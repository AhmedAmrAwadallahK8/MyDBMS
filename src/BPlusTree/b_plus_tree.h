#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#include "..\DataBaseObjects\record.h"
#include "..\DataBaseObjects\entry.h"
#include "node_block.h"
#include "node.h"


//insert into classroom values ('Packard', '101', '500');
template<typename T>
class B_Plus_Tree{
    protected:
        Node_Block<T> *root_block;
        int type_flag;
    public:
        B_Plus_Tree(int primary_key_type, int block_size);
        ~B_Plus_Tree();

        Node_Block<T>* get_root();

        void select_insert_protocol(Record *input_record);
        void insert(T data, Record *input_record);
        void do_insert(T data, Record *input);
        void insert_leaf(T data, Record *input, Node_Block<T> *leaf_block);
        void block_split();
        void block_split_left();
        void block_split_right();
        void block_split_middle();

        friend class test_b_plus_tree;
};

template<typename T>
B_Plus_Tree<T>::B_Plus_Tree(int primary_key_type, int block_size):
    root_block(new Node_Block<T>(block_size, true, true)),
    type_flag(primary_key_type)
    {}

/* Later this will need to handle deleting all the pointers recursively */
template<typename T>
B_Plus_Tree<T>::~B_Plus_Tree(){}

template<typename T>
Node_Block<T>* B_Plus_Tree<T>::get_root(){
    return root_block;
}

template<typename T>
void B_Plus_Tree<T>::insert(T data, Record *input){
    std::cout << "Data entering Insert: " << data << std::endl;
    if(root_block->is_leaf()){
        insert_leaf(data, input, root_block);
    }
    
}

// template<typename T>
// void B_Plus_Tree<T>::select_insert_protocol(Record *input){
//      /* Scope envy occuring here */
//     if(type_flag == Entry::INT){
//         int int_data = input->get_head_ptr()->get_int();
//         do_insert(int_data, input);
//     }
//     else if(type_flag == Entry::DOUBLE){
//         double dbl_data = input->get_head_ptr()->get_dbl();
//         do_insert(dbl_data, input);
//     }
//     else if(type_flag == Entry::CHAR){
//         char char_data = input->get_head_ptr()->get_char();
//         do_insert(char_data, input);
//     }
//     else if(type_flag == Entry::STRING){
//         std::string str_data = input->get_head_ptr()->get_str();
//         do_insert(str_data, input);
//     }
//     else{
//         std::cout << "Unhandled Type\n";
//     }
// }

// template<typename T>
// void B_Plus_Tree<T>::do_insert(T data, Record *input){
//     if(root_block->is_leaf()){
//         insert_leaf(input, root_block);
//     }
//     std::cout << "Data: " << data << std::endl;
// }

template<typename T>
void B_Plus_Tree<T>::insert_leaf(T data, Record *input, Node_Block<T> *leaf_block){
    if(leaf_block->is_full()){
        /* add new block logic */
        std::cout << "Entered full block\n";
    }
    else{
        leaf_block->add_leaf_node(data, input);
    }
}

template<typename T>
void B_Plus_Tree<T>::block_split(){

}

#endif