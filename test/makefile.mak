# Example Makefile for compiling C programs

# Variables
CC = gcc
CFLAGS = -Wall -g

# Source files
SRCS = c.c
OBJS = $(SRCS:.c=.o)

# Default target
all: program

# Link
program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) program

# Phony targets
.PHONY: all clean
