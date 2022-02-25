#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
  size = 0;
  head = NULL;
  tail = NULL;
}

Queue::~Queue() {
  destroy(head);
}

void Queue::destroy(data* current) {
  if(current == NULL) {
    return;
  }
  else if(current->nextData != NULL) {
    destroy(current->nextData);
  }
  delete current;
  current = NULL;
}

void Queue::enqueue(char newValue) {
  data* newData = new data;
  newData->value = newValue;
  newData->prevData = NULL;
  newData->nextData = NULL;
  if(tail == NULL) {
    head = newData;
    tail = newData;
  }
  else {
    tail->nextData = newData;
    newData->prevData = tail;
    tail = newData;
  }
  size++;
}

char Queue::dequeue() {
  if(head == NULL) {
    return '~';
  }
  char returnChar = head->value;
  data* afterHead = head->nextData;
  delete head;
  if(afterHead == NULL) {
    tail = NULL;
  }
  else  {
    afterHead->prevData = NULL;
  }
  head = afterHead;
  return returnChar;
  size--;
}

char Queue::peek() {
  if(head == NULL) {
    return '~';
  }
  return head->value;
}
