CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude

TARGET = main
TEST_TARGET = test_bigint

SRC = src/main.c src/bigint.c
TEST_SRC = tests/test_bigint.c src/bigint.c


all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)


$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_TARGET)


test: $(TEST_TARGET)
	./$(TEST_TARGET)


clean:
	rm -f $(TARGET) $(TEST_TARGET)