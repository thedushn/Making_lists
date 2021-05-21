#include <iostream>
#include "CustomList.h"
#include "DoublyLinked.h"

#include "CircularList.h"

using namespace std;
int main() {


        CircularList c1;

        c1.create(1);
        c1.create(2);
        c1.create(3);
        c1.create(3);
        c1.create(3);
        c1.create(3);
        c1.display();

        c1.insert_at_index(5,5);
        c1.insert_at_index(5,5);
        c1.insert_at_index(5,5);
        c1.insert_at_index(5,5);
        c1.delete_duplicates();
        c1.display();





    return 0;
}
