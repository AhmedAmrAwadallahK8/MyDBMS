#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>

#include "table.h"

class Database{
    protected:
        std::string database_name;
        std::vector<Table*> tables;
    public:
        Database();
        ~Database();
};

#endif