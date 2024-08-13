#!/bin/bash

./my_program "$@"
exit_code=$?

if [ $exit_code -eq 0 ]; then
    echo "Program executed successfully."
elif [ $exit_code -eq 2 ]; then
    echo "Invalid input provided."
elif [ $exit_code -eq 3 ]; then
    echo "File not found."
else
    echo "An unknown error occurred. Exit code: $exit_code"
fi

