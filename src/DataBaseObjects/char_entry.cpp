#include "entry.h"
#include "char_entry.h"

Char_Entry::Char_Entry(char c):
    Entry("char"),
    data(c)
    {}

Char_Entry::~Char_Entry(){}

char Char_Entry::get_data(){
    return data;
}
