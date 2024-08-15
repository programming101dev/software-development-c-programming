#!/usr/bin/env sh

# Parse the command line arguments using basic getopt
USAGE="Usage: $0 -c <compiler> [-s <start_at>]"

ARGS=$(getopt c:s: "$@")
if [ $? -ne 0 ]; then
    echo "$USAGE"
    exit 1
fi

set -- $ARGS

COMPILER=""
START_AT=""

while [ "$#" -gt 0 ]; do
    case "$1" in
        -c)
            COMPILER="$2"
            shift 2
            ;;
        -s)
            START_AT="$2"
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

# Loop over directories that start with a number, starting from start_at if provided
for dir in [0-9][0-9]-*/; do
    # Skip specific directories
    case "$dir" in
        "02-hello-world/" | "06-make/")
            echo "Skipping directory: $dir"
            continue
            ;;
    esac

    # If start_at is provided, skip directories before start_at
    if [ -n "$START_AT" ]; then
        dir_num=${dir%%-*}
        if [ "$dir_num" -lt "$START_AT" ]; then
            continue
        fi
    fi

    if [ -d "$dir" ]; then
        pushd "$dir" > /dev/null || exit 1

        # Check for any Makefile in the directory
        if ls Makefile* >/dev/null 2>&1; then
            for makefile in Makefile*; do
                make -f "$makefile" CC="$COMPILER" all || { echo "Error with $makefile in directory: $dir"; result=1; break 2; }
                make -f "$makefile" clean || { echo "Error during clean with $makefile in directory: $dir"; result=1; break 2; }
            done
        else
            echo "No Makefiles found in directory: $dir"
        fi

        popd > /dev/null || exit 1
    fi
done

exit ${result:-0}
