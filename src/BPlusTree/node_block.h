#ifndef NODE_BLOCK_H
#define NODE_BLOCK_H

class Node;

class Node_Block{
    protected:
        Node_Block *parent_block;
        Node_Block *child_block;
        std::vector<Node> node_vec;
        Node_Block *next_leaf_block;
        Node_Block *prev_leaf_block;
        int block_size;
        bool full, leaf, root;
    public:
        Node_Block(int size_input, bool leaf_input, bool root_input);
        ~Node_Block();

        Node_Block* get_parent_block_ptr();
        Node_Block* get_child_block_ptr();
        Node_Block* get_next_leaf_ptr();
        Node_Block* get_prev_leaf_ptr();
        bool is_full();
        bool is_leaf();
        bool is_root();

        void set_parent();
        void set_child();
        void set_next();
        void set_prev();
        void set_root();

        void add_node();
};

#endif