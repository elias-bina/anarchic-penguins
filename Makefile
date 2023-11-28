
.PHONY:all,true-all

all:true-all

BIN?=bin
TARGETS=
CFLAGS=-O0 -g3
CFLAGS+=-std=c++17
INCLUDES=-I./include
LIBRARIES=-lsfml-graphics -lsfml-window -lsfml-system -pthread


include src/project.mk
include base.mk

true-all: ${TARGETS}
