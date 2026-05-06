#!/bin/bash

# Configuration
OUTPUT="ts_exec"
CC=gcc
# Includes current directory and the student/Inc folder
CFLAGS="-I. -Istudent/Inc -Wall"
# Lists all source files in their respective directories
SRCS="main.c student/src/menu.c student/src/student.c"

echo "--- Starting build for project TS ---"

# 1. Check if gcc is installed
if ! command -v $CC &> /dev/null
then
    echo "Error: $CC (compiler) not found. Please install build-essential."
    exit 1
fi

# 2. Run the compilation
$CC $CFLAGS $SRCS -o $OUTPUT

# 3. Verify results
if [ $? -eq 0 ]; then
    echo "Build successful! Created: $OUTPUT"
    chmod +x $OUTPUT
else
    echo "Build failed. Check the errors above."
    exit 1
fi

