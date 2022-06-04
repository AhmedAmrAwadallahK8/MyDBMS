#ifndef ABSTRACT_BLOCK_H
#define ABSTRACT_BLOCK_H

class Abstract_Block{
    protected:
        int block_size;
        bool is_full;
            
    public:
        Abstract_Block();
        ~Abstract_Block();
        virtual void do_nothing()=0; //Temp function to define this class as abstract
        
};

#endif