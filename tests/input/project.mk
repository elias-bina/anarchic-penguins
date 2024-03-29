include src/input/project.mk

TEST_INPUT_EXE=$(BIN)/tests-input-make-exe

TEST_INPUT_SRCS:=							\
	$(INPUT-SRCS)							\
	tests/input/action-list-tests.cpp		\
	tests/input/input-controller-tests.cpp	\
	tests/input/input-manager-tests.cpp		\
	tests/input/tests-input.cpp



TEST_INPUT_OBJ:= $(TEST_INPUT_SRCS:%.cpp=$(BIN)/%.o)

$(TEST_INPUT_EXE): $(TEST_INPUT_OBJ)


TARGETS+=$(TEST_INPUT_EXE)
