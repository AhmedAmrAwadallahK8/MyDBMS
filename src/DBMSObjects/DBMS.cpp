#include <map>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "..\DataBaseObjects\database.h"
#include "dbms.h"

DBMS::DBMS():
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
    std::cout << query << std::endl;
}

bool DBMS::query_empty(std::string query){
    if(query == ""){
        return true;
    }
    return false;
}



/* TODO: Handle new databases with a name already in the database */
void DBMS::add_database(std::string input_name){
    Database* new_db = new Database(input_name);
    databases.insert(std::pair<std::string, Database*>(input_name, new_db));
}

void DBMS::use_database(std::string db_name){
    Database* selected_database = databases[db_name];
    current_database = selected_database;
}