
.PHONY:all,true-all

all:true-all

BIN?=bin
TARGETS=
CFLAGS+=-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch -Wlogical-op -Wmissing-declarations -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpointer-arith -Wredundant-decls -Wstack-protector -Wstrict-null-sentinel -Wundef -Wwrite-strings
CFLAGS+=-O0 -g3
CFLAGS+=-std=c++17
INCLUDES=-I./include
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -pthread
LDFLAGS+=-fsanitize=undefined,address
CFLAGS+=-fsanitize=undefined,address

include src/project.mk
include base.mk

true-all: ${TARGETS}
