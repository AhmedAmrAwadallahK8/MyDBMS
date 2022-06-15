#include <vector>

#include "node.h"
#include "node_block.h"



Node_Block::Node_Block(int size_input, bool leaf_input, bool root_input):
    parent_block_ptr(nullptr),
    child_block_ptr(nullptr),
    next_leaf_block_ptr(nullptr),
    prev_leaf_block_ptr(nullptr),
    block_size(size_input),
    full(false),
    leaf(leaf_input),
    root(root_input)
    {}

Node_Block::~Node_Block(){}

void Node_Block::add_node(Entry* input_entry, Node_Block* input_block){
    if(full){
        return;
    }
    else{
        node_vec.push_back(Node(input_entry, input_block));
        full = is_full();
    }
        
}

void Node_Block::add_leaf_node(Entry* input_entry, Record* input_record){
    if(full){
        return;
    }
    else{
        node_vec.push_back(Node(input_entry, input_record));
        full = is_full();
    }  
}

bool Node_Block::is_full(){
    if(node_vec.size() > block_size){
        return true;
    }
    else{
        return false;
    }
}

Node_Block* Node_Block::get_parent_block_ptr(){
    return parent_block_ptr;
}

Node_Block* Node_Block::get_child_block_ptr(){
    return child_block_ptr;
}

Node_Block* Node_Block::get_next_leaf_ptr(){
    return next_leaf_block_ptr;
}

Node_Block* Node_Block::get_prev_leaf_ptr(){
    return prev_leaf_block_ptr;
}

bool Node_Block::is_full(){
    return full;
}

bool Node_Block::is_leaf(){
    return leaf;
}

bool Node_Block::is_root(){
    return root;
}

void Node_Block::set_parent(Node_Block* input_block_ptr){
    parent_block_ptr = input_block_ptr;
}

void Node_Block::set_child(Node_Block* input_block_ptr){
    child_block_ptr = input_block_ptr;
}

void Node_Block::set_next(Node_Block* input_block_ptr){
    next_leaf_block_ptr = input_block_ptr;
}

void Node_Block::set_prev(Node_Block* input_block_ptr){
    prev_leaf_block_ptr = input_block_ptr;
}

void Node_Block::set_root(bool input_bool){
    root = input_bool;
}
