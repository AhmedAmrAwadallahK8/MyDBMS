#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <typeinfo>
#include <iostream>

template <typename Type>
struct Entry{
    Type data;
    void *next_entry;

    Entry(Type data);
    ~Entry();
    std::string get_type();

};

template<typename Type>
Entry<Type>::Entry(Type data):
    data(data),
    next_entry(nullptr)
    {}

template<typename Type>
Entry<Type>::~Entry(){}

template<typename Type>
std::string Entry<Type>::get_type(){
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
        return type_info;
    }
}

void test_entry(){
    Entry d = Entry("Hello");
    Entry c = Entry('a');
    Entry b = Entry(2.3);
    Entry a = Entry(2);

    /* Testing Normal Functions */
    std::cout << "Int Test| Type: " << a.get_type()  << " Value: " << a.data << std::endl;
    std::cout << "Double Test| Type: " << b.get_type()  << " Value: " << b.data << std::endl;
    std::cout << "Char Test| Type: " << c.get_type()  << " Value: " << c.data << std::endl;
    std::cout << "String Test| Type: " << d.get_type()  << " Value: " << d.data << std::endl;

    /* Testing pointer relationships */
    std::cout << "A Test| Address: " << &a << " Next Address: " << a.next_entry << " Value: " << a.data << std::endl;
    std::cout << "B Test| Address: " << &b << " Next Address: " << b.next_entry << " Value: " << b.data << std::endl;
    std::cout << "C Test| Address: " << &c << " Next Address: " << c.next_entry << " Value: " << c.data << std::endl;
    std::cout << "D Test| Address: " << &d << " Next Address: " << d.next_entry << " Value: " << d.data << std::endl;
}

#endif