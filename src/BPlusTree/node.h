#ifndef NODE_H
#define NODE_H

#include "entry.h"
#include "record.h"

class Node{
    protected:
        Entry* entry;
        Node_Block *child_block_ptr;
        Record *record_ptr;
    public:
        Node();
        ~Node();
        Node_Block* get_child();  
};

#endif