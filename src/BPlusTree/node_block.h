#ifndef NODE_BLOCK_H
#define NODE_BLOCK_H

#include <vector>
#include <iostream>
#include <algorithm>

#include "..\DataBaseObjects\record.h"

template <typename T>
class Node;
template<typename T>
class Node_Block{
    protected:
        Node_Block<T> *parent_block_ptr;
        Node_Block<T> *child_block_ptr;
        std::vector<Node<T>*> node_vec;
        Node_Block<T> *next_leaf_block_ptr;
        Node_Block<T> *prev_leaf_block_ptr;
        long long unsigned int block_size;
        bool full, leaf, root;
    public:
        Node_Block(int size_input, bool leaf_input, bool root_input);
        ~Node_Block();

        void add_to_block(T input_data, Node_Block<T>* input_block); /* Dead Code */
        void add_node(T input_data, Node_Block<T>* input_block);
        void add_leaf_node(T input_data, Record* input_record);
        void add_leaf_direct(Node<T>* leaf_node);
        void add_node_direct(Node<T>* node);

        Node_Block<T>* get_parent_block_ptr();
        Node_Block<T>* get_child_block_ptr();
        Node_Block<T>* get_next_leaf_ptr();
        Node_Block<T>* get_prev_leaf_ptr();
        Node<T>* get_and_remove_last_node();
        std::vector<Node<T>*> get_node_vec();
        bool is_full();
        bool is_leaf();
        bool is_root();

        void set_parent(Node_Block<T>* input_block_ptr);
        void set_child(Node_Block<T>* input_block_ptr);
        void set_next(Node_Block<T>* input_block_ptr);
        void set_prev(Node_Block<T>* input_block_ptr);
        void set_root(bool input_root);

        bool compare_nodes(const Node<T>* lhs, const Node<T>* rhs);

        void print_block();

        bool check_full();

        Node_Block<T>* find_next_child(T data);

        bool has_parent();
        bool has_next();
        bool has_prev();
        bool has_child();

        void print_block_records();

        struct data_compare{
            bool operator()(Node<T>* node1, Node<T>* node2) {
                return node1->get_data() < node2->get_data(); 
            }
        };

        void static test();
        bool static test_root();
        bool static test_pointers();
        bool static test_adding_nodes();
        bool static test_adding_leaf_nodes();
        
};

template<typename T>
Node_Block<T>::Node_Block(int input_size, bool input_leaf, bool input_root):
    parent_block_ptr(nullptr),
    child_block_ptr(nullptr),
    next_leaf_block_ptr(nullptr),
    prev_leaf_block_ptr(nullptr),
    block_size(input_size),
    full(false),
    leaf(input_leaf),
    root(input_root)
    {}

template<typename T>
Node_Block<T>::~Node_Block(){
    for(Node<T>* node: node_vec){
        delete node;
    }
    delete child_block_ptr;
}

template<typename T>
void Node_Block<T>::add_node(T input_data, Node_Block<T>* input_block){
    if((!full) && (!leaf)){
        node_vec.push_back(new Node<T>(input_data, input_block));
        std::sort(node_vec.begin(), node_vec.end(), data_compare());
        full = check_full();
    }
    else if((node_vec.size()==block_size) && (!leaf)){
        node_vec.push_back(new Node<T>(input_data, input_block));
        std::sort(node_vec.begin(), node_vec.end(), data_compare());
    }
}

template<typename T>
void Node_Block<T>::add_leaf_node(T input_data, Record* input_record){
    if((!full) && (leaf)){
        node_vec.push_back(new Node<T>(input_data, input_record));
        std::sort(node_vec.begin(), node_vec.end(), data_compare());
        full = check_full();
    }
    else if((node_vec.size()==block_size) && (leaf)){
        node_vec.push_back(new Node<T>(input_data, input_record));
        std::sort(node_vec.begin(), node_vec.end(), data_compare());
    }
}

template<typename T>
void Node_Block<T>::add_node_direct(Node<T>* node){
    node_vec.push_back(node);
}

template<typename T>
void Node_Block<T>::add_leaf_direct(Node<T>* leaf_node){
    node_vec.push_back(leaf_node);
}

template<typename T>
Node<T>* Node_Block<T>::get_and_remove_last_node(){
    Node<T>* node = node_vec.back();
    node_vec.pop_back();
    full = false; /* This could be a problem in the future */
    return node;
}

template<typename T>
Node_Block<T>* Node_Block<T>::find_next_child(T data){
    Node_Block<T>* correct_node = child_block_ptr;
    for(Node<T>* n : node_vec){
        if(data == n->get_data()){
            /* Has to be unique, don't allow the insertion */
        }
        else if(data < n->get_data()){
            return correct_node;
        }
        else if(data > n->get_data()){
            correct_node = n->get_child_ptr();
        }
    }
    return correct_node;
}

template<typename T>
void Node_Block<T>::print_block(){
    for(Node<T>* n: node_vec){
        std::cout << "Data: " << n->get_data() << "\n";
    }
}

