#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

class Object {
 private:
 	string element;
	Object* listPrev;

 public:
 	Object(const string& e, Object* curr);
	void setPrev(Object* n);
	Object* getPrev();
	string getElement();
};

Object::Object(const string& e, Object* curr){
	element = e;
	this->listPrev = curr;
}

void Object::setPrev(Object* n) {
	this->listPrev = n;
}

Object* Object::getPrev() {
	return this->listPrev;
}

string Object::getElement() {
	return this->element;
}

#endif
