#ifndef DBMS_H
#define DBMUS_H

#include<vector>
#include<map>
#include<string>

class Parser;
class Database;

class DBMS{
    protected:
        std::map<std::string, Database*> databases;
        Parser parsed_query;
        std::string current_token;
        Database* current_database;
        bool running;
    public:
        DBMS();
        ~DBMS();

        void engine();
        std::string get_query();
        void analyze_syntax(std::string query);
        void execute_query(std::string query);
        void execute_if_end_of_query();
        std::string clean_input(std::string input);
        void print_databases();

        void create_statement();
        void show_statement();

        void create_database(std::string input_name);
        void use_database(std::string db_name);

        void show_databases();
        bool database_exists(std::string db_name);
        bool query_open(std::string query);
        bool user_quit(std::string input);
        bool query_empty(std::string query);
        bool end_of_query();
};

#endif