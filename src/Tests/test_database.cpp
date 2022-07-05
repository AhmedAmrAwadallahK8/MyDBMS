#include <iostream>
#include <string>

#include "test_database.h"
#include "..\DataBaseObjects\record.h"
#include "..\DataBaseObjects\database.h"
#include "..\DataBaseObjects\entry.h"

void Test_Database::test(){
    test_table_print();


    std::cout << "Finished all tests\n";
}

void Test_Database::test_table_print(){
    Database db("Company");
    db.create_table("Employee", {"Id", "Name"}, {Entry::INT, Entry::STRING});
    db.create_table("CustomerMessage", {"Name", "Message"}, {Entry::STRING, Entry::STRING});
    
    std::vector<std::string> entries1{"Ahmed2", "Hello"};
    std::vector<int> attr1{Entry::STRING, Entry::STRING};
    Record *pk1 = new Record(attr1, entries1);

    std::vector<std::string> entries2{"Bob", "Hello"};
    Record *pk2 = new Record(attr1, entries2);

    std::vector<std::string> entries3{"Vanice", "Hello"};
    Record *pk3 = new Record(attr1, entries3);

    std::vector<std::string> entries4{"Janice", "Hello"};
    Record *pk4 = new Record(attr1, entries4);

    std::vector<std::string> entries5{"Vince", "Hello"};
    Record *pk5 = new Record(attr1, entries5);

    std::vector<std::string> entries6{"Zach", "Hello"};
    Record *pk6 = new Record(attr1, entries6);

    std::vector<std::string> entries7{"Mizzie", "Hello"};
    Record *pk7 = new Record(attr1, entries7);

    std::vector<std::string> entries8{"Eric", "Hello"};
    Record *pk8 = new Record(attr1, entries8);

    std::vector<std::string> entries9{"David", "Hello"};
    Record *pk9 = new Record(attr1, entries9);

    std::vector<std::string> entries10{"Nickan", "Hello"};
    Record *pk10 = new Record(attr1, entries10);

    std::vector<std::string> entries11{"Alex", "Hello"};
    Record *pk11 = new Record(attr1, entries11);

    std::vector<std::string> entries12{"Shiri", "Hello"};
    Record *pk12 = new Record(attr1, entries12);

    std::vector<std::string> entries13{"Anon", "Hello"};
    Record *pk13 = new Record(attr1, entries13);

    std::vector<std::string> entries14{"Wade", "Hello"};
    Record *pk14 = new Record(attr1, entries14);

    db.insert_into_table("CustomerMessage", pk1);
    db.insert_into_table("CustomerMessage", pk2);
    db.insert_into_table("CustomerMessage", pk3);
    db.insert_into_table("CustomerMessage", pk4);
    db.insert_into_table("CustomerMessage", pk5);
    db.insert_into_table("CustomerMessage", pk6);
    db.insert_into_table("CustomerMessage", pk7);
    db.insert_into_table("CustomerMessage", pk8);
    db.insert_into_table("CustomerMessage", pk9);
    db.insert_into_table("CustomerMessage", pk10);
    db.insert_into_table("CustomerMessage", pk11);
    db.insert_into_table("CustomerMessage", pk12);
    db.insert_into_table("CustomerMessage", pk13);
    db.insert_into_table("CustomerMessage", pk14);

    std::vector<std::string> int_entries1{"20", "Hello"};
    std::vector<int> attr2{Entry::INT, Entry::STRING};
    Record *pk_int1 = new Record(attr2, int_entries1);

    std::vector<std::string> int_entries2{"70", "Hello"};
    Record *pk_int2 = new Record(attr2, int_entries2);

    std::vector<std::string> int_entries3{"30", "Hello"};
    Record *pk_int3 = new Record(attr2, int_entries3);

    std::vector<std::string> int_entries4{"5", "Hello"};
    Record *pk_int4 = new Record(attr2, int_entries4);

    std::vector<std::string> int_entries5{"12", "Hello"};
    Record *pk_int5 = new Record(attr2, int_entries5);

    std::vector<std::string> int_entries6{"16", "Hello"};
    Record *pk_int6 = new Record(attr2, int_entries6);

    std::vector<std::string> int_entries7{"50", "Hello"};
    Record *pk_int7 = new Record(attr2, int_entries7);

    std::vector<std::string> int_entries8{"80", "Hello"};
    Record *pk_int8 = new Record(attr2, int_entries8);

    std::vector<std::string> int_entries9{"55", "Hello"};
    Record *pk_int9 = new Record(attr2, int_entries9);

    std::vector<std::string> int_entries10{"60", "Hello"};
    Record *pk_int10 = new Record(attr2, int_entries10);

    std::vector<std::string> int_entries11{"13", "Hello"};
    Record *pk_int11 = new Record(attr2, int_entries11);

    std::vector<std::string> int_entries12{"14", "Hello"};
    Record *pk_int12 = new Record(attr2, int_entries12);

    std::vector<std::string> int_entries13{"21", "Hello"};
    Record *pk_int13 = new Record(attr2, int_entries13);

    std::vector<std::string> int_entries14{"22", "Hello"};
    Record *pk_int14 = new Record(attr2, int_entries14);

    db.insert_into_table("Employee", pk_int1);
    db.insert_into_table("Employee", pk_int2);
    db.insert_into_table("Employee", pk_int3);
    db.insert_into_table("Employee", pk_int4);
    db.insert_into_table("Employee", pk_int5);
    db.insert_into_table("Employee", pk_int6);
    db.insert_into_table("Employee", pk_int7);
    db.insert_into_table("Employee", pk_int8);
    db.insert_into_table("Employee", pk_int9);
    db.insert_into_table("Employee", pk_int10);
    db.insert_into_table("Employee", pk_int11);
    db.insert_into_table("Employee", pk_int12);
    db.insert_into_table("Employee", pk_int13);
    db.insert_into_table("Employee", pk_int14);

    db.print_table("Employee");
    db.print_table("CustomerMessage");
}