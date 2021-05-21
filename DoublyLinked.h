//
// Created by thedushn on 18-May-21.
//

#ifndef MAKING_LISTS_DOUBLYLINKED_H
#define MAKING_LISTS_DOUBLYLINKED_H
#include <iostream>
struct  NodeD{

    int data;
    NodeD *next;
    NodeD *prev;
};

class DoublyLinked {

private:
    NodeD *head{};
    NodeD *tail{};
    int size{};
public:
    void create(int value);
    DoublyLinked();

    void dispay();
    void reverse_dispay();

    void append(int value);
    void preppend(int value);

    void insert_at_position(int value ,int index);
    void insert_before_index(int value , int index);

    void remove_from_list_by_index(int index);
    void remove_from_list_by_key(int key);
    void remove_from_list_by_pointer(NodeD *p);
    void remove_from_list_if_duplicate();
    void find_size();
    void reverse_array();

    NodeD *getHead() const;

    NodeD *getTail() const;

    int getSize() const;

    virtual ~DoublyLinked();

};


#endif //MAKING_LISTS_DOUBLYLINKED_H
