#ifndef INT_ENTRY_H
#define INT_ENTRY_H

#include "entry.h"

class Int_Entry: public Entry{
    protected:
        int data;
    public:
        Int_Entry(int data);
        ~Int_Entry();

        int get_data();

};

#endif