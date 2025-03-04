# Variables
CC = gcc
CFLAGS = -Iinclude -Wall -std=c99
LDFLAGS = -lm
LIB = lib/libztransform.a
OBJ = build/ztransform.o
EXAMPLE = build/main

# Reglas
all: $(LIB) $(EXAMPLE)

# Crear la biblioteca estática
$(LIB): $(OBJ)
	ar rcs $@ $^

# Compilar el archivo objeto
$(OBJ): src/ztransform.c include/ztransform.h
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar el ejemplo
$(EXAMPLE): examples/main.c $(LIB)
	@mkdir -p build
	$(CC) $(CFLAGS) $< -Llib -lztransform $(LDFLAGS) -o $@

# Limpiar archivos generados
clean:
	rm -rf build/* lib/*

# Ejecutar el ejemplo
run: $(EXAMPLE)
	./$(EXAMPLE)

.PHONY: all clean run