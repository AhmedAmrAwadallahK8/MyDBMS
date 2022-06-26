
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

void B_Plus_Tree::insert(Record *input){
    select_insert_protocol(input);
}

void B_Plus_Tree::select_insert_protocol(Record *input){
    switch(type_flag){
        case Entry::INT:
            do_insert(input->get_head_ptr()->get_int()); /* Scope envy occuring here */
            break;
        case Entry::DOUBLE:
            do_insert(input->get_head_ptr()->get_dbl());
            break;
        case Entry::CHAR:
            do_insert(input->get_head_ptr()->get_char());
            break;
        case Entry::STRING:
            do_insert(input->get_head_ptr()->get_str());
            break;
        default: /* Unhandled Case Logic */
            break; 
    }
}

template<typename T>
void B_Plus_Tree::do_insert(T data){
    std::cout << "Data: " << data << std::endl;
}

void B_Plus_Tree::block_split(){

}
