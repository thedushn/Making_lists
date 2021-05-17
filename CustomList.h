//
// Created by thedushn on 16-May-21.
//

#ifndef MAKING_LISTS_CUSTOMLIST_H
#define MAKING_LISTS_CUSTOMLIST_H
#include <iostream>

struct Node {
    int data;
    Node *next;

};

class CustomList {

private:
    Node *tail;
    Node *head;
    int size;
public:
    void Create(int value);
    void display();
    void prepend(int value);
    void append(int value);
    void insert(int value,int index);
    int get_size();
    void delete_element_by_index(int index);
    void delete_element_by_key(int key);
    int get_size_the_bad_way();
    bool search(int element);
    int search_num_of_elements(int element);
    void remove_duplicate();
    void reverse_list();
    void segregate_even_odd();
    void segregate_even_odd_using_p();



    CustomList();

    ~CustomList();
};


#endif //MAKING_LISTS_CUSTOMLIST_H
