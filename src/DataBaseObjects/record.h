#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

#include "Entry.h"

class Record{
    protected:
        std::vector<std::string> attributes;
        std::vector<Entry*> entries;
    public:
        Record();
        ~Record();
};

#endif