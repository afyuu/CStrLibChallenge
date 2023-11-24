CC = gcc
CFLAGS = -std=c99 -Wall -pedantic
RM = del /Q

.PHONY: all clean

all: string.exe

string.exe: str.o main.o
	$(CC) $(CFLAGS) str.o main.o -o $@

str.o: str.c str.h
	$(CC) $(CFLAGS) -c str.c -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o string.exe
