CC = gcc
CFLAGS = -Wall

# List of source files
SOURCES = piece.c board.c main.c

# List of header files
HEADERS = piece.h board.h

# Name of the output executable
TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
