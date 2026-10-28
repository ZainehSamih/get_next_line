# get_next_line

A C function that reads a file descriptor one line at a time.

## About

This project was developed as part of the 42 Core Curriculum. It focuses on file descriptors, the `read()` function, static variables, and dynamic memory management.

## Features

- Reads one line per function call
- Handles lines across multiple reads
- Supports configurable `BUFFER_SIZE`

## Compilation

Compile the source files with your test program:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o program
```

## Usage

```c
char *line;

line = get_next_line(fd);
```

Call `get_next_line()` repeatedly to read subsequent lines. Free each returned line when it is no longer needed.

## Note

This is an educational implementation. Check the project subject for its exact behavior and limitations.
