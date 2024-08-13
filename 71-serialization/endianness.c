#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h> // For htonl and ntohl

struct Example {
    int8_t a;
    int32_t b;
    int8_t c;
};

void serialize(const struct Example *example, uint8_t *buffer) {
    memcpy(buffer, &example->a, sizeof(example->a));
    int32_t b_network = htonl(example->b); // Convert to network byte order
    memcpy(buffer + sizeof(example->a), &b_network, sizeof(b_network));
    memcpy(buffer + sizeof(example->a) + sizeof(b_network), &example->c, sizeof(example->c));
}

void deserialize(const uint8_t *buffer, struct Example *example) {
    memcpy(&example->a, buffer, sizeof(example->a));
    int32_t b_network;
    memcpy(&b_network, buffer + sizeof(example->a), sizeof(b_network));
    example->b = ntohl(b_network); // Convert from network byte order
    memcpy(&example->c, buffer + sizeof(example->a) + sizeof(b_network), sizeof(example->c));
}

int main(void) {
    struct Example original = {'A', 12345, 'Z'};
    uint8_t buffer[sizeof(original)];

    serialize(&original, buffer);

    struct Example copy;
    deserialize(buffer, &copy);

    printf("Original: a=%c, b=%d, c=%c\n", original.a, original.b, original.c);
    printf("Copy: a=%c, b=%d, c=%c\n", copy.a, copy.b, copy.c);

    return 0;
}
