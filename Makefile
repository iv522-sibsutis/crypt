SOURCE_DIRS = thirdparty src
SRC = ./src
TEST = ./test
OBJ = ./obj
BIN = ./bin
BIN_SEARCH = $(addsuffix /*.c, src)
TEST_SEARCH = $(addsuffix /*.c, test)
OBJ_SRC = $(patsubst src/%.c, obj/src/%.o, $(wildcard $(BIN_SEARCH)))
OBJ_TEST = $(patsubst test/%.c, obj/test/%.o, $(wildcard $(TEST_SEARCH))) $(filter-out obj/src/main.o, $(OBJ_SRC))

DEPENDS = $(OBJ_SRC:.o=.d) $(OBJ_TEST:.o=.d)

.PHONY: make
make: dirs
	@$(MAKE) all
	
.PHONY: dirs
dirs:
	@mkdir -p $(dir $(OBJ_SRC))
	@mkdir -p $(dir $(OBJ_TEST))
	@mkdir -p $(BIN)

.PHONY: clean
clean:
	rm bin
	rm obj
	
.PHONY: all
all: $(BIN)/crypt $(BIN)/crypt_test

$(BIN)/crypt: $(OBJ_SRC)
	gcc $^ -o $@ `pkg-config --cflags --libs gtk+-3.0`

$(BIN)/crypt_test: $(OBJ_TEST)
	gcc $^ -o $@ `pkg-config --cflags --libs gtk+-3.0`

-include $(DEPENDS)

$(OBJ)/src/%.o: $(SRC)/%.c
	gcc -c -Wall -g -O0 -MP -MMD $(addprefix -I ,$(SOURCE_DIRS)) $< -o $@ `pkg-config --cflags --libs gtk+-3.0`

$(OBJ)/test/%.o: $(TEST)/%.c
	gcc -c -Wall -g -O0 -MP -MMD $(addprefix -I ,$(SOURCE_DIRS)) $< -o $@ `pkg-config --cflags --libs gtk+-3.0` 
