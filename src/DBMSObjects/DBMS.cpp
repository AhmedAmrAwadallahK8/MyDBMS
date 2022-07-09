#include <map>
#include <string>
#include <chrono>
#include <thread>

#include "..\DataBaseObjects\database.h"
#include "DBMS.h"

DBMS::DBMS():
    current_database(nullptr),
    running(true)
{

}

DBMS::~DBMS(){


}

void DBMS::engine(){
    std::string query;
    while(running){
        query = get_query();
        parse_and_execute_query(query);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

std::string DBMS::get_query(){

}

void DBMS::parse_and_execute_query(std::string query){

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