#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstring>
#include "object.hpp"

using namespace std;

class Stack {
 private:
 	Object* curr;

 public:
 	bool empty();
	void push(const string& e);
	void pop();
	Object* top();
	void print();
};

bool Stack::empty() {
 if(this->curr == NULL) {
 	return true;
 }

 return false;
}

void Stack::push(const string& e) {
 if(empty()) {
  this->curr = new Object(e, NULL);
 } else {
  Object* temp = new Object(e, this->curr);
  this->curr = temp;
 }
}

void Stack::pop() {
 if(empty()) {
  return;
 } else {
  Object* temp = this->curr->getPrev();
  delete this->curr;
  this->curr = temp;
 }
}

Object* Stack::top() {
 return this->curr;
}

void Stack::print() {
 Object* temp = this->curr;

 while(temp) {
 	cout << temp->getElement() << endl;
	temp = temp->getPrev();
 }
}

#endif
