//
// Created by thedushn on 20-May-21.
//

#ifndef MAKING_LISTS_CIRCULARLIST_H
#define MAKING_LISTS_CIRCULARLIST_H

#include <iostream>
struct  NodeC{

    int data;
    NodeC *next;

};
class CircularList {

private:
    NodeC *head;
    NodeC *tail;
public:
    CircularList();

    virtual ~CircularList();

    void create(int value);

    void display();
    void reverse_list();

    void preppend(int value);
    void append(int value);
    void insert_at_index(int value,int index);
    void delete_element_by_index(int index);
    void delete_duplicates();


};


#endif //MAKING_LISTS_CIRCULARLIST_H
