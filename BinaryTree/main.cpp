#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "binarytree.hpp"

using namespace std;

void test1() {
 int n = 0;
 ifstream exfile("test1.txt");

 if(exfile.is_open()) {
  BinaryTree* t = new BinaryTree(n);

  while(exfile >> n) {
  	t->insert(n);
  }

  t->print(t->top());
  exfile.close();
 }
}

void test2() {
 int n = 0;
 ifstream exfile("test2.txt");

 if(exfile.is_open()) {
  BinaryTree* t = new BinaryTree(n);

  while(exfile >> n) {
  	t->insert(n);
  }

  t->print(t->top());
  exfile.close();
 }
}

void test3() {
 int n = 0;
 ifstream exfile("test2.txt");
                                    
 if(exfile.is_open()) {
  BinaryTree* t = new BinaryTree(n);
                                    
  while(exfile >> n) {
  	t->insert(n);
  }

  exfile.close();

  t->remove(1, t->top());
  t->print(t->top());
 }
}

void test4() {
 int n = 0;
 ifstream exfile("test2.txt");
                                    
 if(exfile.is_open()) {
  BinaryTree* t = new BinaryTree(n);
                                    
  while(exfile >> n) {
  	t->insert(n);
  }

  exfile.close();

  t->remove(10, t->top());
  t->print(t->top());
 }
}

int main() {
 test1();
 test2();
 test3();
 test4();
 return 0;
}
