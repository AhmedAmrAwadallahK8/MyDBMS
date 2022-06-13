#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <typeinfo>

/*Class based behavior not viable, try structs*/

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


















// template <typename Type>
// class Entry{
//     protected:
//         Type data;
//         bool start, end;
//         Entry *next_entry;
//     public:
//         Entry(Type data);
//         ~Entry();
//         std::string get_type();
//         Type get_data();
//         Entry* get_next_entry();

// };

// template<typename Type>
// Entry<Type>::Entry(Type data):
//     data(data)
//     {}

// template<typename Type>
// Entry<Type>::~Entry(){}

// template<typename Type>
// Type Entry<Type>::get_data(){
//     return data;
// }

// template<typename Type>
// Entry* Entry<Type>::get_next_entry(){
//     return next_entry;
// }

// template<typename Type>
// std::string Entry<Type>::get_type(){
//     std::string type_info = typeid(data).name();
//     if(type_info == "i"){
//         return "int";
//     }
//     else if(type_info == "d"){
//         return "double";
//     }
//     else if(type_info == "c"){
//         return "char";
//     }
//     else if(type_info == "PKc"){
//         return "string";
//     }
//     else{
//         return "Unsupported Type";
//     }
// }

#endif