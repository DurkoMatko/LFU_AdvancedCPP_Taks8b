#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include "LinkedList.cpp"

void testInts(){
	LinkedList<int> list;
    list.addHead(5);
    list.addHead(10);
    list.addHead(20);

    LinkedList<int> list2;
    list2.addHead(100);
    list2.addHead(200);
    list2.addHead(300);

    std::cout << list << std::endl;

    LinkedList<int> list3(list);

    list3.printAndDelete();

    LinkedList<int> list4;
    list4=list2;
    list4.addList(list);
    std::cout << list4 << std::endl;
}

void testStrings(){
	LinkedList<std::string> list;
    list.addTail("hey");
    list.addTail("hello");
    list.addTail("world");

    LinkedList<std::string> list2;
    list2.addTail("this");
    list2.addTail("is");
    list2.addTail("test");

    std::cout << list << std::endl;

    LinkedList<std::string> list3(list);

    list3.printAndDelete();

    LinkedList<std::string> list4;
    list4=list2;
    list4.addList(list);
    std::cout << list4 << std::endl;

}



int main() {
    testInts();
    testStrings();

    std::cout << "Returned default value from static member: " << LinkedList<std::string>::getDefaultValueForType<int>() << std::endl;Im 
    return 0;
}