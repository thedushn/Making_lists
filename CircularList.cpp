//
// Created by thedushn on 20-May-21.
//

#include "CircularList.h"

void CircularList::create(int value) {

    NodeC *p=new NodeC;
    p->data=value;
    NodeC *temp;
    if(head== nullptr){

        head=p;
        p->next= nullptr;
        this->tail=p;
    }
    else{

        p->next=head;

        this->tail->next=p;
        head=p;



    }

}
CircularList::CircularList(){

    this->head= nullptr;

}

CircularList::~CircularList() {

    NodeC *temp;

    while(this->head!=this->tail){
        temp= this->head;
        this->head= this->head->next;
        delete temp;


    }
    delete this->tail;


}

void CircularList::display() {

    NodeC *temp= this->head;
    if(temp== nullptr)
        std::cout<< "empty list\n";
    while(temp){
        std::cout<< temp->data<<'\n';
        if(temp==this->tail){
            break;
        }
        temp= temp->next;
    }
    std::cout<<"end of display\n";

}

void CircularList::reverse_list() {

    NodeC *prev, *cur,*new_tail;

    if (this->head == nullptr){
        printf("Cannot reverse empty list.\n");
        return;
    }

    new_tail    = head;
    prev        = tail;
    cur         = head;


// Iterate till you reach the initial node in circular list
    while (head != tail)
    {
        head = head->next;
        cur->next = prev;

        prev = cur;
        cur  = head;
    }

    cur->next = prev;
    tail=new_tail;


}

void CircularList::preppend(int value) {
    NodeC *temp;

    if(this->head== nullptr){
        create(value);

    }else{
        temp = new NodeC;
        temp->data=value;
        this->tail->next=temp;
        temp->next=this->head;
        this->head=temp;

    }

}

void CircularList::insert_at_index(int value, int index) {
        NodeC *temp;
        NodeC *ptr;

        int counter=0;
    if(this->head== nullptr){
        std::cout << "list empty\n";
        return;

    }else{

        ptr=head;
        if(index==0){
            create(value);
            std::cout << "data " <<value<< "added at index " << index<<"\n";
            return;

        }
        while(ptr!=this->tail){
                if(counter==index-1){

                    temp = new NodeC;
                    temp->data=value;
                    temp->next=ptr->next;

                    ptr->next=temp;

                    std::cout << "data " <<value<< "added at index " << index<<"\n";
                    return;


                }
            counter++;
            ptr=ptr->next;
        }

//        if(counter==index-1){
//            temp = new NodeC;
//            temp->data=value;
//            temp->next=ptr->next;
//            ptr->next=temp;
//            this->tail=temp;
//            std::cout << "data " <<value<< "added at index " << index<<"\n";
//
//
//        }


    }


}

void CircularList::delete_element_by_index(int index) {

    NodeC *temp;
    NodeC *ptr;

    int counter=0;
    if(this->head== nullptr){
        std::cout << "list empty\n";
        return;

    }else{

        ptr=this->head;
        if(index==0){
              this->tail->next= this->head->next;
              this->head= this->head->next;
                delete ptr;
            std::cout << "data removed at index " << index<<"\n";
            return;

        }
        while(ptr->next!=this->tail){
            if(counter==index-1){

                temp        =  ptr->next;
                ptr->next   =  ptr->next->next;


                std::cout << "data  removed at index " << index<<"\n";
                return;


            }
            counter++;
            ptr=ptr->next;
        }

        if(counter==index-1){
            temp        =ptr->next;
            ptr->next   =this->tail->next;


            this->tail=ptr;
            delete temp;
            std::cout << "data  removed at index " << index<<"\n";


        }


    }



}

void CircularList::delete_duplicates() {

    NodeC *a=this->head;
    NodeC *b;
    NodeC *c;
    int data;
    if(this->head== nullptr){
        std::cout << "list is empty \n";
        return;
    }else
    while(a != this->tail){
        b=a;
        data=a->data;
        while(b->next!=this->head){

            if(data==b->next->data){

                if(b->next==this->tail){
                    c=b->next;
                    b->next= this->head;
                    delete c;
                    std::cout << "deleted duplicate "<< data<<'\n';
                    b=this->tail;
                }
                else{
                    c=b->next;
                    b->next=b->next->next;
                    delete c;
                    std::cout << "deleted duplicate "<< data<<'\n';

                }
                continue;
            }
            b=b->next;
        }

            a=a->next;
    }
}

void CircularList::append(int value) {
        NodeC *temp;
    if(this->head== nullptr){
        std::cout << "list is empty \n";
        create(value);
        return;
    }else{
        temp=new NodeC;
        temp->data=value;
        temp->next=this->head;
        this->tail->next=temp;
        this->tail=temp;


    }

}

