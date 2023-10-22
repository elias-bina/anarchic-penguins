


$(BIN)/%.o:%.cpp
	mkdir -p $(dir $@)
	gcc -o $@ -c $^ $(INCLUDES)

$(BIN)/%-make-exe:
	mkdir -p $(dir $@)
	g++ -o $(patsubst %-make-exe,%,$@) $^ $(LIBRARIES)


.PHONY:clean
clean:
	rm -rf $(BIN)
