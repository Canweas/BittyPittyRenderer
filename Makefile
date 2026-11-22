PRJ_DIR = ./BittyPittyRenderer/

ASM = nasm
ASM_FLAGS = -f elf64

GXX = gcc
C_FLAGS = -no-pie

TARGET = app

ASM_SRC = ./BittyPittyRenderer/src/implementations/stringLib.asm
SRC = $(wildcard ./BittyPittyRenderer/src/*.c) $(wildcard ./BittyPittyRenderer/src/implementations/*.c)

OBJS = ./objs/stringLib.o

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

rundel: clean all
	./$(TARGET)
	rm -f $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(GXX) $(C_FLAGS) $(OBJS) $(SRC) -o $(TARGET)

$(OBJS):
	$(ASM) $(ASM_FLAGS) $(ASM_SRC) -o $(OBJS)

.PHONY: all clean run
