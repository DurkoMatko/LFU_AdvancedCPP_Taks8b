#include <iostream>
#include <iterator>
#include <algorithm>
#include "LinkedList.cpp"

void createLists(){

}


int main() {
    LinkedList list;
    list.addHead(5);
    list.addHead(10);
    list.addHead(20);

    LinkedList list2;
    list2.addHead(100);
    list2.addHead(200);
    list2.addHead(300);

    std::cout << list << std::endl;

    LinkedList list3(list);

    list3.printAndDelete();

    LinkedList list4;
    list4=list2;
    list4.addList(list);
    std::cout << list4 << std::endl;

    return 0;
}