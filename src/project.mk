include src/entities/project.mk
include src/environnement/project.mk

HELLO-EXE-NAME = $(BIN)/hello-make-exe



HELLO-EXE-SRCS = src/main.cpp 					\
								 ${ENTITIES-SRCS} 			\
								 ${ENVIRONNEMENT-SRCS}


HELLO-EXE-OBJS:=$(HELLO-EXE-SRCS:%.cpp=$(BIN)/%.o)
${HELLO-EXE-NAME}: ${HELLO-EXE-OBJS}

TARGETS+=${HELLO-EXE-NAME}