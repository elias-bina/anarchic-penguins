include src/entities/project.mk
include src/environnement/project.mk
include src/input/project.mk

ANARCHIC_PENGUINS-EXE-NAME = $(BIN)/anarchic-penguins-make-exe



ANARCHIC_PENGUINS-EXE-SRCS = src/main.cpp 					\
								 						 src/game.cpp 					\
								 						 ${ENTITIES-SRCS} 			\
								 						 ${ENVIRONNEMENT-SRCS}  \
								 						 ${INPUT-SRCS}


ANARCHIC_PENGUINS-EXE-OBJS:=$(ANARCHIC_PENGUINS-EXE-SRCS:%.cpp=$(BIN)/%.o)
${ANARCHIC_PENGUINS-EXE-NAME}: ${ANARCHIC_PENGUINS-EXE-OBJS}

TARGETS+=${ANARCHIC_PENGUINS-EXE-NAME}
