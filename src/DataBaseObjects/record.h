#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

#include "entry.h"

//insert into classroom values ('Packard', '101', '500');

class Record{
    public:
        void* primary_key_ptr;
    //public:
        enum attribute_flags{
            INT = 0,
            DOUBLE = 1,
            CHAR = 2,
            STRING = 3
        };
        Record(std::vector<int> &table_attributes, std::vector<std::string> &entries);
        ~Record();
};



// template<typename Type>
// Record<Type>::Record(std::vector<int> &table_attributes, std::vector<std::string> &entries){
//     std::vector<int>::reverse_iterator table_attr_iterator = table_attributes.rbegin();
//     std::vector<std::string>::reverse_iterator entries_iterator = entries.rbegin();
//     Entry<void,void> *prev_entry = nullptr;
//     Entry<void,void> *curr_entry = nullptr;
//     for(;table_attr_iterator != table_attributes.rend() && entries_iterator != entries.rend(); table_attr_iterator++, entries_iterator++){
//         switch(*table_attr_iterator){
//             case(INT):
//                 (Entry<int, decltype(prev_entry)>)curr_entry = Entry((int)entries_iterator, prev_entry);
//                 // curr_entry = Entry(std::stoi(*entries_iterator), prev_entry);
//                 break;
//             case(DOUBLE):
//                 // (Entry<double, decltype(prev_entry)>)curr_entry = Entry((double)entries_iterator, prev_entry);
//                 curr_entry = Entry(std::stod(*entries_iterator), prev_entry);
//                 break;
//             case(CHAR):
//                 // (Entry<char, decltype(prev_entry)>)curr_entry = Entry((char)entries_iterator, prev_entry);
//                 curr_entry = Entry((*entries_iterator).data()[0], prev_entry);
//                 break;
//             case(STRING):
//                 // (Entry<std::string, decltype(prev_entry)>)curr_entry = Entry((std::string)entries_iterator, prev_entry);
//                 curr_entry = Entry(*entries_iterator, prev_entry);
//                 break;
//         }  
//         // (decltype(curr_entry))prev_entry = curr_entry;
//         prev_entry = curr_entry;
//     }
//     // (decltype(prev_entry))primary_key_ptr = prev_entry;
//     primary_key_ptr = prev_entry; 
// }


Record::Record(std::vector<int> &table_attributes, std::vector<std::string> &entries){
    std::vector<int>::iterator table_attr_iterator = table_attributes.begin();
    std::vector<std::string>::iterator entries_iterator = entries.begin();
    switch(*table_attr_iterator){
        case(INT):
            primary_key_ptr = new Entry(std::stoi(*entries_iterator));
            break;
        case(DOUBLE):
            primary_key_ptr = new Entry(std::stod(*entries_iterator));
            break;
        case(CHAR):
            primary_key_ptr = new Entry((*entries_iterator).data()[0]);
            break;
        case(STRING):
            primary_key_ptr = new Entry((std::string)*entries_iterator);
            break;
    }
    table_attr_iterator++;
    entries_iterator++;

    // for(;table_attr_iterator != table_attributes.end() && entries_iterator != entries.end(); table_attr_iterator++, entries_iterator++){
    //     switch(*table_attr_iterator){
    //         case(INT):
    //             break;
    //         case(DOUBLE):
    //             break;
    //         case(CHAR):
    //             break;
    //         case(STRING):
    //             break;
    //     }  
    // } 
}

// for (vector<my_class>::reverse_iterator i = my_vector.rbegin(); i != my_vector.rend(); ++i ) { 
//     }


Record::~Record(){}


#endif