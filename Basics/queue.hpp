#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "object.hpp"

class Queue {
 private:
	Object* phead;
	Object* ptail;

 public:
 	bool empty();
 	void push(const string& e);
	void pop();
	Object* top();
	void print();

};

bool Queue::empty() {
 if(this->phead == NULL) {
 	return true;
 }

 return false;
}

void Queue::push(const string& e) {
 if(empty()) {
	this->phead = new Object(e, NULL);
 } else {
 	if(this->ptail == NULL) {
		this->ptail = new Object(e, NULL);
		this->phead->setPrev(this->ptail);
	} else {
	 	Object* temp = new Object(e, NULL);
 		this->ptail->setPrev(temp);
		this->ptail = temp;
	}
 }
}

void Queue::pop() {
 Object* temp = this->phead->getPrev();
 delete this->phead;
 this->phead = temp;
}

Object* Queue::top() {
 return this->phead;
}

void Queue::print() {
 Object* temp = this->phead;

 while(temp != NULL) {
	cout << temp->getElement() << endl;
 	temp = temp->getPrev();
 }
}

#endif
