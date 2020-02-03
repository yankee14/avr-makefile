# Project settings
# (commonly modified settings)
# 
# Print Makefile debug info?
DEBUG = true
#
# Project name, determines build directory and binary name
PROJECT_TITLE = project
#
# Optimization levels 0, 1, 2, 3, g, s, or fast
OPTIMIZATION_LEVEL = s
#
# Microcontroller to be programmed (run avrdude -p ?)
MCU = atmega328p
#
# Microcontroller clock speed
F_CPU = 16E6
#
# exclude files and directories from compilation (space separated), e.g.
# EXCLUDE = dontcompile.c noincludedir/ignoreme.h noincludedir/ignoreme.c
EXCLUDE = .git include/subdir/test2.c
#
# Where to place build artifacts
BUILD_DIR = build_$(PROJECT_TITLE)
# Where to place binary
BINARY = $(BUILD_DIR)/$(PROJECT_TITLE).elf

# --------------------
# C compiler settings
#
CC = avr-gcc
CC_STD = gnu11
CC_PREPROCESS_FLAG = -E
CC_COMPILE_FLAG = -S
C_ASSEMBLER = avr-as
C_LINKER = avr-ld
C_DEBUGGER = avr-gdb
CWARN = -Wall -Wextra -Wpedantic
CFLAGS = -g -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(CWARN)
C_ASSEMBLER_FLAGS = -g -mmcu=$(MCU)

# --------------------
# Programmer settings
#
FLASH_TOOL = avrdude
PROGRAMMER = arduino
PROGRAMMER_BAUD = 115200
PROGRAMMER_DEVICE = /dev/ttyACM0
PROGRAMMER_WRITE_PROGRAM = -U flash:w:$(BINARY):e
PROGRAMMER_VERIFY_PROGRAM = -U flash:v$(BINARY):e
PROGRAMMER_FLAGS = 

# --------------------
# OS dependent settings
#
MKDIR = mkdir
MKDIR_FLAGS = --parents --verbose --
RM = rm
RM_FLAGS = --recursive --verbose --force --
#
# generate build directory structure
dir_structure := $(shell find . -type d ! -path "." -printf '%P\n' | grep -v "$(BUILD_DIR)" | grep -v ".git")
dir_structure := $(filter-out $(EXCLUDE),$(dir_structure))
build_dir_structure := $(BUILD_DIR) $(patsubst %,$(BUILD_DIR)/%,$(dir_structure))
#
# generate file build lists
c_headers := $(shell find . -type f -iname "*.h" -printf "%P\n")
c_sources := $(shell find . -type f -iname "*.c" -printf "%P\n")
#
# prune excluded files from lists
c_headers := $(filter-out $(EXCLUDE),$(c_headers))
c_sources := $(filter-out $(EXCLUDE),$(c_sources))
#
c_preprocess := $(patsubst %,$(BUILD_DIR)/%,$(c_sources:.c=.i))
c_compile := $(patsubst %,$(BUILD_DIR)/%,$(c_sources:.c=.s))
c_assemble := $(patsubst %, $(BUILD_DIR)/%, $(c_sources:.c=.o))

# --------------------
# Makefile debug
ifeq ($(strip $(DEBUG)),true)
    $(info PROJECT_TITLE:$(PROJECT_TITLE)--)
    $(info OPTIMIZATION_LEVEL:$(OPTIMIZATION_LEVEL)--)
    $(info EXCLUDE:$(EXCLUDE)--)
    $(info BUILD_DIR:$(BUILD_DIR)--)
    $(info BINARY:$(BINARY)--)
    $(info CC:$(CC)--)
    $(info CWARN:$(CWARN)--)
    $(info CXX:$(CXX)--)
    $(info MKDIR:$(MKDIR)--)
    $(info MKDIR_FLAGS:$(MKDIR_FLAGS)--)
    $(info RM:$(RM)--)
    $(info RM_FLAGS:$(RM_FLAGS)--)
    $(info dir_structure:$(dir_structure)--)
    $(info build_dir_structure:$(build_dir_structure)--)
    $(info c_headers:$(c_headers)--)
    $(info c_sources:$(c_sources)--)
	$(info c_preprocess:$(c_preprocess)--)
	$(info c_compile:$(c_compile)--)
	$(info c_assemble:$(c_assemble)--)
endif

# Build targets
#
.PHONY: all
all: link
#
#
.PHONY: debug
debug:
#
#
.PHONY: verify
verify:
#
#
.PHONY: flash
flash:
#
#
.PHONY: binary
binary: link
#
#
$(BINARY): 
	$(C_LINKER) -m avr5 -o $@ $(c_assemble) -L/usr/lib/avr/lib -lc
#
#
.PHONY: link
link: assemble $(BINARY)
#
#
$(c_assemble): %.o: %.s
	$(C_ASSEMBLER) $(C_ASSEMBLER_FLAGS) -o $@ $<
#
#
.PHONY: assemble
assemble: compile $(c_assemble)
#
#
$(c_compile): %.s: %.i
	$(CC) $(CC_COMPILE_FLAG) $(CFLAGS) -o $@ $<
#
#
.PHONY: compile
compile: preprocess $(c_compile)
#
#
$(c_preprocess): $(BUILD_DIR)/%.i: %.c
	$(CC) $(CC_PREPROCESS_FLAG) $(CFLAGS) -o $@ $<
#
#
.PHONY: preprocess
preprocess: build_dir $(c_preprocess)
#
#
.PHONY: build_dir
build_dir:
	$(MKDIR) $(MKDIR_FLAGS) $(build_dir_structure)
#
#
.PHONY: clean
clean:
	$(RM) $(RM_FLAGS) $(BUILD_DIR)
#
#
.PHONY: help
help:

