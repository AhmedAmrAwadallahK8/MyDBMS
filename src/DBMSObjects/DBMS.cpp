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
    current_database(nullptr),
    running(true)
{

}

DBMS::~DBMS(){


}

void DBMS::engine(){
    std::cout << "Welcome to ASQL database. Type q or quit to exit the program.\n";
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
    parsed_query = Parser(query);
    parsed_query.get_token();
    current_token = parsed_query.get_token();
    if(current_token == "create"){
        create_statement();
    }
    else{
        std::cout << "Expected a statement token instead got " << current_token << std::endl;
    }
}

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
    else{
        if(current_token == ";"){
            std::cout << "Expected table identifier instead got nothing\n";
        }
        else{
            /* create table */
        }
    }
}

bool DBMS::query_empty(std::string query){
    if(query == ""){
        return true;
    }
    return false;
}



/* TODO: Handle new databases with a name already in the database */
void DBMS::create_database(std::string input_name){
    if(database_exists(input_name)){
        std::cout << "Database with name " << input_name << " already exists\n";
    }
    else{
        Database* new_db = new Database(input_name);
        databases.insert(std::pair<std::string, Database*>(input_name, new_db));
        std::cout << "Created Database " << input_name << "\n";
    }
}

bool DBMS::database_exists(std::string db_name){
    if(databases.count(db_name) == 1){
        return true;
    }
    return false;
}

void DBMS::use_database(std::string db_name){
    Database* selected_database = databases.at(db_name);
    current_database = selected_database;
}