CC = gcc
CFLAGS = -g -Wall

all: build run clean

HEADERS = $(wildcard *.h)
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

build: 
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(OBJECTS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o greedy 

.PHONY: clean 
clean: 	
	@rm -f *.o 
	
	