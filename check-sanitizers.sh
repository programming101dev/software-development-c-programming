#!/usr/bin/env sh

# Usage message
USAGE="Usage: $0 -c <compiler>"

# Parse the command line arguments
ARGS=$(getopt c: "$@")
if [ $? -ne 0 ]; then
    echo "$USAGE"
    exit 1
fi

set -- $ARGS

COMPILER=""

while [ "$#" -gt 0 ]; do
    case "$1" in
        -c)
            COMPILER="$2"
            shift 2
            ;;
        --)
            shift
            break
            ;;
        *)
            echo "$USAGE"
            exit 1
            ;;
    esac
done

if [ -z "$COMPILER" ]; then
    echo "$USAGE"
    exit 1
fi

# List of known sanitizers
SANITIZERS="
-fsanitize=address
-fsanitize=undefined
-fsanitize=leak
-fsanitize=thread
-fsanitize=memory
-fsanitize=cfi
-fsanitize=safe-stack
-fsanitize=address-globals
-fsanitize=address-use-after-scope
-fsanitize=cfi-derived-cast
-fsanitize=cfi-icall
-fsanitize=cfi-unrelated-cast
-fsanitize=dataflow
-fsanitize=hwaddress
-fsanitize=kcfi
-fsanitize=scudo
-fsanitize=shadow-call-stack
-fsanitize=stack
-fsanitize=structleak
-fsanitize=trap
-fsanitize=integer
-fsanitize=bounds
-fsanitize=alignment
-fsanitize=null
-fsanitize=signed-integer-overflow
-fsanitize=float-divide-by-zero
-fsanitize=vptr
-fsanitize=shift
-fsanitize=unsigned-integer-overflow
-fsanitize=nullability-arg
-fsanitize=bounds-strict
-fsanitize=local-bounds
-fsanitize=object-size
-fsanitize=cfi-cast-strict
"

# Check supported sanitizers for the specified compiler
echo "Supported Sanitizers for $COMPILER:"
for sanitizer in $SANITIZERS; do
    if echo "int main(){}" | $COMPILER $sanitizer -x c - -o /dev/null 2>/dev/null; then
        echo "$sanitizer"
    fi
done
