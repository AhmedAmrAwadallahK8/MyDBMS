#include <vector>

#include "node.h"
#include "node_block.h"



Node_Block::Node_Block(int size_input, bool leaf_input, bool root_input):
    parent_block(nullptr),
    child_block(nullptr),
    next_leaf_block(nullptr),
    prev_leaf_block(nullptr),
    block_size(size_input),
    leaf(leaf_input),
    root(root_input)
    {}

Node_Block::~Node_Block(){}


