#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

class Record;
class Test_B_Plus_Tree;
class Node_Block;


//insert into classroom values ('Packard', '101', '500');

class B_Plus_Tree{
    protected:
        Node_Block *root_block;
        int type_flag;
        bool empty;
    public:
        B_Plus_Tree(int primary_key_type, int block_size);
        ~B_Plus_Tree();

        void select_insert_protocol(Record *input_record);
        void insert(Record *input_record);
        template<typename T>
        void do_insert(T data, Record *input);
        void first_insert(Record *input);
        void block_split();
        void block_split_left();
        void block_split_right();
        void block_split_middle();

        friend class test_b_plus_tree;
};

#endif