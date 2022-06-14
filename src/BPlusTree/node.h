#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

#include "entry.h"
#include "record.h"
#include "node_block.h"

class Node{
    protected:
        Entry* entry_ptr;
        Node_Block *child_block_ptr;
        Record *record_ptr;
    public:
        Node(Entry* input_entry, Node_Block* input_block);
        Node(Entry* input_entry, Record* input_record);
        ~Node();

        Entry* get_entry_ptr();
        Node_Block* get_child_ptr();  
        Record* get_record_ptr();
        
        void static test();
};

#endif