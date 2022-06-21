
#include "..\DataBaseObjects\entry.h"
#include "b_plus_tree.h"
#include "..\DataBaseObjects\record.h"
#include "node_block.h"

B_Plus_Tree::B_Plus_Tree(int primary_key_type, int block_size):
    root_block(new Node_Block(block_size, true, true)),
    type_flag(primary_key_type)
    {}

/* Later this will need to handle deleting all the pointers recursively */
B_Plus_Tree::~B_Plus_Tree(){}

void B_Plus_Tree::select_insert_protocol(Record input){
    switch(type_flag){
        case Entry::INT:
            insert(input.get_head_ptr()->get_int());
            break;
        case Entry::DOUBLE:
            insert(input.get_head_ptr()->get_dbl());
            break;
        case Entry::CHAR:
            insert(input.get_head_ptr()->get_char());
            break;
        case Entry::STRING:
            insert(input.get_head_ptr()->get_str());
            break;
        default: /* Unhandled Case Logic */
            break; 
    }
}

void B_Plus_Tree::insert(auto data){
    std::cout << "Data: " << data << std::endl;
}

void B_Plus_Tree::block_split(){

}
