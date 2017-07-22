#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

class Node {
	private:
		Node** pPts;
		Node* pParent;
		int nop;
		int element;
	public:
		Node(const int& e, int nop, Node* curr);
		~Node();
		void setPointer(int n, Node* p);
		void removePointer(int n);
		Node** getPointers();
		Node* getPointer(int n);
		Node* getParent();
		int getElement();
		void setElement(int n);
		int minValue();
};

Node::Node(const int& e, int nop, Node* curr) {
	this->element = e;
	this->nop = nop;
	this->pPts = (Node**)malloc(nop*sizeof(Node*));
	this->pParent = curr;

	for(int i=0;i<this->nop;i++) {
		this->pPts[i] = NULL;
	}
}

Node::~Node() {
	for(int i=0;i<this->nop;i++) {
		if(this->pPts[i] != NULL) {
			this->pPts[i] = NULL;
		}
	}

	free(this->pPts);
}

void Node::setPointer(int n, Node* p) {
	this->pPts[n] = p;
}

Node** Node::getPointers() {
	return this->pPts;
}

Node* Node::getPointer(int n) {
	return this->pPts[n];
}

Node* Node::getParent() {
	return this->pParent;
}

int Node::getElement() {
	return this->element;
}

void Node::setElement(int n) {
	this->element = n;
}

int Node::minValue() {
	if(this->getPointer(0) == NULL) {
		return this->getPointer(0)->getElement();
	} else {
		return this->getPointer(0)->minValue();
	}
}


#endif
