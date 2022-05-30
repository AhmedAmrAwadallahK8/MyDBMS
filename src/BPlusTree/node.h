#ifndef NODE_H
#define NODE_H

#include "entry.h"

class Node{
    protected:
        Entry *primary_key;
        Node *child_ptr;
        Node *next_node;
        bool is_leaf;
    public:
        Node();
        ~Node();
        Node* get_child();
};

#endif