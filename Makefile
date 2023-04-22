
.PHONY:all,true-all

all:true-all

BIN?=bin
TARGETS=
INCLUDES=-I./include


include src/project.mk
include base.mk

true-all: ${TARGETS}