#include <map>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include <excpt.h>

#include "..\DataBaseObjects\database.h"
#include "..\DataBaseObjects\entry.h"
#include "..\QueryLanguage\parser.h"
#include "dbms.h"

DBMS::DBMS():
    parsed_query(""),
    current_database(""),
    running(true)
{}

DBMS::~DBMS(){}

void DBMS::engine(){
    system("cls");
    std::cout << "Welcome to ASQL database. Type q or quit to exit the program.\n";
    std::cout << "Querys are not executed until a semicolon(;) character is input into the program\n";
    std::cout << "All queries are expected to be lower case.\n";
    std::string query = "";
    while(running){
        clean_up_attribs_and_types();
        query = get_query();
        valid_query = true;
        execute_query(query);
    }
    std::cout << "Thank you for using my DBMS\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    system("cls");
}

std::string DBMS::get_query(){
    std::string query = "";
    std::string input = "";
    std::cout << "Enter Query:";
    bool first_line = true;
    while(query_open(input)){
        if(first_line){
            first_line = false;
        }
        else{
            query += " ";
            std::cout << "           >";
        }
        std::getline(std::cin, input);
        input = clean_input(input);
        if(user_quit(input)){
            return "";
        }
        query += input;
    }
    /* this should be encapsulated in its own function */
    std::string final_query = "";
    for(char c : query){
        if(c==';'){
            final_query += c;
            break;
        }
        else{
            final_query += c;
        }
    }
    return final_query;
    /* Remove trailing text after ; */
}

std::string DBMS::clean_input(std::string input){
    input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
    return input;
}

bool DBMS::user_quit(std::string input){
    if((input == "quit") | (input == "q")){
        running = false;
        return true;
    }
    return false;
}

bool DBMS::query_open(std::string input){
    for(char c : input){
        if(c == ';'){
            return false;
        }
    }
    return true;
}

void DBMS::execute_query(std::string query){
    if(query_empty(query)){
        return;
    }
    parsed_query = std::move(Parser(query));
    parsed_query.get_token();
    current_token = parsed_query.get_token();
    if(current_token == "create"){
        create_statement();
    }
    else if(current_token == "show"){
        show_statement();
    }
    else if(current_token == "use"){
        use_statement();
    }
    else if(current_token == "drop"){
        drop_statement();
    }
    else if(current_token == "insert"){
        insert_statement();
    }
    else if(current_token == "select"){
        simple_select_statement();
    }
    else{
        std::cout << "Expected a statement token instead got " << current_token << std::endl;
    }
}

/* simpleSelect: select attributeList from tableName where expression ; */
void DBMS::simple_select_statement(){
    next_token();
    if(has_attribute_list()){
        attribute_list();
    }
    else{
        expected_attribute_list();
    }
    if(is_keyword_from()){}
    else{
        expected_keyword_from();
    }
    next_token();
    std::string table_name;
    if(has_identifier()){
        table_name = current_token;
    }
    else{
        expected_identifier();
    }
    next_token();
    if(end_of_query()){
        if(database_selected()){
            Database* db = databases[current_database];
            if(db->table_exists(table_name)){
                Table* table = db->execute_select(table_name, attributes, expression_sequence);
                if(table != nullptr){
                    table->print_table();
                    delete table;
                }
                return;
            }
            else{
                expected_table_to_exist();
                return;
            }
        }
        else{
            no_selected_db();
            return;
        }
    }
    else{
        if(is_keyword_where()){
        }
        else{
            expected_end_of_query();
            return;
        }
    }
    if(is_keyword_where()){
        expression();
    }
    else{
        expected_keyword_where();
    }
    if(end_of_query()){
        select_setup_and_execute(table_name);
    }
    else{
        expected_end_of_query();
        return;
    }
}

void DBMS::expression(){
    next_token();
    expression_sequence.push_back(current_token);
    next_token();
    if(valid_op()){
       expression_sequence.push_back(current_token); 
       next_token();
    }
    else{
        expected_valid_op();
    }
    expression_sequence.push_back(current_token);
    next_token();
}

bool DBMS::valid_op(){
    if(current_token == "<" || current_token == ">" || current_token == "="){
        return true;
    }
    else{
        return false;
    }
}

