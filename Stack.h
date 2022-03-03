#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"

using namespace std;

class Stack {
 public:
  Stack(); //Constructor
  ~Stack(); //Destructor
  Node* peek(); //Returns Node at the top of the stack.
  Node* pop(); //Returns top of stack, removes it.
  void push(Node* newNode); //Adds to the top.
  int length(); //Returns how many elements are in it.
private:
  void destroy(Node* current); //Called by destructor, erases stack.
  int size;
  Node* head;
};

#endif
