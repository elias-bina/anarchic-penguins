
.PHONY:all,true-all

all:true-all

BIN?=bin
TARGETS=
INCLUDES=-I./include
LIBRARIES=-lsfml-graphics -lsfml-window -lsfml-system


include src/project.mk
include base.mk

true-all: ${TARGETS}
