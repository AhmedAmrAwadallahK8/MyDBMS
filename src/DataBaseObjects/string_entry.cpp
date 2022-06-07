#include <string>

#include "entry.h"
#include "string_entry.h"

String_Entry::String_Entry(std::string s):
    Entry("string"),
    data(s)
    {}

String_Entry::~String_Entry(){}

std::string String_Entry::get_data(){
    return data;
}