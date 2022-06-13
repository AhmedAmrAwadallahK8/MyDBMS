#include <iostream>
#include <vector>
#include <string>

#include "DataBaseObjects\entry.h"
#include "DataBaseObjects\record.h"

// Template Issue: Reflections?

/* Entry is now a linked list of void pointers, retrive type information of data from the records attribute table */
/*TODO
    Revamp Entry for void pointers
    Revemp record for new entry implementation
    Strings currently unsupported?
 */
int main(){
    std::vector<std::string> entries;
    entries.push_back("andy");
    entries.push_back("2");
    entries.push_back("3");
    std::vector<int> attr;
    attr.push_back(3);
    attr.push_back(0);
    attr.push_back(0);
    Record a = Record(attr, entries);
    std::cout << "Record Test| Type: " << ((Entry<std::string>*)(a.primary_key_ptr))->get_type()  << " Value: " << ((Entry<std::string>*)(a.primary_key_ptr))->data << std::endl;
    //test_entry();



    std::cout << "Program Execution Complete";
}