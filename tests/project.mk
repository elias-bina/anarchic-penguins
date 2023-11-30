include tests/input/project.mk

# TEST_INPUT_EXE=$(BIN)/tests-input-make-exe
# # TEST_STRING_MANIPULATION_EXE=$(BIN)/tests-string-manipulation-make-exe
# # TEST_UI_UTILS_EXE=$(BIN)/tests-ui-utils-make-exe

# TEST_INPUT_SRCS:=	\
# 	$(INPUT-SRCS)	\
# 	tests/tests_input.cpp

# # TEST_STRING_MANIPULATION_SRCS:= \
# # 	$(SOCKETS_SRCS) 	\
# # 	$(TRANSCODING_SRCS) \
# # 	$(UI_SRCS) 			\
# # 	$(UTILS_SRCS)		\
# # 	$(MPACK_SRCS) \
# # 	tests/tests_string_manipulation.c

# # TEST_UI_UTILS_SRCS:= \
# # 	$(SOCKETS_SRCS) 	\
# # 	$(TRANSCODING_SRCS) \
# # 	$(UI_SRCS) 			\
# # 	$(UTILS_SRCS)		\
# # 	$(MPACK_SRCS) \
# # 	tests/tests_ui_utils.c


# TEST_INPUT_OBJ:= $(TEST_INPUT_SRCS:%.cpp=$(BIN)/%.o)
# # TEST_STRING_MANIPULATION_OBJ:= $(TEST_STRING_MANIPULATION_SRCS:%.cpp=$(BIN)/%.o)
# # TEST_UI_UTILS_OBJ:= $(TEST_UI_UTILS_SRCS:%.cpp=$(BIN)/%.o)

# $(TEST_INPUT_EXE): $(TEST_INPUT_OBJ)
# # $(TEST_STRING_MANIPULATION_EXE): $(TEST_STRING_MANIPULATION_OBJ)
# # $(TEST_UI_UTILS_EXE): $(TEST_UI_UTILS_OBJ)


# TARGETS+=$(TEST_INPUT_EXE)
# # TARGETS+=$(TEST_STRING_MANIPULATION_EXE)
# # TARGETS+=$(TEST_UI_UTILS_EXE)
