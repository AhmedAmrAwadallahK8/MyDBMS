#include <iostream>

#include "DataBaseObjects\entry.h"

// Template Issue: Reflections?

int main(){
    //Entry *e = new Entry("Hello");
    // Entry f(2);
    // decltype(f) *g = &f;
    Entry d = Entry("Hello", (int*)nullptr);
    Entry c = Entry('a', &d);
    Entry b = Entry(2.3, &c);
    Entry a = Entry(2, &b);

    /* Testing Normal Functions */
    std::cout << "Int Test| Type: " << a.get_type()  << " Value: " << a.data << std::endl;
    std::cout << "Double Test| Type: " << b.get_type()  << " Value: " << b.data << std::endl;
    std::cout << "Char Test| Type: " << c.get_type()  << " Value: " << c.data << std::endl;
    std::cout << "String Test| Type: " << d.get_type()  << " Value: " << d.data << std::endl;

    /* Testing pointer relationships */
    // std::cout << "A Test| Type: " << a.get_type()  << " Value: " << a.data << std::endl;

    std::cout << "A Test| Address: " << &a << " Next Address: " << a.next_entry << " Value: " << a.data << std::endl;
    std::cout << "B Test| Address: " << &b << " Next Address: " << b.next_entry << " Value: " << b.data << std::endl;
    std::cout << "C Test| Address: " << &c << " Next Address: " << c.next_entry << " Value: " << c.data << std::endl;
    std::cout << "D Test| Address: " << &d << " Next Address: " << d.next_entry << " Value: " << d.data << std::endl;
    
    // std::cout << "B Test| Type: " << b.get_type()  << " Value: " << b.data << std::endl;
    // std::cout << "C Test| Type: " << c.get_type()  << " Value: " << c.data << std::endl;
    // std::cout << "D Test| Type: " << d.get_type()  << " Value: " << d.data << std::endl;
    

    //std::cout << "Int Test| Type: " << e.get_type() << " Value: " << e.get_type() << std::endl;
    //std::cout << "String Test| Type: " << g->data << " Value: " << g->get_type() << std::endl;



    std::cout << "Program Execution Complete";
}