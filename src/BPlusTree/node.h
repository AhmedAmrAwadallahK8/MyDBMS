#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

#include "..\DataBaseObjects\entry.h"
#include "..\DataBaseObjects\record.h"
#include "..\BPlusTree\node_block.h"

template<typename T>
class Node_Block;
template<typename T>
class Node{
    protected:
        T data;
        Node_Block<T> *child_block_ptr;
        Record *record_ptr;
    public:
        Node(T data, Node_Block<T>* input_block);
        Node(T data, Record* input_record);
        ~Node();

        T get_data();

       void set_child_ptr(Node_Block<T>* new_child);

        Node_Block<T>* get_child_ptr(); 
        Record* get_record_ptr();

        void print_record();
        bool has_record();

        bool operator< (const Node<T> &other) const {
            return data < other.data;
        }
        
        void static test();
};



template<typename T>
Node<T>::Node(T input_data, Node_Block<T>* block_entry):
    data(input_data),
    child_block_ptr(block_entry),
    record_ptr(nullptr)
    {}

template<typename T>
Node<T>::Node(T input_data, Record* input_record):
    data(input_data),
    child_block_ptr(nullptr),
    record_ptr(input_record)
    {}

template<typename T>
Node<T>::~Node(){}

template<typename T>
void Node<T>::set_child_ptr(Node_Block<T>* new_child){
    child_block_ptr = new_child;
}

template<typename T>
void Node<T>::print_record(){
    if(has_record()){
        record_ptr->print_record();
    }
}

template<typename T>
bool Node<T>::has_record(){
    if(record_ptr != nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
T Node<T>::get_data(){
    return data;
}

template<typename T>
Node_Block<T>* Node<T>::get_child_ptr(){
    return child_block_ptr;
}

template<typename T>
Record* Node<T>::get_record_ptr(){
    return record_ptr;
}

template<typename T>
void Node<T>::test(){
    Entry a(2);
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record b(attr, entries);
    Node_Block<int> c(4, true, true);
    
    Node node(2, &c);
    Node leaf(2, &b);

    std::cout << "Node Test. Entry Data: " << node.get_data() << " Child Block Address: " << 
                 node.get_child_ptr() << " Record Address: " << node.get_record_ptr() << std::endl;

    std::cout << "Leaf Test. Entry Data: " << leaf.get_data() << " Child Block Address: " << 
                leaf.get_child_ptr() << " Record Address: " << leaf.get_record_ptr() << std::endl;
}

#endif