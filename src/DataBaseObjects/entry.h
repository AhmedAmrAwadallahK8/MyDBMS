#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <typeinfo>

template <typename Type, typename Next_Entry_Type>
struct Entry{
    Type data;
    Next_Entry_Type *next_entry;

    Entry(Type data, Next_Entry_Type *next_entry);
    ~Entry();
    std::string get_type();
};

template<typename Type, typename Next_Entry_Type>
Entry<Type, Next_Entry_Type>::Entry(Type data, Next_Entry_Type *next_entry):
    data(data),
    next_entry(next_entry)
    {}

template<typename Type, typename Next_Entry_Type>
Entry<Type, Next_Entry_Type>::~Entry(){}

template<typename Type, typename Next_Entry_Type>
std::string Entry<Type, Next_Entry_Type>::get_type(){
    std::string type_info = typeid(data).name();
    if(type_info == "i"){
        return "int";
    }
    else if(type_info == "d"){
        return "double";
    }
    else if(type_info == "c"){
        return "char";
    }
    else if(type_info == "PKc"){
        return "string";
    }
    else{
        return "Unsupported Type";
    }
}

#endif