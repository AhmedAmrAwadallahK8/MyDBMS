#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

#include "entry.h"

class Record{
    protected:
        std::vector<std::string> attributes;
        std::vector<Entry<data_types>*> entries;
    public:
        
        Record();
        ~Record();
};

#endif