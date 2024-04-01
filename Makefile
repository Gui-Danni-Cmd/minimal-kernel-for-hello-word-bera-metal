SRC_DIR = src
BUILD_DIR = build

OUTPUT_NAME = kernel

ASM_SOURCE = $(SRC_DIR)/kernel.asm
C_SOURCE = $(SRC_DIR)/kernel.c
run: build
	qemu-system-i386 -kernel $(BUILD_DIR)/$(OUTPUT_NAME)

create_build_dir:
	mkdir -p $(BUILD_DIR)

build: create_build_dir
	nasm -f elf32 $(ASM_SOURCE) -o $(BUILD_DIR)/kernasm.o
	gcc -m32 -c $(C_SOURCE) -o $(BUILD_DIR)/kernc.o
	ld -m elf_i386 -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/$(OUTPUT_NAME) $(BUILD_DIR)/kernasm.o $(BUILD_DIR)/kernc.o


clean:
	rm -rf $(BUILD_DIR)/*
