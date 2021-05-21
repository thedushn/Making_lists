//
// Created by thedushn on 18-May-21.
//

#include "DoublyLinked.h"

void DoublyLinked::create(int value) {

    auto *temp =new NodeD;
    temp->data=value;

    if(this->head== nullptr){
        this->head=temp;
        this->head->next= nullptr;
        this->head->prev= nullptr;
        this->tail=temp;

    }else{
        temp->prev=this->tail;
        this->tail->next=temp;
        this->tail=temp;
        temp->next= nullptr;

    }
    size++;


}

DoublyLinked::~DoublyLinked() {
    NodeD *temp;

    while(this->head){
        temp= this->head;
        this->head= this->head->next;
        delete temp;


    }


}

DoublyLinked::DoublyLinked() {

}

void DoublyLinked::dispay() {

    NodeD *temp=this->head;
    if(temp== nullptr)
        std::cout<< "empty list\n";
    while(temp){
        std::cout<< temp->data<<'\n';
        temp= temp->next;
    }
    std::cout<<"end of display\n";
}

void DoublyLinked::append(int value) {


    NodeD *temp;

    if(this->head== nullptr){
        create(value);

    }else{
        temp = new NodeD;
        temp->data=value;
        temp->prev=this->tail;
        this->tail->next=temp;
        this->tail=temp;
        temp->next= nullptr;
        size++;
    }


}

void DoublyLinked::preppend(int value) {

    NodeD *temp;
    if(this->head== nullptr){
        create(value);

    }
    else{
        temp = new NodeD;
        temp->data=value;
        this->head->prev=temp;
        temp->next=this->head;
        this->head=temp;
        this->head->prev= nullptr;
        size++;
    }

}

void DoublyLinked::reverse_dispay() {

    NodeD *temp=this->tail;

    while(temp){
        std::cout<< temp->data<<'\n';
        temp= temp->prev;
    }
    std::cout<< "revese diplay end \n";
}

void DoublyLinked::insert_at_position(int value, int index) {

    NodeD *a;
    NodeD *b;
    int i=0;
    if(index<0){
        std::cout << "index cant be a negative number \n";
        return;
    }
    if(this->head== nullptr){
        std:: cout << "list is empty use other functions\n";
        return;
    }
    else{
        a=this->head;
        if(index==0){
            preppend(value);
            std::cout << "node added\n";
            return;
        }
        while(a){
            if(i==index){
                if(a==this->tail){
                    append(value);
                    std::cout << "node added\n";
                    break;
                }
                b=new NodeD;
                b->data= value;
                b->prev=a->prev;
                a->prev->next=b;
                b->next=a;
                std::cout << "node added\n";
                size++;
                break;
            }

            a=a->next;
            i++;
        }
    }

}

void DoublyLinked::insert_before_index(int value, int index) {

    NodeD *a;
    NodeD *b;
    int i=0;
    if(index<0){
        std::cout << "index cant be a negative number \n";
    }
    if(this->head== nullptr){
        std::cout << "list is empty \n";
        return;
    }else{

        a=this->head;
        if(index==0){
            preppend(value);
            return;
        }
        while(a){
            if(i==index){
                b=new NodeD;
                b->data= value;
                b->prev=a->prev;
                a->prev->next=b;
                b->next=a;
                std::cout << "node added\n";
                size++;
                return;
            }
            a=a->next;
            i++;
        }
        std::cout<< "node not added index to big for the list size\n";

    }

}

void DoublyLinked::remove_from_list_by_index(int index) {
    NodeD *a;
    NodeD *b;
    int i=0;
    if(index<0){
        std::cout << "index cant be a negative number \n";
    }
    if(this->head== nullptr){
        std::cout << "list is empty \n";
        return;
    }else{

        a=this->head;
        if(index==0){
            this->head=this->head->next;
            a->next= nullptr;
            if(this->tail==a){
                this->tail= nullptr;
            }

            if(this->head!= nullptr)
                this->head->prev= nullptr;

            delete a;
            size--;
            std::cout<< "node removed at index" << index<<'\n';
            return;
        }

        while(a){
            if(i==index){
                b=a->prev;
                b->next=a->next;
                if(a==this->tail){
                    this->tail=b;
                }else{
                    a->next->prev=b;
                }

                delete a;
                size--;

                return;
            }
            a=a->next;
            i++;
        }
        std::cout<< "node not removed index to big for the list size\n";

    }

}

