#include <iostream>
#include <vector>

#include "..\BPlusTree\b_plus_tree.h"
#include "test_b_plus_tree.h"
#include "..\DataBaseObjects\entry.h"
#include "..\DataBaseObjects\record.h"

void Test_B_Plus_Tree::test(){
    bool all_tests_passed = true;
    test_correct_tree_type();




    if(all_tests_passed){
        std::cout << "All tests passed\n";
    }
    else{
        std::cout << "One more tests failed\n";
    }
}

void Test_B_Plus_Tree::test_correct_tree_type(){
    int default_size = 4;
    B_Plus_Tree int_tree(Entry::INT, default_size);
    B_Plus_Tree dbl_tree(Entry::DOUBLE, default_size);
    B_Plus_Tree char_tree(Entry::CHAR, default_size);
    B_Plus_Tree str_tree(Entry::STRING, default_size);

    std::vector<std::string> entries1{"2", "2.34", "a", "Hello"};
    std::vector<int> attr1{Entry::INT, Entry::DOUBLE, Entry::CHAR, Entry::STRING};
    Record *pk_int = new Record(attr1, entries1);
    std::vector<std::string> entries2{"2.32", "2.34", "a", "Hello"};
    std::vector<int> attr2{Entry::DOUBLE, Entry::DOUBLE, Entry::CHAR, Entry::STRING};
    Record *pk_dbl = new Record(attr2, entries2);
    std::vector<std::string> entries3{"c", "2.34", "a", "Hello"};
    std::vector<int> attr3{Entry::CHAR, Entry::DOUBLE, Entry::CHAR, Entry::STRING};
    Record *pk_char = new Record(attr3, entries3);
    std::vector<std::string> entries4{"Dancing", "2.34", "a", "Hello"};
    std::vector<int> attr4{Entry::STRING, Entry::DOUBLE, Entry::CHAR, Entry::STRING};
    Record *pk_str = new Record(attr4, entries4);

    int_tree.insert(pk_int);
    dbl_tree.insert(pk_dbl);
    char_tree.insert(pk_char);
    str_tree.insert(pk_str);

    delete pk_int;
    delete pk_dbl;
    delete pk_char;
    delete pk_str;
}