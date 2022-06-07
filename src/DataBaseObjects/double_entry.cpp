#include "entry.h"
#include "double_entry.h"

Double_Entry::Double_Entry(double d):
    Entry("double"),
    data(d)
    {}

Double_Entry::~Double_Entry(){}

double Double_Entry::get_data(){
    return data;
}