void DoublyLinked::remove_from_list_by_key(int key) {
    NodeD *a;
    NodeD *b;
    if(this->head== nullptr){
        std::cout << "list is empty \n";
        return;
    }else{

        a=this->head;


        while(a){

            if(key==a->data){
                if(a==this->head){
                    this->head=this->head->next;

                    if(this->tail==a){
                        this->tail= nullptr;
                    }

                    if(this->head!= nullptr)
                        this->head->prev= nullptr;

                    delete a;
                    a= this->head;
                    size--;
                    std::cout<< "node removed with key " << key<<'\n';
                    continue;
                }else{
                    b=a->prev;
                    b->next=a->next;
                    if(a==this->tail){
                        this->tail=b;
                    }else{
                        a->next->prev=b;
                    }
                }


                delete a;
                size--;
                a=b;
                std::cout<< "node removed with key " << key<<'\n';
            }
            a=a->next;

        }


    }

}

void DoublyLinked::remove_from_list_by_pointer(NodeD *p) {

    NodeD *a;
    NodeD *b;
    if(this->head== nullptr || p== nullptr){
        std::cout << "list is empty or pointer is null\n";
        return;
    }else{

        a=this->head;


        while(a){

            if(p==a){
                if(a==this->head){
                    this->head=this->head->next;
                    if(this->tail==a){
                        this->tail= nullptr;
                    }
                    if(this->head!= nullptr)
                        this->head->prev= nullptr;

                    delete a;

                    size--;
                    std::cout<< "node removed with pointer " << p<<'\n';
                   break;
                }else{
                    b=a->prev;
                    b->next=a->next;
                    if(a==this->tail){
                        this->tail=b;
                    }else{
                        a->next->prev=b;
                    }
                }


                delete a;
                size--;

                std::cout<< "node removed with key " << p<<'\n';
                break;
            }
            a=a->next;

        }


    }


}

NodeD *DoublyLinked::getHead() const {
    return this->head;
}

NodeD *DoublyLinked::getTail() const {
    return this->tail;
}

int DoublyLinked::getSize() const {
    return this->size;
}

void DoublyLinked::remove_from_list_if_duplicate() {

    NodeD *a;
    NodeD *b;
    NodeD *c;
    int data=0;
    if(this->head== nullptr){
        std::cout << "list is empty \n";
        return;
    }else{
        c=this->head;
       while(c){
           data=c->data;
            a=c->next;
           while(a){

               if(data==a->data){
                   if(a==this->head){
                       this->head=this->head->next;

                       if(this->tail==a){
                           this->tail= nullptr;
                       }

                       if(this->head!= nullptr)
                           this->head->prev= nullptr;

                       delete a;
                       a= this->head;
                       size--;
                       std::cout<< "node removed with data " << data<<'\n';
                       continue;
                   }else{
                       b=a->prev;
                       b->next=a->next;
                       if(a==this->tail){
                           this->tail=b;
                       }else{
                           a->next->prev=b;
                       }
                   }


                   delete a;
                   size--;
                   a=b;
                   std::cout<< "node removed with data "<< data<<'\n';
               }
               a=a->next;

           }
           c=c->next;
       }




    }
}

void DoublyLinked::find_size() {
    NodeD *temp=this->head;
    int i=0;
    while(temp){
        i++;
        temp=  temp->next;
    }
    std::cout << "Number of elements in a list "<<i<<'\n';
}

void DoublyLinked::reverse_array() {
    NodeD *a=this->head;
    NodeD *b= nullptr;
    NodeD *c=this->head;
    NodeD *d=this->tail;

    if(this->head== nullptr){
        std::cout << "list is empty \n";
        return;
    }
    while(a){
        b=a->prev;
        a->prev=a->next;
        a->next=b;
        a=a->prev;
    }
        //if we didnt know tail;
        /*
         * if(b){
         * this->head=b->prev;
         * }
         * */
    this->tail=c;
    this->head=d;

}
