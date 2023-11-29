


$(BIN)/%.o:%.cpp
	mkdir -p $(dir $@)
	gcc -o $@ -c $^ $(INCLUDES) $(CFLAGS)

$(BIN)/%-make-exe:
	mkdir -p $(dir $@)
	g++ -o $(patsubst %-make-exe,%,$@) $^ $(LDFLAGS)


.PHONY:clean
clean:
	rm -rf $(BIN)
