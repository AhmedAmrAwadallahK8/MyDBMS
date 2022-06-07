#include <string>

#include "entry.h"

Entry::Entry(std::string type):
    type(type)
    {}

Entry::~Entry(){}

std::string Entry::get_type(){
    return type;
}