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
    std::vector<std::string> entries{"2", "2.3", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record a = Record(attr, entries);

    Entry* curr_entry = a.primary_key_ptr;
    std::cout << "Record Test|" << " Value: " << curr_entry->int_entry << std::endl;
    curr_entry = curr_entry->next_entry;
    std::cout << "Record Test|" << " Value: " << curr_entry->dbl_entry << std::endl;
    curr_entry = curr_entry->next_entry;
    std::cout << "Record Test|" << " Value: " << curr_entry->char_entry << std::endl;
    curr_entry = curr_entry->next_entry;
    std::cout << "Record Test|" << " Value: " << curr_entry->str_entry << std::endl;
    //test_entry();



    std::cout << "Program Execution Complete";
}