//
// Created by thedushn on 16-May-21.
//

#include "CustomList.h"



CustomList::CustomList() {

   this->tail= nullptr;
   this->head= nullptr;
   this->size=0;
}

void CustomList::Create(int value) {

    Node *temp  =   new Node;

    temp->data  =   value;
    temp->next  =   nullptr;

    if(this->head== nullptr){
        this->head=temp;
        this->tail=temp;
    }else{

        this->tail->next=temp;
        this->tail      =temp;
    }
    this->size++;
    temp        = nullptr;
}

void CustomList::display() {

    Node *temp=this->head;

    while(temp){
        std::cout <<temp->data << '\n';
        temp=temp->next;
    }
    std::cout<<"end of display\n";

}

CustomList::~CustomList() {

    Node *temp;
    while(this->head){
        temp=this->head;
        this->head=temp->next;
        delete temp;


    }
    this->head= nullptr;
    this->tail= nullptr;
    this->size=0;
    std:: cout <<"end\n";

}

void CustomList::prepend(int value) {
    Node *temp= nullptr;
    if(tail== nullptr){
        Create(value);
    }
    else{
        temp= new Node;
        temp->data=value;
        temp->next=this->head;
        this->head=temp;
        this->size++;
    }

}

void CustomList::append(int value) {

    Node *temp= nullptr;
    if(tail== nullptr){
        Create(value);
    }
    else{
        temp= new Node;
        temp->data=value;
        temp->next= nullptr;
        this->tail->next=temp;
        this->tail=temp;
        this->size++;
    }
}

void CustomList::insert(int value, int index) {
        Node *a= nullptr;
        Node *b= nullptr;
        if(index<size){
            if(index==0){
                prepend(value);
                return;
            }
            a=head;
            for(int i=0;i<index-1;i++){
                a=a->next;
            }
            b=new Node;
            b->data=value;
            b->next= a->next;
            a->next=b;
            size++;


        }else if(index>=size){
           append(value);
        }

}

int CustomList::get_size() {
    return this->size;
}

void CustomList::delete_element_by_index(int index) {
    Node *a= nullptr;
    Node *b= nullptr;
    if(head!= nullptr){

        if(index<size){
            if(index==0){
              a=head;
              if(a==tail){
                  tail= nullptr;
              }
              head=head->next;
                delete a;


            }else{
                a=head;
                for(int i=0;i<index-1;i++){
                    a=a->next;
                }
                if(a->next==tail && a->next==head){

                    delete a->next;
                    a->next= nullptr;
                    head= nullptr;
                    tail= nullptr;

                }
                else if(a->next==head){
                    head=head->next;
                    delete a->next;
                    a->next= nullptr;
                }
                else if(a->next==tail){
                    delete a->next;
                    a->next=nullptr;
                    tail= a;
                }
                else{
                    b=a->next;
                    a->next=b->next;
                    delete b;
                    b= nullptr;
                }
            }





            size--;
        }


    }

}

void CustomList::delete_element_by_key(int key) {
    Node *a= nullptr;
    Node *b= nullptr;
    int index=0;
    if(head!= nullptr){
        a=head;
            if(a->data==key){
                delete_element_by_index(0);
                std::cout<<"element deleted \n";
                return ;
            }

            while(a->next){
                if(a->next->data==key){

                    if(a->next==tail && a->next==head){

                        delete a->next;
                        a->next= nullptr;
                        head= nullptr;
                        tail= nullptr;

                    }
                    else if(a->next==head){
                        head=head->next;
                        delete a->next;
                        a->next= nullptr;
                    }
                    else if(a->next==tail){
                        delete a->next;
                        a->next=nullptr;
                        tail= a;
                    }
                    else{
                        b=a->next;
                        a->next=b->next;
                        delete b;
                        b= nullptr;
                    }
                    size--;
                    std::cout <<"element with the key:"<<key<< " "<< "deleted\n";
                   return;
                }
                a=a->next;
            }
        std::cout <<"element with the key:"<<key<< " "<< "not deleted\n";
        std::cout <<"element with the key:"<<key<< " "<< "does not exist in list\n";

    }else{
        std::cout <<"list empty\n";
    }

}

int CustomList::get_size_the_bad_way() {
    Node *temp=this->head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }

    return count;
}

bool CustomList::search(int element) {

    Node *temp=this->head;
    while(temp){

        if(temp->data==element){
            return true;
        }
        temp=temp->next;

    }
    return false;
}

int CustomList::search_num_of_elements(int element) {

    Node *temp=this->head;
    int  count=0;
    while(temp){

        if(temp->data==element){
            count++;
        }
        temp=temp->next;

    }
    return count;

}

void CustomList::remove_duplicate() {

    Node *a=this->head;
    Node *b;
    Node *c= nullptr;
    Node *d= this->head;

    int element=0;
  while(a!= nullptr) {
        element = a->data;
        b = a->next;
        d=a;
        while (b) {

            if (element == b->data) {
                c = b;

                d->next = b->next;


            }

            if (c) {
                if (c->next == nullptr) {
                    this->tail = d;
                }
                delete c;
                c = nullptr;
               break;

            }
            d=b;
            b = b->next;

        }
        if(b== nullptr){
            a=a->next;
        }
    }

}

void CustomList::reverse_list() {
    Node *temp=this->head;
    this->tail=this->head;
    Node *before= nullptr,*after= nullptr;


  while(temp){

        after=temp->next;
        temp->next=before;

        before=temp;
        temp=after;



  }
  this->head=before;




}

void CustomList::segregate_even_odd() {
        Node *temp=this->head;
        Node *temp_2= nullptr;

        while(temp){
            if(temp_2== nullptr){
                if(temp->data!=0){
                    if(temp->data%2!=0){
                        temp_2=temp;

                    }
                }
            }
            else{
                if(temp->data!=0){
                    if(temp->data%2==0){
                        temp->data      =temp->data^temp_2->data;
                        temp_2->data    =temp->data^temp_2->data;
                        temp->data      =temp->data^temp_2->data;

                    temp_2= nullptr;
                    temp=this->head;
                        continue;

                    }
                }
            }


            temp=temp->next;
        }

}
void CustomList::segregate_even_odd_using_p() {
    Node *temp   = this->head;
    Node *temp_2 = nullptr;
    Node *prev   = nullptr;

    while(temp->next){

        if(temp->data!=0){
            if(temp->data%2!=0){
                temp_2=temp;

            }
        }

    }

}




