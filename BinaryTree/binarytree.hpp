#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "node.hpp"

using namespace std;

//2 since binary
int _nop = 2;

class BinaryTree {
	private:
		Node* proot;

	public:
		BinaryTree(const int& e);
		void insert(const int& e);
		void remove(const int& e);
		Node* remove(const int& e, Node* curr);
		void print(Node* curr);
		int cmpElement(const int& e1, const int& e2);
		Node* top();
};

BinaryTree::BinaryTree(const int& e) {
	this->proot = new Node(e, _nop, NULL);
}

void BinaryTree::insert(const int& e) {
	Node* c = this->proot;

	while(c != NULL) {
		if(c->getElement() > e) {
			if(c->getPointer(0) == NULL) {
				Node* temp = new Node(e, _nop, c);
				c->setPointer(0, temp);
				break;
			} else {
				c = c->getPointer(0);
			}
		} else {
			if(c->getPointer(1) == NULL) {
				Node* temp = new Node(e, _nop, c);
				c->setPointer(1, temp);
				break;
			} else {
				c = c->getPointer(1);
			}
		}
	}

	return;
}

void BinaryTree::remove(const int& e) {
	if(this->proot == NULL) {
		return;
	} else if(cmpElement(this->proot->getElement(), e) == 0) {
		Node* temp = this->proot;

		if(this->proot->getPointer(0) != NULL) {
			this->proot = this->proot->getPointer(0);
		} else if(this->proot->getPointer(1) != NULL) {
			this->proot = this->proot->getPointer(1);
		} else {
			this->proot = NULL;
		}

		delete temp;
	} else {
		Node* temp = remove(e, this->proot);
		delete temp;
	}
}	

Node* BinaryTree::remove(const int& e, Node* curr) {
	Node* left = curr->getPointer(0);
	Node* right = curr->getPointer(1);
	
	if(cmpElement(e, curr->getElement()) == 0) {
		if(left != NULL && right != NULL ) {
			curr->setElement(right->minValue());
			return remove(curr->getElement(), curr);
		} else if(curr->getParent()->getPointer(0) == curr) {
			Node* temp = (curr->getPointer(0) != NULL) ? curr->getPointer(0) : curr->getPointer(1);
			curr->getParent()->setPointer(0, temp);
			return curr;
		}  else if(curr->getParent()->getPointer(1) == curr) {
			Node* temp = (curr->getPointer(0) != NULL) ? curr->getPointer(0) : curr->getPointer(1);
			curr->getParent()->setPointer(1, temp);
			return curr;
 		}
	} else {
		if(cmpElement(e, curr->getElement()) < 0) {
			if(curr->getPointer(0) != NULL)
				remove(e, curr->getPointer(0));
			else
				return NULL;
		} else if(cmpElement(e, curr->getElement()) > 0) {
			if(curr->getPointer(1) != NULL)
				remove(e, curr->getPointer(1));
			else
				return NULL;
		}
	}
}

void BinaryTree::print(Node* curr) {
	if(curr != NULL) {
		cout << curr->getElement() << endl;
		if(curr->getPointer(0) != NULL)
			cout << "left" << curr->getPointer(0)->getElement() << endl;
		if(curr->getPointer(1) != NULL)
			cout << "right" << curr->getPointer(1)->getElement() << endl;
	} else {
		return;
	}

	print(curr->getPointer(0));
	print(curr->getPointer(1));
	
	return;
}

int BinaryTree::cmpElement(const int& e1, const int& e2) {
	if(e1 > e2) {
		return 1;
	} else if(e1 < e2) {
		return -1;
	}

	return 0;
}

Node* BinaryTree::top() {
	return this->proot;
}

#endif
