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
        bool running;
    public:
        DBMS();
        ~DBMS();

        void engine();
        std::string get_query();
        void analyze_syntax(std::string query);
        void execute_query(std::string query);
        void add_database(std::string input_name);
        void use_database(std::string db_name);

        bool query_open(std::string query);
};

#endif