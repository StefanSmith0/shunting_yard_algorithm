#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
 public:
  Queue(); //Constructor
  ~Queue(); //Destructor
  void enqueue(Node* newNode); //Adds to the end.
  Node* dequeue(); //Pops from the front.
  Node* peek(); //Returns the front.
  int length(); //Returns the number of elements
 private:
  void destroy(Node* current); //Called by destructor, erases queue.
  int size;
  Node* head;
  Node* tail;
};

#endif
