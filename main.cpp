#include <iostream>
#include "CustomList.h"
using namespace std;
int main() {
    {

        CustomList c1;
        c1.Create(2);
        cout << "number of elements is "<<c1.get_size_the_bad_way()<<"\n";
        c1.delete_element_by_index(0);
        c1.display();
        c1.Create(5);
        c1.Create(3);
        c1.prepend(44);
        c1.prepend(44);
        c1.Create(3);
        c1.Create(3);
        c1.Create(3);

        c1.append(44);
        c1.Create(3);
        cout <<" Search :" <<(c1.search(44)? ("true"):("false"))<<'\n';

        cout <<" Search how many elements are in the array :" <<(c1.search_num_of_elements(44))<<'\n';
        c1.display();
        c1.remove_duplicate();
        cout <<" Search how many elements are in the array :" <<(c1.search_num_of_elements(44))<<'\n';
        c1.display();
        c1.append(77);
        c1.insert(4456342,3);
        c1.insert(444555555,c1.get_size());
        c1.insert(0,0);
        cout << "number of elements is "<<c1.get_size_the_bad_way()<<"\n";
        c1.display();
        cout <<"reverse \n";
        c1.reverse_list();
        c1.display();
        c1.delete_element_by_key(0);
        c1.display();
        c1.delete_element_by_key(4456342);
        c1.display();
        c1.delete_element_by_key(11111);
        c1.delete_element_by_key(77);
        c1.delete_element_by_key(444555555);
        cout << "number of elements is "<<c1.get_size_the_bad_way()<<"\n";
        c1.display();
        c1.Create(2);
        c1.Create(1);
        c1.Create(5);
        c1.Create(4);
        c1.display();
        c1.segregate_even_odd();
        c1.display();


    }

    return 0;
}
