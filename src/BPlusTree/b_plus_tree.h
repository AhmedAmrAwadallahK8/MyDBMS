#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#include "entry.h"
#include "record.h"
#include "node_block.h"

//insert into classroom values ('Packard', '101', '500');

class B_Plus_Tree{
    protected:
        Node_Block root_block;
        int type_flag;
    public:
        B_Plus_Tree();
        ~B_Plus_Tree();

        void insert(Record input_record);
        void block_split();

};

#endif