void DBMS::expected_valid_op(){
    std::cout << "Expected valid operation instead got " << current_token << ";\n";
    valid_query = false;
}
void DBMS::select_setup_and_execute(std::string table_name){
    if(database_selected()){
        Database* db = databases[current_database];
        if(db->table_exists(table_name)){
            Table* table = db->execute_select(table_name, attributes, expression_sequence);
            if(table != nullptr){
                table->print_table();
                delete table;
            }
        }
        else{
            expected_table_to_exist();
            return;
        }
    }
    else{
        no_selected_db();
        return;
    }
}

bool DBMS::is_keyword_where(){
    if(current_token == "where"){
        return true;
    }
    else{
        return false;
    }
}

void DBMS::expected_keyword_where(){
    std::cout << "Expected keyword where instead got " << current_token << ";\n";
    valid_query = false;
}

bool DBMS::has_identifier(){
    if((current_token == ";") | (current_token == "(") | (current_token == "where") | (current_token == "join")){
        return false;
    }
    else{
        return true;
    }

}

void DBMS::expected_identifier(){
    std::cout << "Expected identifier token instead got special token. Did you forget to specify the name of your table/database?\n";
    valid_query = false;

}

bool DBMS::has_attribute_list(){
    if(current_token == "from"){
        return false;
    }
    else{
        return true;
    }
}

void DBMS::expected_attribute_list(){
    std::cout << "Expected attribute list instead got empty set.\n";
    valid_query = false;
}

bool DBMS::is_keyword_from(){
    if(current_token == "from"){
        return true;
    }
    else{
        return true;
    }

}

void DBMS::expected_keyword_from(){
    std::cout << "Expected keyword from instead got " << current_token << ".\n";
    valid_query = false;
}

void DBMS::attribute_list(){
    if(current_token == "*"){
        add_attribute(current_token);
        next_token();
    }
    else{
        add_attribute(current_token);
        next_token();
        while(current_token == ","){
            next_token();
            add_attribute(current_token);
            next_token();
        }
    }
}

/* Very basic needs major refinement */
void DBMS::select_statement(){
    current_token = parsed_query.get_token();
    if(current_token == "*"){
        current_token = parsed_query.get_token();
        if(current_token == "from"){
            current_token = parsed_query.get_token();
            std::string table_name = current_token;
            if(current_token == ";"){
                std::cout << "Expected table name got ;\n";
            }
            else{
                current_token = parsed_query.get_token();
                if(end_of_query()){
                    if(database_selected()){
                        Database* db = databases[current_database];
                        db->print_table(table_name);
                    }
                    else{
                        no_selected_db();
                    }
                }
                else{
                    expected_end_of_query();
                }
            }
        }
    }
}

void DBMS::insert_statement(){
    current_token = parsed_query.get_token();
    if(current_token != "into"){
        std::cout << "Expected keyword into instead got " << current_token << "\n";
        query_failure();
    }
    current_token = parsed_query.get_token();
    if(current_token == "("){
        std::cout << "Expected table name instead got (\n";
        query_failure();
    }
    else{
        insert_into_table(current_token);
    }
}

void DBMS::insert_into_table(std::string table_name){
    current_token = parsed_query.get_token();
    if(current_token != "("){
        std::cout << "Expected ( instead got " << current_token << "\n";
        query_failure();
    }
    string_constant_list();
    if(current_token != ")"){
        std::cout << "Expected ) instead got " << current_token << "\n";
        query_failure();
    }
    current_token = parsed_query.get_token();
    if(end_of_query()){
        if(database_selected()){
           Database* db = databases[current_database]; 
            try {
                db->insert_into_table_if_exists(table_name, input_strings);
            }
            catch(std::exception& e) {
                std::cerr << "User entered the wrong type for one of the attributes of this table, aborting insertion." << std::endl;
            }
           clean_up_attribs_and_types();
        }
        else{
            no_selected_db();
            return;
        }
    }
    else{
        expected_end_of_query();
    }
}

void DBMS::string_constant_list(){
    get_input_string();
    while(current_token == ","){
        get_input_string();
    }
}

void DBMS::get_input_string(){
    std::string input;
    next_token();
    if(current_token == ")"){
        std::cout << "Expected input value but instead got empty set\n";
        query_failure();
    }
    if(current_token == "\""){
        if(parsed_query.token_is_ahead("\"")){
            input = string_constant();
        }
        else{
            std::cout << "Expected string to close but never encountered a close quotation mark.\n";
            query_failure();
        }
    }
    else if(parsed_query.look_ahead(1) == "."){
        std::string unit = current_token;
        next_token();
        std::string decimal = current_token; 
        next_token();
        std::string incomplete_unit = current_token;
        next_token();
        input = unit + decimal + incomplete_unit;
    }
    else{
        input = current_token;
        next_token();
    }
    add_string_input(input);
}

