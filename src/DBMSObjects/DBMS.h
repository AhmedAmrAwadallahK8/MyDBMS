#ifndef DBMS_H
#define DBMUS_H

#include<vector>
#include<map>
#include<string>

class Database;

class DBMS{
    protected:
        std::map<std::string, Database*> databases;
        Database* current_database;
    public:
        DBMS();
        ~DBMS();

        void add_database(std::string input_name);
        void select_database(std::string db_name);
};

#endif