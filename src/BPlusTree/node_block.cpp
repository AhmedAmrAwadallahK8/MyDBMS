#include <vector>
#include <iostream>

#include "..\DataBaseObjects\entry.h"
#include "..\DataBaseObjects\record.h"
#include "node.h"
#include "node_block.h"



Node_Block::Node_Block(int input_size, bool input_leaf, bool input_root):
    parent_block_ptr(nullptr),
    child_block_ptr(nullptr),
    next_leaf_block_ptr(nullptr),
    prev_leaf_block_ptr(nullptr),
    block_size(input_size),
    full(false),
    leaf(input_leaf),
    root(input_root)
    {}

Node_Block::~Node_Block(){}

void Node_Block::add_node(Entry* input_entry, Node_Block* input_block){
    if((!full) && (!leaf)){
        node_vec.push_back(Node(input_entry, input_block));
        full = check_full();
    }   
}

void Node_Block::add_leaf_node(Entry* input_entry, Record* input_record){
    if((!full) && (leaf)){
        node_vec.push_back(Node(input_entry, input_record));
        full = check_full();
    }
}

bool Node_Block::check_full(){
    if(node_vec.size() == block_size){
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

void Node_Block::test(){
    bool test_success = true;
    Entry test_entry(2);
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record test_record(attr, entries);

    Node_Block test_node_block(3, false, false);
    Node_Block test_leaf_block(3, true, false);
    Node_Block parent(3, true, true);
    Node_Block child(3, true, true);
    Node_Block next(3, true, true);
    Node_Block prev(3, true, true);

    test_node_block.set_parent(&parent);
    test_node_block.set_child(&child);
    test_node_block.set_next(&next);
    test_node_block.set_prev(&next);

    /* Pointer Testing */
    if((test_node_block.get_parent_block_ptr() != &parent) || (test_node_block.get_child_block_ptr() != &child) || 
        (test_node_block.get_next_leaf_ptr() != &next) || (test_node_block.get_prev_leaf_ptr() == &prev)){
        std::cout << "Block ptr set or retrieval failure" << std::endl;
        test_success = false;
    }

    /* Root set and get testing */
    test_node_block.set_root(true);
    if(!test_node_block.is_root()){
        std::cout << "Root status set or retrieval failure" << std::endl;
        test_success = false;
    }

    /* Adding Nodes */
    test_node_block.add_node(&test_entry, &child);
    if(test_node_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Failed to add node" << std::endl;
        test_success = false;
    } 

    test_node_block.add_leaf_node(&test_entry, &test_record);
    if(test_node_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Added a leaf node to a node block" << std::endl;
        test_success = false;
    } 

    test_node_block.add_node(&test_entry, &child);
    test_node_block.add_node(&test_entry, &child);
    test_node_block.add_node(&test_entry, &child);
    if(test_node_block.node_vec.size() > test_node_block.block_size){
        std::cout << "Added node when this block was full" << std::endl;
        test_success = false;
    }

    /* Adding Leaf Nodes into a Leaf Block */
    test_leaf_block.add_leaf_node(&test_entry, &test_record);
    if(test_leaf_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Failed to add leaf node" << std::endl;
        test_success = false;
    } 

    test_leaf_block.add_node(&test_entry, &child);
    if(test_leaf_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Added a node to a leaf node block" << std::endl;
        test_success = false;
    } 

    test_leaf_block.add_leaf_node(&test_entry, &test_record);
    test_leaf_block.add_leaf_node(&test_entry, &test_record);
    test_leaf_block.add_leaf_node(&test_entry, &test_record);
    if(test_leaf_block.node_vec.size() > test_leaf_block.block_size){
        std::cout << "Added node when this leaf block was full" << std::endl;
        test_success = false;
    }

    /* Final Judgement */
    if(test_success){
        std::cout << "All test cases passed" << std::endl;
    }
    else{
        std::cout << "One or more tests failed" << std::endl;
    }
    return;
}
