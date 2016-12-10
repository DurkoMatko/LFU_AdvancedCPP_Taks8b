#include "LinkedList.h"
#include <cstddef>
#include <iostream>


std::ostream& operator<<(std::ostream& os,LinkedList& list)
{
	list.rewindToHead();

	while(list.hasValue()){
    	os << list.getValue() << std::endl;
    	list.next();
    }
    os << std::endl;
}

//copy assign operator
LinkedList &LinkedList::operator=(LinkedList& list) noexcept{
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
			std::cout << "Copied " << n->x <<std::endl;
			//create next one
			n->next = new Node();

			//move to next one
			list.cur = list.cur->next;
			n = n->next;
		}
		//next one does not exist so just finish copying this node
		n->x = list.cur->x;
		std::cout << "Copied " << n->x <<std::endl;
		n->next == NULL;
		list.rewindToHead();
		rewindToHead();
	}
	return *this;
}

//default constructor
LinkedList::LinkedList(){
	head=NULL;
	cur = NULL;
}


LinkedList::~LinkedList(){
	rewindToHead();
    while(hasValue()){
    	Node *n = cur;
    	cur = cur->next;
    	delete n;
    }
}

//copy constructor
LinkedList::LinkedList(LinkedList& list) noexcept{
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
			std::cout << "Copied " << n->x <<std::endl;
			//create next one
			n->next = new Node();

			//move to next one
			list.cur = list.cur->next;
			n = n->next;
		}
		//next one does not exist so just finish copying this node
		n->x = list.cur->x;
		std::cout << "Copied " << n->x <<std::endl;
		n->next == NULL;
	}
	list.rewindToHead();
}

// append a new value at the beginning of the list
void LinkedList::addHead(int val){
	//create new node
    Node *n = new Node();   
    n->x = val;             
    n->next = head;         
         
    //set head to new node                   
    head = n;   
    cur = head;
}

void LinkedList::addTail(int val){
	//make cursor point to tail of list
	rewindToTail();
	Node *n = new Node();   
    n->x = val;
    n->next = NULL;

    //add to tail
    cur->next = n;

}

// returns the first element in the list and deletes the Node.
int LinkedList::popValue(){
    Node *n = head;
    int ret = n->x;

    //set head to next node
    head = head->next;
    //check if NULL - means empty list 
    if(head == NULL)
    	cur = NULL;

    delete n;
    return ret;
}

void LinkedList::rewindToHead(){
	cur = head;
}

void LinkedList::rewindToTail(){
	//just loop till not at the tail
	while(cur->next != NULL){
		cur = cur->next;
	}
}

bool LinkedList::next(){
	if(cur!=NULL){
		cur = cur->next;
		return true;
	}
	return false;
}

int LinkedList::getValue() const{
	if(cur!=NULL){
		return cur->x;
	}
	return 0;   //should be exception
}

bool LinkedList::hasValue() const{
	return ( cur != NULL ? true : false );
}

void LinkedList::printAndDelete(){
	rewindToHead();
    while(hasValue()){
    	std::cout << popValue() << std::endl;	
    }
}

void LinkedList::addList(LinkedList& list){
	list.rewindToHead();
	while(list.hasValue()){
		addTail(list.popValue());
	}
}