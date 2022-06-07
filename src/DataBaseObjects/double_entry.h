#ifndef DOUBLE_ENTRY_H
#define DOUBLE_ENTRY_H

#include "entry.h"

class Double_Entry: public Entry{
    protected:
        double data;
    public:
        Double_Entry(double d);
        ~Double_Entry();

        double get_data();
};

#endif