template<typename T>
bool Node_Block<T>::check_full(){
    if(node_vec.size() == block_size){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
Node_Block<T>* Node_Block<T>::get_parent_block_ptr(){
    return parent_block_ptr;
}

template<typename T>
Node_Block<T>* Node_Block<T>::get_child_block_ptr(){
    return child_block_ptr;
}

template<typename T>
Node_Block<T>* Node_Block<T>::get_next_leaf_ptr(){
    return next_leaf_block_ptr;
}

template<typename T>
Node_Block<T>* Node_Block<T>::get_prev_leaf_ptr(){
    return prev_leaf_block_ptr;
}

template<typename T>
std::vector<Node<T>*> Node_Block<T>::get_node_vec(){
    return node_vec;
}

template<typename T>
bool Node_Block<T>::is_full(){
    return full;
}

template<typename T>
bool Node_Block<T>::is_leaf(){
    return leaf;
}

template<typename T>
bool Node_Block<T>::is_root(){
    return root;
}

template<typename T>
void Node_Block<T>::set_parent(Node_Block<T>* input_block_ptr){
    parent_block_ptr = input_block_ptr;
}

template<typename T>
void Node_Block<T>::set_child(Node_Block<T>* input_block_ptr){
    child_block_ptr = input_block_ptr;
}

template<typename T>
void Node_Block<T>::set_next(Node_Block<T>* input_block_ptr){
    next_leaf_block_ptr = input_block_ptr;
}

template<typename T>
void Node_Block<T>::set_prev(Node_Block<T>* input_block_ptr){
    prev_leaf_block_ptr = input_block_ptr;
}

template<typename T>
void Node_Block<T>::set_root(bool input_bool){
    root = input_bool;
}

template<typename T>
bool Node_Block<T>::has_parent(){
    if(parent_block_ptr != nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
bool Node_Block<T>::has_next(){
    if(next_leaf_block_ptr != nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
bool Node_Block<T>::has_prev(){
    if(prev_leaf_block_ptr != nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
bool Node_Block<T>::has_child(){
    if(child_block_ptr != nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
void Node_Block<T>::print_block_records(){
    for(Node<T>* n: node_vec){
        n->print_record();
    }
}

template<typename T>
void Node_Block<T>::test(){
    bool test_success = true;

    test_success = test_pointers();
    test_success = test_root();
    test_success = test_adding_nodes();
    test_success = test_adding_leaf_nodes();

    if(test_success){
        std::cout << "All Node_Block test cases passed" << std::endl;
    }
    else{
        std::cout << "One or more tests failed" << std::endl;
    }
    return;
}

/* Code in this function could be broken down further */
template<typename T>
bool Node_Block<T>::test_adding_nodes(){
    Node_Block test_node_block(3, false, false);
    T test_data = 2;
    Node_Block child(3, true, true);
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record test_record(attr, entries);

    test_node_block.add_node(test_data, &child);
    if(test_node_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Failed to add node" << std::endl;
        return false;
    } 

    test_node_block.add_leaf_node(test_data, &test_record);
    if(test_node_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Added a leaf node to a node block" << std::endl;
        return false;
    } 

    test_node_block.add_node(test_data, &child);
    test_node_block.add_node(test_data, &child);
    test_node_block.add_node(test_data, &child);
    if(test_node_block.node_vec.size() > test_node_block.block_size){
        std::cout << "Added node when this block was full" << std::endl;
        return false;
    }

    return true;

}

/* Code in this function could be broken down further */
template<typename T>
bool Node_Block<T>::test_adding_leaf_nodes(){
    Node_Block test_leaf_block(3, true, false);
    T test_data = 2;
    Node_Block child(3, true, true);
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record test_record(attr, entries);

    test_leaf_block.add_leaf_node(test_data, &test_record);
    if(test_leaf_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Failed to add leaf node" << std::endl;
        return false;
    } 

    test_leaf_block.add_node(test_data, &child);
    if(test_leaf_block.node_vec.size() != (long long unsigned int)1){
        std::cout <<"Added a node to a leaf node block" << std::endl;
        return false;
    } 

    test_leaf_block.add_leaf_node(test_data, &test_record);
    test_leaf_block.add_leaf_node(test_data, &test_record);
    test_leaf_block.add_leaf_node(test_data, &test_record);
    if(test_leaf_block.node_vec.size() > test_leaf_block.block_size){
        std::cout << "Added node when this leaf block was full" << std::endl;
        return false;
    }

    test_leaf_block.print_block();

    return true;
}

template<typename T>
bool Node_Block<T>::test_pointers(){
    Node_Block test_node_block(3, false, false);

    Node_Block parent(3, true, true);
    Node_Block child(3, true, true);
    Node_Block next(3, true, true);
    Node_Block prev(3, true, true);

    test_node_block.set_parent(&parent);
    test_node_block.set_child(&child);
    test_node_block.set_next(&next);
    test_node_block.set_prev(&next);

    if((test_node_block.get_parent_block_ptr() != &parent) || (test_node_block.get_child_block_ptr() != &child) || 
        (test_node_block.get_next_leaf_ptr() != &next) || (test_node_block.get_prev_leaf_ptr() == &prev)){
        std::cout << "Block ptr set or retrieval failure" << std::endl;
        return false;
    }
    
    return true;
}

template<typename T>
bool Node_Block<T>::test_root(){
    Node_Block test_node_block(3, false, false);

    test_node_block.set_root(true);
    if(!test_node_block.is_root()){
        std::cout << "Root status set or retrieval failure" << std::endl;
        return false;
    }

    return true;
}

#endif