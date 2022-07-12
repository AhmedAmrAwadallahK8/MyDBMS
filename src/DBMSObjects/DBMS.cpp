#include <map>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "..\DataBaseObjects\database.h"
#include "..\QueryLanguage\parser.h"
#include "dbms.h"

DBMS::DBMS():
    parsed_query(""),
    current_database(""),
    running(true)
{

}

DBMS::~DBMS(){


}

void DBMS::engine(){
    system("cls");
    std::cout << "Welcome to ASQL database. Type q or quit to exit the program.\n";
    std::cout << "Querys are not executed until a semicolon(;) character is input into the program\n";
    std::string query = "";
    while(running){
        query = get_query();
        execute_query(query);
        // analyze_syntax(query); /* Needs to be its own class */
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
    else{
        std::cout << "Expected a statement token instead got " << current_token << std::endl;
    }
}

void DBMS::drop_statement(){
    current_token = parsed_query.get_token();
    if(current_token == "database"){
        current_token = parsed_query.get_token(); 
        if(end_of_query()){
            std::cout << "Expected database identifier instead got ;\n";
        }
        else{
            drop_database(current_token);
        }
    } 
    else if(current_token == "table"){
       /* Table Logic */ 
    }
    else{
        std::cout << "Expected keyword database or table instead got " << current_token << "\n";
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
        /* Code for showing table */
    }
    else{
        std::cout << "Expected keyword databases or tables instead got " << current_token << "\n";
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
        if(current_token == ";"){
            std::cout << "Expected database identifier instead got nothing\n";
        }
        else{
            create_database(current_token);
        }
    }
    else if(current_token == "table"){
        current_token = parsed_query.get_token();
        if(current_token == ";"){
            std::cout << "Expected table identifier instead got nothing\n";
        }
        else{
            /* create table */
        }
    }
    else{
        std::cout << "Expected keyword table or database instead got " << current_token << "\n";
    }
}

bool DBMS::query_empty(std::string query){
    if(query == ""){
        return true;
    }
    return false;
}



/* TODO: Check if token is ; before executing*/
/* Additonally need to update this function so that is compatible with our execution abstraction*/
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
/* Abstraction code for checking if a query has a semicolon, does not work but comment
archiving this for now, can be deleted if needed*/
//void DBMS::execute_if_end_of_query(std::function<void()>* dbms_func){
//    current_token = parsed_query.get_token();
//    if(end_of_query()){
//       dbms_func(); 
//    }
//    else{
//        std::cout << "Expected ; got " << current_token << " instead\n";
//    }
//}

bool DBMS::end_of_query(){
    if(current_token == ";"){
        return true;
    }
    else{
        return false;
    }
}

void DBMS::expected_end_of_query(){
    std::cout << "Expected ; instead got " << current_token << "\n";
}