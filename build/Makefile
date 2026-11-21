GXX = gcc
ASM = nasm

ASM_FLAGS = -f elf64

SRCc = $(wildcard ../src/*.c)

MainAsrc = ../src/AssemblyFiles/main.asm
MainCsrc = ../src/main/main.c

MainAobj = ./mainA.o
MainCobj = ./mainC.o

TARGET = app

all: $(TARGET)

clean:
	rm -f $(TARGET) $(MainCobj) $(MainAobj)

$(TARGET): clean $(MainCobj) $(MainAobj)
	$(GXX) $(MainCobj) $(MainAobj) -o $(TARGET)

$(MainCobj):
	$(GXX) -c $(MainCsrc) -o $(MainCobj)

$(MainAobj):
	$(ASM) $(ASM_FLAGS) $(MainAsrc) -o $(MainAobj)
