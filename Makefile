# Variables
CC = gcc
CFLAGS = -Iinclude -Wall -std=c99
LDFLAGS = -lm
LIB = lib/libztransform.a
OBJ = build/ztransform.o
EXAMPLE = build/main

# Rules
all: $(LIB) $(EXAMPLE)

# Create the static library
$(LIB): $(OBJ)
	@mkdir -p lib
	ar rcs $@ $^

# Compile the object file
$(OBJ): src/ztransform.c include/ztransform.h
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the example
$(EXAMPLE): examples/main.c $(LIB)
	@mkdir -p build
	$(CC) $(CFLAGS) $< -Llib -lztransform $(LDFLAGS) -o $@

# Clean generated files
clean:
	rm -rf build/* lib/*

# Run the example
run: $(EXAMPLE)
	./$(EXAMPLE)

.PHONY: all clean run