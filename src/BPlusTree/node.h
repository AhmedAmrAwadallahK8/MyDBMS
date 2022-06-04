#ifndef NODE_H
#define NODE_H

#include "entry.h"
#include "abstract_node.h"

class Node: public Abstract_Node {
    protected:
        Abstract_Node *child_ptr;
    public:
        Node();
        ~Node();
        Abstract_Node* get_child();
        
};

#endif