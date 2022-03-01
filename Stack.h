#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"

using namespace std;

class Stack {
 public:
  Stack();
  ~Stack();
  void destroy(Node* current);
  char pop();
  void push(char newValue);
  char peek();
  Node* popNode();
  void pushNode(Node* newNode);
  int length();
private:
  int size;
  Node* head;
};

#endif
