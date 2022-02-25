#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

class Stack {
  struct data;
 public:
  Stack();
  ~Stack();
  void destroy(data* current);
  char pop();
  void push(char newValue);
  char peek();
private:
  
  struct data {
    char value;
    data* nextData;
  };
  
  int size;
  data* head;
};

#endif
