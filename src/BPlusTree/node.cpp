#include <iostream>
#include <vector>

#include "..\DataBaseObjects\entry.h"
#include "..\DataBaseObjects\record.h"
#include "node.h"
#include "node_block.h"


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


void Node::test(){
    Entry a(2);
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record b(attr, entries);
    Node_Block c(4, true, true);

    Node node(&a, &c);
    Node leaf(&a, &b);

    std::cout << "Node Test. Entry Address: " << node.get_entry_ptr() << " Child Block Address: " << 
                node.get_child_ptr() << " Record Address: " << node.get_record_ptr() << std::endl;

    std::cout << "Leaf Test. Entry Address: " << leaf.get_entry_ptr() << " Child Block Address: " << 
                leaf.get_child_ptr() << " Record Address: " << leaf.get_record_ptr() << std::endl;
}