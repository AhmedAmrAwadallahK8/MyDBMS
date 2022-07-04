#include <iostream>
#include <string>
#include <vector>

#include "test_table.h"
#include "../DataBaseObjects/table.h"
#include "../DataBaseObjects/entry.h"
#include "../DataBaseObjects/record.h"
void Test_Table::test(){
    test_type_insert();

    std::cout << "Test Complete\n";
}
void Test_Table::test_type_insert(){
    std::vector<std::string> entries1{"20", "Hello"};
    std::vector<int> attr1{Entry::INT, Entry::STRING};
    std::vector<std::string> attr_names{"IntAttr", "StrAttr"};
    Table int_table("Random Numbers", attr_names, attr1);
    Record *pk_int1 = new Record(attr1, entries1);

    std::vector<std::string> entries2{"70", "Hello"};
    Record *pk_int2 = new Record(attr1, entries2);

    std::vector<std::string> entries3{"30", "Hello"};
    Record *pk_int3 = new Record(attr1, entries3);

    std::vector<std::string> entries4{"5", "Hello"};
    Record *pk_int4 = new Record(attr1, entries4);

    std::vector<std::string> entries5{"12", "Hello"};
    Record *pk_int5 = new Record(attr1, entries5);

    std::vector<std::string> entries6{"16", "Hello"};
    Record *pk_int6 = new Record(attr1, entries6);

    std::vector<std::string> entries7{"50", "Hello"};
    Record *pk_int7 = new Record(attr1, entries7);

    std::vector<std::string> entries8{"80", "Hello"};
    Record *pk_int8 = new Record(attr1, entries8);

    std::vector<std::string> entries9{"55", "Hello"};
    Record *pk_int9 = new Record(attr1, entries9);

    std::vector<std::string> entries10{"60", "Hello"};
    Record *pk_int10 = new Record(attr1, entries10);

    std::vector<std::string> entries11{"13", "Hello"};
    Record *pk_int11 = new Record(attr1, entries11);

    std::vector<std::string> entries12{"14", "Hello"};
    Record *pk_int12 = new Record(attr1, entries12);

    std::vector<std::string> entries13{"21", "Hello"};
    Record *pk_int13 = new Record(attr1, entries13);

    std::vector<std::string> entries14{"22", "Hello"};
    Record *pk_int14 = new Record(attr1, entries14);
    
    int_table.insert_record(pk_int1);
    int_table.insert_record(pk_int2);
    int_table.insert_record(pk_int3);
    int_table.insert_record(pk_int4);
    int_table.insert_record(pk_int5);
    int_table.insert_record(pk_int6);
    int_table.insert_record(pk_int7);
    int_table.insert_record(pk_int8);
    int_table.insert_record(pk_int9);
    int_table.insert_record(pk_int10);
    int_table.insert_record(pk_int11);
    int_table.insert_record(pk_int12);
    int_table.insert_record(pk_int13);
    int_table.insert_record(pk_int14);
    int_table.print_table();
}