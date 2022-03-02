#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"

using namespace std;

class Stack {
 public:
  Stack();
  ~Stack();
  Node* peek();
  Node* pop();
  void push(Node* newNode);
  int length();
private:
  void destroy(Node* current);
  int size;
  Node* head;
};

#endif
