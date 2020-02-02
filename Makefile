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
MCU = ATmega328P
#
# exclude files and directories from compilation (space separated), e.g.
# EXCLUDE = dontcompile.c noincludedir/ignoreme.h noincludedir/ignoreme.c
EXCLUDE = .git dontcompile.c noincludedir/ignoreme.h noincludedir/ignoreme.c
#
# (uncommonly modified settings)
BUILD_DIR = build_$(PROJECT_TITLE)
BINARY = $(BUILD_DIR)/$(PROJECT_TITLE).elf

# --------------------
# C compiler settings
#
CC = avr-gcc
CC_STD = gnu11
CC_PREPROCESS_FLAG = -E
CC_COMPILE_FLAG = -S
CC_ASSEMBLER = avr-as
CC_LINKER = avr-ld
CC_DEBUGGER = avr-gdb
CWARN = -Wall -Wextra -Wpedantic
CFLAGS = -MM $(CWARN)

# --------------------
# Programmer settings
#
FLASH_TOOL = avrdude
PROGRAMMER = arduino
PROGRAMMER_BAUD = 115200
PROGRAMMER_DEVICE = /dev/ttyACM0
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
build_dir_structure := $(patsubst %,$(BUILD_DIR)/%,$(dir_structure))
#
# generate file build lists
c_headers := $(shell find . -type f -iname "*.h" -printf "%P\n")
c_sources := $(shell find . -type f -iname "*.c" -printf "%P\n")
#
# prune excluded files from lists
c_headers := $(filter-out $(EXCLUDE),$(c_headers))
c_sources := $(filter-out $(EXCLUDE),$(c_sources))
#
# precompile


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
.PHONY: link
link: assemble
#
#
.PHONY: assemble
assemble: compile
#
#
.PHONY: compile
compile: preprocess
#
#
.PHONY: preprocess
preprocess: build_dir
	$(CC) $(CC_PREPROCESS_FLAG) 
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

