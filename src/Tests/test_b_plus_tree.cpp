#include <iostream>
#include <vector>

#include "..\BPlusTree\b_plus_tree.h"
#include "test_b_plus_tree.h"
#include "..\DataBaseObjects\entry.h"
#include "..\DataBaseObjects\record.h"
#include "..\BPlusTree\node_block.h"

void Test_B_Plus_Tree::test(){
    bool all_tests_passed = true;
    // test_correct_tree_type();
    test_insertion();




    if(all_tests_passed){
        std::cout << "All tests passed\n";
    }
    else{
        std::cout << "One more tests failed\n";
    }
}

void Test_B_Plus_Tree::test_insertion(){
    int default_size = 3;
    B_Plus_Tree<int> int_tree(Entry::INT, default_size);

    std::vector<std::string> entries1{"20", "Hello"};
    std::vector<int> attr1{Entry::INT, Entry::STRING};
    Record *pk_int1 = new Record(attr1, entries1);

    std::vector<std::string> entries2{"70", "Hello"};
    Record *pk_int2 = new Record(attr1, entries2);

    std::vector<std::string> entries3{"30", "Hello"};
    Record *pk_int3 = new Record(attr1, entries3);

    std::vector<std::string> entries4{"5", "Hello"};
    Record *pk_int4 = new Record(attr1, entries4);

    std::vector<std::string> entries5{"12", "Hello"};
    Record *pk_int5 = new Record(attr1, entries5);

    int_tree.insert(pk_int1->get_head_ptr()->get_int(), pk_int1);
    int_tree.insert(pk_int2->get_head_ptr()->get_int(), pk_int2);
    int_tree.insert(pk_int3->get_head_ptr()->get_int(), pk_int3);
    int_tree.insert(pk_int4->get_head_ptr()->get_int(), pk_int4);
    int_tree.insert(pk_int5->get_head_ptr()->get_int(), pk_int5);

    Node_Block<int>* root = int_tree.get_root();
    std::cout << "Printing Root1...\n";
    root->print_block();
    std::cout << "Printing Child of Root...\n";
    root->get_child_block_ptr()->print_block();
    std::cout << "Printing Child Next..\n";
    root->get_child_block_ptr()->get_next_leaf_ptr()->print_block();
    std::cout << "IntAttr\tStrAttr\n";
    int_tree.print_tree();


}

void Test_B_Plus_Tree::test_correct_tree_type(){
    int default_size = 4;
    B_Plus_Tree<int> int_tree(Entry::INT, default_size);
    B_Plus_Tree<double> dbl_tree(Entry::DOUBLE, default_size);
    B_Plus_Tree<char> char_tree(Entry::CHAR, default_size);
    B_Plus_Tree<std::string> str_tree(Entry::STRING, default_size);

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

    int_tree.insert(pk_int->get_head_ptr()->get_int(), pk_int);
    dbl_tree.insert(pk_dbl->get_head_ptr()->get_dbl(), pk_dbl);
    char_tree.insert(pk_char->get_head_ptr()->get_char(), pk_char);
    str_tree.insert(pk_str->get_head_ptr()->get_str(), pk_str);

    delete pk_int;
    delete pk_dbl;
    delete pk_char;
    delete pk_str;
}