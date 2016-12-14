#include "LinkedList.h"
#include <cstddef>
#include <iostream>


template <typename U>
std::ostream& operator<<(std::ostream& os,LinkedList<U>& list)
{
	list.rewindToHead();

	while(list.hasValue()){
    	os << list.getValue() << std::endl;
    	list.next();
    }
    os << std::endl;
}


//copy assign operator
template<typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T>& list) noexcept{
	//if they are not the same objects		
	if(head!=list.head){
		//delete previous contents
		rewindToHead();
		while(hasValue()){
			popValue();
		}

		//prepare linkedList to be copied
		list.rewindToHead();

		//first node = head
		Node *n = new Node();
		head = n;
		cur=head;

		//if next exists
		while(list.cur->next != NULL){
			n->x = list.cur->x;
			//create next one
			n->next = new Node();

			//move to next one
			list.cur = list.cur->next;
			n = n->next;
		}
		//next one does not exist so just finish copying this node
		n->x = list.cur->x;
		n->next == NULL;
		list.rewindToHead();
		rewindToHead();
	}
	return *this;
}



//default constructor
template<typename T>
LinkedList<T>::LinkedList(){
	head=NULL;
	cur = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList(){
	rewindToHead();
    while(hasValue()){
    	Node *n = cur;
    	cur = cur->next;
    	delete n;
    }
}


//copy constructor
template<typename T>
LinkedList<T>::LinkedList(LinkedList& list) noexcept{
	list.rewindToHead();

	if(list.head==NULL){
		head=NULL;
		cur = NULL;
	}
	else{
		//first node == head
		Node *n = new Node();
		head = n;
		cur=head;

		//if next exists
		while(list.cur->next != NULL){
			n->x = list.cur->x;
			//create next one
			n->next = new Node();

			//move to next one
			list.cur = list.cur->next;
			n = n->next;
		}
		//next one does not exist so just finish copying this node
		n->x = list.cur->x;
		n->next == NULL;
	}
	list.rewindToHead();
}

// append a new value at the beginning of the list
template<typename T>
void LinkedList<T>::addHead(T val){
	//create new node
    Node *n = new Node();   
    n->x = val;             
    n->next = head;         
         
    //set head to new node                   
    head = n;   
    cur = head;
}

template<typename T>
void LinkedList<T>::addTail(T val){
	
	//if not empty
	if(hasValue())
		//make cursor point to tail of list
		rewindToTail();

	//create node for value
	Node *n = new Node();   
    n->x = val;
    n->next = NULL;

    //check if not empty list
    if(hasValue()){
	    //add to tail
	    cur->next = n;
	}
	else{
		//if empty, create first node
		head = n;
		cur = head;
	}


}

// returns the value of a head and deletes is + sets the new head
template<typename T>
T LinkedList<T>::popValue(){
    Node *n = head;
    T ret = n->x;

    //set head to next node
    head = head->next;
    cur=head;

    delete n;
    return ret;
}

template<typename T>
void LinkedList<T>::rewindToHead(){
	cur = head;
}

template<typename T>
void LinkedList<T>::rewindToTail(){
	//just loop till not at the tail
	while(cur->next != NULL){
		cur = cur->next;
	}
}

template<typename T>
bool LinkedList<T>::next(){
	if(cur!=NULL){
		cur = cur->next;
		return true;
	}
	return false;
}

template<typename T>
T LinkedList<T>::getValue() const{
	if(cur!=NULL){
		return cur->x;
	}
	return 0;   //should be exception
}

template<typename T>
bool LinkedList<T>::hasValue() const{
	return ( cur != NULL ? true : false );
}

template<typename T>
void LinkedList<T>::printAndDelete(){
	rewindToHead();
    while(hasValue()){
    	std::cout << popValue() << std::endl;	
    }
}

template<typename T>
void LinkedList<T>::addList(LinkedList<T>& list){
	list.rewindToHead();
	while(list.hasValue()){
		addTail(list.popValue());
	}
}

template <typename T> 
template <typename U> 
U LinkedList<T>::getDefaultValueForType(){
	return U();
}