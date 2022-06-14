

#include "node.h"

Node::Node(Entry* input_entry, Node_Block* block_entry):
    entry_ptr(input_entry),
    child_block_ptr(block_entry),
    record_ptr(nullptr)
    {}

Node::Node(Entry* input_entry, Record* input_record):
    entry_ptr(input_entry),
    child_block_ptr(nullptr),
    record_ptr(input_record)
    {}

Node::~Node(){}

Entry* Node::get_entry_ptr(){
    return entry_ptr;
}

Node_Block* Node::get_child_ptr(){
    return child_block_ptr;
}

Record* Node::get_record_ptr(){
    return record_ptr;
}

/* TODO: Need to complete node_block before testing */
void Node::test(){
    Entry a(2);
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record b = Record(attr, entries); 
}