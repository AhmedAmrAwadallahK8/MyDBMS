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
        std::string clean_input(std::string input);

        void add_database(std::string input_name);
        void use_database(std::string db_name);

        bool query_open(std::string query);
        bool user_quit(std::string input);
        bool query_empty(std::string query);
};

#endif