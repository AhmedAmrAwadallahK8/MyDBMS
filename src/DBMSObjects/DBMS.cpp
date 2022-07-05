#include <map>
#include <string>

#include "..\DataBaseObjects\database.h"
#include "DBMS.h"

DBMS::DBMS():
    current_database(nullptr)
{

}

DBMS::~DBMS(){

}

/* TODO: Handle new databases with a name already in the database */
void DBMS::add_database(std::string input_name){
    Database* new_db = new Database(input_name);
    databases.insert(std::pair<std::string, Database*>(input_name, new_db));
}

void DBMS::select_database(std::string db_name){
    Database* selected_database = databases[db_name];
    current_database = selected_database;
}