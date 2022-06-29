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
        int default_block_size;
    public:
        B_Plus_Tree();
        B_Plus_Tree(int primary_key_type, int block_size);
        ~B_Plus_Tree();

        Node_Block<T>* get_root();

        void select_insert_protocol(Record *input_record);
        void insert(T data, Record *input_record);
        void do_insert(T data, Record *input);
        void insert_leaf(T data, Record *input, Node_Block<T> *leaf_block);

        void leaf_block_split(T data, Record *input, Node_Block<T> *leaf_block);
        void node_block_split();

        Node_Block<T>* get_correct_leaf_block(T data, Node_Block<T>* node_block);

        void no_parent();
        void no_right_neighbor();
        void no_left_neighbor();

        void block_split_left();
        void block_split_right();
        void block_split_middle();

        void print_tree();

        friend class test_b_plus_tree;
};

template<typename T>
B_Plus_Tree<T>::B_Plus_Tree(int primary_key_type, int block_size):
    root_block(new Node_Block<T>(block_size, true, true)),
    type_flag(primary_key_type),
    default_block_size(block_size)
    {}

template<typename T>
B_Plus_Tree<T>::B_Plus_Tree():
    default_block_size(3),
    root_block(new Node_Block<T>(default_block_size, true, true))
    {}

/* Later this will need to handle deleting all the pointers recursively */
template<typename T>
B_Plus_Tree<T>::~B_Plus_Tree(){}

template<typename T>
Node_Block<T>* B_Plus_Tree<T>::get_root(){
    return root_block;
}

template<typename T>
void B_Plus_Tree<T>::print_tree(){
    Node_Block<T>* curr_block = root_block;
    while(curr_block->has_child()){
        curr_block = curr_block->get_child_block_ptr();
    }
    while(curr_block->has_next()){
        curr_block->print_block_records();
        curr_block = curr_block->get_next_leaf_ptr();
    }
    curr_block->print_block_records();
}

template<typename T>
void B_Plus_Tree<T>::insert(T data, Record *input){
    std::cout << "Inserting Data: " << data << "\n";
    if(root_block->is_leaf()){
        insert_leaf(data, input, root_block);
    }
    else{ /* Get to the correct leaf block */
        Node_Block<T>* leaf_block =  get_correct_leaf_block(data, root_block);
        insert_leaf(data, input, leaf_block);
    }
    
}

template<typename T>
Node_Block<T>* B_Plus_Tree<T>::get_correct_leaf_block(T data, Node_Block<T>* node_block){
    if(node_block->is_leaf()){
        return node_block;
    }
    else{
        Node_Block<T>* next_child_block = node_block->find_next_child(data);
        return get_correct_leaf_block(data, next_child_block);
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
        leaf_block->add_leaf_node(data, input);
        leaf_block_split(data, input, leaf_block);
        
        /* add new block logic */
    }
    else{
        leaf_block->add_leaf_node(data, input);
    }
}

template<typename T>
void B_Plus_Tree<T>::leaf_block_split(T data, Record *input, Node_Block<T> *leaf_block){
    if(leaf_block->is_root()){
            Node_Block<T>* new_root = new Node_Block<T>(default_block_size, false, true);
            Node_Block<T>* new_next = new Node_Block<T>(default_block_size, true, false);

            Node<T> new_leaf_node = leaf_block->get_and_remove_last_node();
            Node<T> old_leaf_node = leaf_block->get_and_remove_last_node();
            new_root->add_node(old_leaf_node.get_data(), new_next);
            new_next->add_leaf_direct(old_leaf_node);
            new_next->add_leaf_direct(new_leaf_node);

            leaf_block->set_root(false);

            leaf_block->set_parent(new_root);
            new_next->set_parent(new_root);
            new_root->set_child(leaf_block);

            leaf_block->set_next(new_next);
            new_next->set_prev(leaf_block);

            root_block = new_root;    
    }
    else{
        return;
    }
}


#endif