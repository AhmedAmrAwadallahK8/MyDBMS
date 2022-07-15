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
        std::vector<std::string> attributes;
        std::vector<std::string> input_strings; 
        std::vector<int> attribute_types;
        Parser parsed_query;
        std::string current_token;
        std::string current_database;
        bool running;
        bool valid_query;
    public:
        DBMS();
        ~DBMS();

        void engine();
        std::string get_query();
        void analyze_syntax(std::string query);
        void execute_query(std::string query);
        //void execute_if_end_of_query(std::function<void()>* dbms_func); /*archived code can be deleted though if needed */
        std::string clean_input(std::string input);
        void print_databases();
        void next_token();

        void create_statement();
        void show_statement();
        void use_statement();
        void drop_statement();
        void insert_statement();
        void select_statement();

        void simple_select_statement();
        void attribute_list();
        void get_attribute();
        bool has_identifier();
        void expected_identifier();
        bool has_attribute_list();
        bool is_keyword_from();
        void expected_keyword_from();
        bool is_keyword_where();
        void expected_keyword_where();
        void expected_attribute_list();
        void has_expression();
        void expected_expression();

        void create_database(std::string input_name);
        void use_database(std::string db_name);
        void drop_database(std::string db_name);
        void delete_database(Database* db);
        void show_databases();

        void create_table(std::string table_name);
        void insert_into_table(std::string table_name);
        void show_tables();

        void string_constant_list();
        void get_input_string();
        void parameter_list();
        void parameter_pair();
        void add_attribute(std::string attribute_name);
        void add_attribute_type(int attribute_type);
        void add_string_input(std::string input);
        bool valid_attribute_type(std::string attribute_type);
        int convert_input_type_to_int(std::string attribute_type);

        void clean_up_attribs_and_types();

        bool database_exists(std::string db_name);
        bool query_open(std::string query);
        bool user_quit(std::string input);
        bool query_empty(std::string query);
        void query_failure();
        bool end_of_query();
        void expected_end_of_query();
        bool database_selected();
        void no_selected_db();
};

#endif