std::string DBMS::string_constant(){
    std::string str;
    next_token();
    while(current_token != "\""){
        str += current_token;
        next_token();
        if(current_token != "\""){
            str += " ";
        }
    }
    next_token();
    return str;
}

void DBMS::add_string_input(std::string input){
    input_strings.push_back(input);
}

void DBMS::drop_statement(){
    current_token = parsed_query.get_token();
    if(current_token == "database"){
        current_token = parsed_query.get_token(); 
        if(end_of_query()){
            std::cout << "Expected database identifier instead got ;\n";
            query_failure();
        }
        else{
            drop_database(current_token);
        }
    } 
    else if(current_token == "table"){
        if(has_identifier()){
            next_token();
            drop_table(current_token);
        }
        else{
            expected_identifier();
        }
    }
    else{
        std::cout << "Expected keyword database or table instead got " << current_token << "\n";
        query_failure();
    }
}

void DBMS::drop_table(std::string table_name){
    next_token();
    if(end_of_query()){
        if(database_selected()){
            Database* db = get_selected_db(); 
            db->drop_table(table_name);
        }
        else{
            expected_selected_db();
        }
    }
    else{
        expected_end_of_query();
    }
}

void DBMS::drop_database(std::string db_name){
    current_token = parsed_query.get_token();
    if(end_of_query()){
        if(database_exists(db_name)){
            Database* db = databases[db_name];
            delete_database(db);
            databases.erase(db_name);
            current_database = "";
            std::cout << "Database " << db_name << " deleted.\n";
        }
        else{
            std::cout << "Specified databases does not exist in the system.\n";
        }
    }
    else{
        expected_end_of_query();
    }
}

void DBMS::delete_database(Database* db){
    delete db;
}

void DBMS::use_statement(){
    current_token = parsed_query.get_token();
    if(end_of_query()){
        std::cout << "Expected identifier instead got ;\n";
    }
    else{
        use_database(current_token);
    }
}

void DBMS::show_statement(){
    current_token = parsed_query.get_token();
    if(current_token == "databases"){
        show_databases();
    }
    else if(current_token == "tables"){
        show_tables();
    }
    else{
        std::cout << "Expected keyword databases or tables instead got " << current_token << "\n";
        query_failure();
    }
}

void DBMS::show_tables(){
    current_token = parsed_query.get_token();
    if(end_of_query()){
        if(database_selected()){
           Database* db = databases[current_database]; 
           db->print_tables();
        }
        else{
            no_selected_db();
        }

    }
    else{
        expected_end_of_query();
    }
}

void DBMS::show_databases(){
    current_token = parsed_query.get_token();
    if(end_of_query()){
        print_databases();
    }
    else{
        expected_end_of_query();
    }
    return;
}

void DBMS::print_databases(){
    std::cout << "Databases\n";
    std::string db_name;
    for(const auto& pair: databases){
        db_name = pair.first;
        if(db_name == current_database){
            std::cout << "->" << db_name << "\n"; 
        }
        else{
            std::cout << "  " << db_name << "\n"; 
        }
    }
}

/*Need to handle when user wants to make a db name that is also a keyword*/
void DBMS::create_statement(){
    current_token = parsed_query.get_token();
    if(current_token == "database"){
        current_token = parsed_query.get_token();
        if(end_of_query()){
            std::cout << "Expected database identifier instead got nothing\n";
        }
        else{
            create_database(current_token);
        }
    }
    else if(current_token == "table"){
        current_token = parsed_query.get_token();
        if(current_token == "("){
            std::cout << "Expected table identifier instead got nothing\n";
        }
        else{
            create_table(current_token);
        }
    }
    else{
        std::cout << "Expected keyword table or database instead got " << current_token << "\n";
        query_failure();
    }
}

