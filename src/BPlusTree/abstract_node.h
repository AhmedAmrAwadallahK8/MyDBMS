#ifndef ABSTRACT_NODE_H
#define ABSTRACT_NODE_H

#include <string>

#include "entry.h"


class Abstract_Node{
    protected:
        Entry* primary_key;
    public:
        Abstract_Node();
        ~Abstract_Node();
        virtual void do_nothing()=0; //Temp function to define this class as abstract
        
};

#endif