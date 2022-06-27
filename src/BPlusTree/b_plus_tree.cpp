
#include "..\DataBaseObjects\entry.h"
#include "b_plus_tree.h"
#include "..\DataBaseObjects\record.h"
#include "node_block.h"

B_Plus_Tree::B_Plus_Tree(int primary_key_type, int block_size):
    root_block(new Node_Block(block_size, true, true)),
    type_flag(primary_key_type),
    empty(true)
    {}

/* Later this will need to handle deleting all the pointers recursively */
B_Plus_Tree::~B_Plus_Tree(){}

Node_Block* B_Plus_Tree::get_root(){
    return root_block;
}

void B_Plus_Tree::insert(Record *input){
    select_insert_protocol(input);
}

void B_Plus_Tree::select_insert_protocol(Record *input){
     /* Scope envy occuring here */
    
    
    
    if(type_flag == Entry::INT){
        int int_data = input->get_head_ptr()->get_int();
        do_insert(int_data, input);
    }
    else if(type_flag == Entry::DOUBLE){
        double dbl_data = input->get_head_ptr()->get_dbl();
        do_insert(dbl_data, input);
    }
    else if(type_flag == Entry::CHAR){
        char char_data = input->get_head_ptr()->get_char();
        do_insert(char_data, input);
    }
    else if(type_flag == Entry::STRING){
        std::string str_data = input->get_head_ptr()->get_str();
        do_insert(str_data, input);
    }
    else{
        std::cout << "Unhandled Type\n";
    }
    // switch(type_flag){
    //     case Entry::INT:
    //         do_insert(int_data, input); 
    //         break;
    //     case Entry::DOUBLE:
    //         do_insert(dbl_data, input);
    //         break;
    //     case Entry::CHAR:    
    //         do_insert(char_data, input);
    //         break;
    //     case Entry::STRING:
    //         do_insert(str_data, input);
    //         break;
    //     default: /* Unhandled Case Logic */
    //         break; 
    // }
}

template<typename T>
void B_Plus_Tree::do_insert(T data, Record *input){
    if(root_block->is_leaf()){
        insert_leaf(input, root_block);
    }
    std::cout << "Data: " << data << std::endl;
}

void B_Plus_Tree::insert_leaf(Record *input, Node_Block *leaf_block){
    if(leaf_block->is_full()){
        /* add new block logic */
        std::cout << "Entered full block\n";
    }
    else{
        leaf_block->add_leaf_node(input->get_head_ptr(), input);
    }
}

void B_Plus_Tree::block_split(){

}
