#ifndef LEAF_NODE_H
#define LEAF_NODE_H

#include "abstract_node.h"
#include "record.h"

class Leaf_Node: public Abstract_Node{
    protected:
        Record *record_ptr;
    public:
        Leaf_Node();
        ~Leaf_Node();
};

#endif