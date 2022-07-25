# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g3 -static
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o entry.o record.o test_b_plus_tree.o table.o test_table.o database.o test_database.o lexer.o parser.o test_parser.o dbms.o
	$(CC) $(CFLAGS) -o mydbms main.o entry.o record.o test_b_plus_tree.o table.o test_table.o database.o test_database.o lexer.o parser.o test_parser.o dbms.o
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

database.o: DataBaseObjects/database.cpp
	$(CC) $(CFLAGS) -c DataBaseObjects/database.cpp

lexer.o: QueryLanguage/lexer.cpp
	$(CC) $(CFLAGS) -c QueryLanguage/lexer.cpp

parser.o: QueryLanguage/parser.cpp
	$(CC) $(CFLAGS) -c QueryLanguage/parser.cpp

dbms.o: DBMSObjects/dbms.cpp
	$(CC) $(CFLAGS) -c DBMSObjects/dbms.cpp

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

test_database.o: Tests/test_database.cpp
	$(CC) $(CFLAGS) -c Tests/test_database.cpp

test_parser.o: Tests/test_parser.cpp
	$(CC) $(CFLAGS) -c Tests/test_parser.cpp