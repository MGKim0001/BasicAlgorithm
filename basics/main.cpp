#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "stack.hpp"
#include "queue.hpp"

using namespace std;

double getTime(timespec s, timespec f) {
 double elapsed;
 elapsed = (f.tv_sec - s.tv_sec);
 elapsed += (f.tv_nsec - s.tv_nsec) / 1000000000.0;

 cout << elapsed << endl;
}

void testStack() {
 string line;
 ifstream myfile1("example.txt");

 Stack* s = new Stack();

 struct timespec start, finish;
 clock_gettime(CLOCK_MONOTONIC, &start);

 if(myfile1.is_open()) {
  while(getline(myfile1, line)) {
   s->push(line);
  }

  myfile1.close();
 }

 s->print();

 clock_gettime(CLOCK_MONOTONIC, &finish);
 getTime(start, finish);
}

void testQueue() {
 string line;
 ifstream myfile2("example.txt");

 Queue* q = new Queue();

 struct timespec start, finish;
 clock_gettime(CLOCK_MONOTONIC, &start);

 if(myfile2.is_open()) {
  while(getline(myfile2, line)) {
   q->push(line);
  }

  myfile2.close();
 }

 q->print();

 clock_gettime(CLOCK_MONOTONIC, &finish);
 getTime(start, finish);
}

int main()
{
 int option;
 cout << "test options: 1-stack, 2-queue" << endl;
 cin >> option;
 
 switch(option) {
 	case 1:
		testStack();
		break;
	case 2:
 		testQueue();
		break;
 }

 return 0;
}

