#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
 public:
  Queue();
  ~Queue();
  void enqueue(Node* newNode);
  Node* dequeue();
  Node* peek();
  int length();
 private:
  void destroy(Node* current);
  int size;
  Node* head;
  Node* tail;
};

#endif
