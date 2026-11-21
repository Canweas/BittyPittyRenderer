ASM = nasm
ASM_FLAGS = -f elf64

GXX = gcc
C_FLAGS =

MAIN_C_SRC = ./src/main.c
MAIN_ASM_SRC = ./asmSrc/main.asm

TARGET = app

all: $(TARGET)

clean:
	rm -f $(TARGET) ./objs/a.o ./objs/c.o

run: $(TARGET)
	./$(TARGET)

$(TARGET): ./objs/a.o ./objs/c.o
	$(GXX) ./objs/a.o ./objs/c.o -o $(TARGET)

./objs/a.o:
	$(ASM) $(ASM_FLAGS) $(MAIN_ASM_SRC) -o ./objs/a.o

./objs/c.o:
	$(GXX) -c $(MAIN_C_SRC) -o ./objs/c.o $(C_FLAGS)

.PHONY: all clean run