void DBMS::create_table(std::string table_name){
    current_token = parsed_query.get_token();
    if(current_token != "("){
        std::cout << "Expected ( instead got " << current_token << "\n";
        query_failure();
    }
    parameter_list();
    if(current_token != ")"){
        std::cout << "Expected ) instead got " << current_token << "\n";
        query_failure();
    }
    current_token = parsed_query.get_token();
    if(end_of_query()){
        if(database_selected()){
            Database* db = databases[current_database];
            db->create_table(table_name, attributes, attribute_types);
            std::cout << "Created table " << table_name << "\n";
            clean_up_attribs_and_types();
        }
        else{
            no_selected_db();
        }
    }
    else{
        expected_end_of_query();
    }
}

void DBMS::no_selected_db(){
    std::cout << "No database currently selected.\n";
}

void DBMS::clean_up_attribs_and_types(){
    attribute_types.clear();
    attributes.clear();
    input_strings.clear();
    expression_sequence.clear();
}

bool DBMS::database_selected(){
    if(current_database == ""){
        return false;
    }
    else{
        return true;
    }
}

void DBMS::parameter_list(){
    parameter_pair();
    while(current_token == ","){
        parameter_pair();
    }
}

void DBMS::parameter_pair(){
    current_token = parsed_query.get_token();
    if(current_token == ")"){
        std::cout << "Expected identifier type pairs, instead got an empty set.\n";
        query_failure();
    }
    else{
        add_attribute(current_token);
    }
    current_token = parsed_query.get_token();
    if(current_token == ")"){
        std::cout << "Expected identifier type pairs, instead got just an identifier\n";
        query_failure();
    }
    else{
        if(valid_attribute_type(current_token)){
            int attribute_type = convert_input_type_to_int(current_token);
            add_attribute_type(attribute_type);
        }
        else{
            std::cout << "Input attribute type is not recognized or unsupported. Type input was " << current_token << "\n";
            query_failure();
        }
    }
    current_token = parsed_query.get_token();
}

void DBMS::add_attribute(std::string attribute_name){
    attributes.push_back(attribute_name);
}

void DBMS::add_attribute_type(int attribute_type){
    attribute_types.push_back(attribute_type);
}

bool DBMS::valid_attribute_type(std::string attribute_type){
    if((attribute_type=="int") | (attribute_type=="double")|(attribute_type=="char")|(attribute_type=="string")){
        return true;
    }
    else{
        return false;
    }
}

int DBMS::convert_input_type_to_int(std::string attribute_type){
    if(attribute_type == "int"){
        return Entry::INT;
    }
    else if(attribute_type == "double"){
        return Entry::DOUBLE;
    }
    else if(attribute_type == "char"){
        return Entry::CHAR;
    }
    else if(attribute_type == "string"){
        return Entry::STRING;
    }
    else{
        return -1;
    }
}

bool DBMS::query_empty(std::string query){
    if(query == ""){
        return true;
    }
    return false;
}

void DBMS::create_database(std::string input_name){
    current_token = parsed_query.get_token();
    if(end_of_query()){
        if(database_exists(input_name)){
            std::cout << "Database with name " << input_name << " already exists\n";
        }
        else{
            Database* new_db = new Database(input_name);
            databases.insert(std::pair<std::string, Database*>(input_name, new_db));
            std::cout << "Created Database " << input_name << "\n";
        }
    }
    else{
        expected_end_of_query();
    }
}

bool DBMS::database_exists(std::string db_name){
    if(databases.count(db_name) == 1){
        return true;
    }
    return false;
}

void DBMS::use_database(std::string db_name){
    current_token = parsed_query.get_token();
    if(end_of_query()){
        if(database_exists(db_name)){
            current_database = db_name;
            std::cout << "Database " << db_name << " is now selected.\n";
        }
        else{
            std::cout << "Database with name " << db_name << " does not exist in system.\n";
        }
    }
    else{
        expected_end_of_query();
    }
}

bool DBMS::end_of_query(){
    if(current_token == ";"){
        return true;
    }
    else{
        return false;
    }
}

void DBMS::expected_end_of_query(){
    std::cout << "Expected ; instead got " << current_token;
    std::cout << " Or query failed an earlier syntax check.\n";
}

void DBMS::query_failure(){
    valid_query = false;
}

void DBMS::next_token(){
    current_token = parsed_query.get_token();
}

Database* DBMS::get_selected_db(){
    return databases[current_database];
}

void DBMS::expected_selected_db(){
    std::cout << "No database currently select.\n";
}

void DBMS::expected_table_to_exist(){
    std::cout << "Specific table does not exist.\n";
}