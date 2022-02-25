#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

class Queue {
  struct data;
 public:
  Queue();
  ~Queue();
  void destroy(data* current);
  void enqueue(char newValue);
  char dequeue();
  char peek();
 private:
  struct data {
    char value;
    data* prevData;
    data* nextData;
  };
  int size;
  data* head;
  data* tail;
};

#endif