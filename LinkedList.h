#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

//template<typename InputIterator, class T>
class LinkedList{

	struct Node {
        int x;
        Node *next;
    };

	public:
		LinkedList();
		LinkedList(LinkedList& list) noexcept;   //copy constructor
		~LinkedList();
		void addHead(int val);
		void addTail(int val);
		int popValue();
		void rewindToHead();
		void rewindToTail();
		bool next();
		int getValue() const;
		bool hasValue() const;
		void printAndDelete();
		void addList(LinkedList& list);

		friend std::ostream& operator<<(std::ostream& os, LinkedList& g);	//needs to be friend cuz it's defined outside of class and needs to access ajacencyList
		LinkedList& operator=(LinkedList& list) noexcept;
	private:
		Node *head;
		Node *cur;
};

#endif //LINKEDLIST_H