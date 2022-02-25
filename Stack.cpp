#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
  size = 0;
  head = NULL;
}

Stack::~Stack() {
  destroy(head);
}

void Stack::destroy(data* current) {
  if(current == NULL) {
    return;
  }
  else if(current->nextData != NULL) {
    destroy(current->nextData);
  }
  delete current;
  current = NULL;
}

char Stack::pop() {
  if(head == NULL) {
    return '~';
  }
  char returnChar = head->value;
  data* afterHead = head->nextData;
  delete head;
  head = afterHead;
  return returnChar;
  size--;
}

void Stack::push(char newValue) {
  data newData = {newValue, NULL};
  data* newPtr = &newData;
  data* tempHead = head;
  head = newPtr;
  newPtr->nextData = tempHead;
  size++;
}

char Stack::peek() {
  if(head == NULL) {
    return '~';
  }
  return head->value;
}
