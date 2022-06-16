# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g3
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o entry.o record.o node.o node_block.o
	$(CC) $(CFLAGS) -o main main.o entry.o record.o node.o node_block.o
 
# The main.o target can be written more simply
 
main.o: main.cpp DataBaseObjects/entry.h DataBaseObjects/record.h BPlusTree/node_block.h
	$(CC) $(CFLAGS) -c main.cpp

entry.o: DataBaseObjects/entry.cpp DataBaseObjects/entry.h
	$(CC) $(CFLAGS) -c DataBaseObjects/entry.cpp

record.o: DataBaseObjects/record.cpp DataBaseObjects/record.h
	$(CC) $(CFLAGS) -c DataBaseObjects/record.cpp

node.o: BPlusTree/node.cpp BPlusTree/node.h 
	$(CC) $(CFLAGS) -c BPlusTree/node.cpp

node_block.o: BPlusTree/node_block.cpp BPlusTree/node_block.h BPlusTree/node.h DataBaseObjects/entry.h DataBaseObjects/record.h
	$(CC) $(CFLAGS) -c BPlusTree/node_block.cpp


