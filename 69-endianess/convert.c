#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
    // Example for htonl and ntohl
    unsigned int host_long = 0x12345678;
    unsigned int network_long = htonl(host_long);
    unsigned int converted_back_long = ntohl(network_long);

    printf("Host long: 0x%x\n", host_long);
    printf("Network long: 0x%x\n", network_long);
    printf("Converted back long: 0x%x\n", converted_back_long);

    // Example for htons and ntohs
    unsigned short host_short = 0x1234;
    unsigned short network_short = htons(host_short);
    unsigned short converted_back_short = ntohs(network_short);

    printf("Host short: 0x%x\n", host_short);
    printf("Network short: 0x%x\n", network_short);
    printf("Converted back short: 0x%x\n", converted_back_short);

    return 0;
}
