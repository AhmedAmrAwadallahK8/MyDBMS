

#include "entry.h"
#include "int_entry.h"

Int_Entry::Int_Entry(int x):
    Entry::Entry("int"),
    data(x)
    {}

Int_Entry::~Int_Entry(){}

int Int_Entry::get_data(){
    return data;
}