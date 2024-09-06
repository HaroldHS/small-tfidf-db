CC=gcc

CCFLAGS=-c -g

BUILD_DIR=build
SRC_DIR=src

SOURCE_FILES=$(shell find $(SRC_DIR) -name *.c)
SOURCE_OBJECT_FILES=$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCE_FILES))

.PHONY: build test run clean 

build: $(SOURCE_OBJECT_FILES)
	$(CC) -o $@/small-tfidf-db $(SOURCE_OBJECT_FILES)

$(SOURCE_OBJECT_FILES) : $(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(dir $@) && $(CC) $(CCFLAGS) $(patsubst $(BUILD_DIR)/%.o, $(SRC_DIR)/%.c, $@) -o $@

test:
	./build/small-tfidf-db test

run:
	./build/small-tfidf-db

clean:
	rm -rf ./build/*
