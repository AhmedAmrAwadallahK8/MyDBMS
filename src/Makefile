# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o entry.o int_entry.o double_entry.o char_entry.o string_entry.o
	$(CC) $(CFLAGS) -o main main.o entry.o int_entry.o double_entry.o char_entry.o string_entry.o
 
# The main.o target can be written more simply
 
main.o: main.cpp DataBaseObjects/int_entry.h DataBaseObjects/double_entry.h DataBaseObjects/char_entry.h DataBaseObjects/string_entry.h
	$(CC) $(CFLAGS) -c main.cpp
 
entry.o: DataBaseObjects/entry.cpp DataBaseObjects/entry.h
	$(CC) $(CFLAGS) -c DataBaseObjects/entry.cpp

int_entry.o: DataBaseObjects/int_entry.cpp DataBaseObjects/int_entry.h DataBaseObjects/entry.h
	$(CC) $(CFLAGS) -c DataBaseObjects/int_entry.cpp

double_entry.o: DataBaseObjects/double_entry.cpp DataBaseObjects/double_entry.h DataBaseObjects/entry.h
	$(CC) $(CFLAGS) -c DataBaseObjects/double_entry.cpp

char_entry.o: DataBaseObjects/char_entry.cpp DataBaseObjects/char_entry.h DataBaseObjects/entry.h
	$(CC) $(CFLAGS) -c DataBaseObjects/char_entry.cpp

string_entry.o: DataBaseObjects/string_entry.cpp DataBaseObjects/string_entry.h DataBaseObjects/entry.h
	$(CC) $(CFLAGS) -c DataBaseObjects/string_entry.cpp