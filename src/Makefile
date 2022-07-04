# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g3
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o entry.o record.o test_b_plus_tree.o table.o test_table.o
	$(CC) $(CFLAGS) -o main main.o entry.o record.o test_b_plus_tree.o table.o test_table.o
# node_block.o b_plus_tree.o test_b_plus_tree.o
# The main.o target can be written more simply
 
main.o: main.cpp Tests/test_table.h 
	$(CC) $(CFLAGS) -c main.cpp

entry.o: DataBaseObjects/entry.cpp 
	$(CC) $(CFLAGS) -c DataBaseObjects/entry.cpp

record.o: DataBaseObjects/record.cpp
	$(CC) $(CFLAGS) -c DataBaseObjects/record.cpp

table.o: DataBaseObjects/table.cpp
	$(CC) $(CFLAGS) -c DataBaseObjects/table.cpp

#node.o: BPlusTree/node.cpp BPlusTree/node.h 
#	$(CC) $(CFLAGS) -c BPlusTree/node.cpp

#node_block.o: BPlusTree/node_block.cpp BPlusTree/node_block.h BPlusTree/node.h DataBaseObjects/entry.h DataBaseObjects/record.h
#	$(CC) $(CFLAGS) -c BPlusTree/node_block.cpp

#b_plus_tree.o: BPlusTree/b_plus_tree.cpp BPlusTree/b_plus_tree.h BPlusTree/node_block.h DataBaseObjects/entry.h DataBaseObjects/record.h
#	$(CC) $(CFLAGS) -c BPlusTree/b_plus_tree.cpp

test_b_plus_tree.o: Tests/test_b_plus_tree.cpp
	$(CC) $(CFLAGS) -c Tests/test_b_plus_tree.cpp

test_table.o: Tests/test_table.cpp
	$(CC) $(CFLAGS) -c Tests/test_table.cpp