#include <iostream>
#include "Queue.h"
#include "Node.h"

using namespace std;

Queue::Queue() {
  size = 0;
  head = NULL;
  tail = NULL;
}

Queue::~Queue() {
  destroy(head);
}

void Queue::destroy(Node* current) {
  if(current == NULL) {
    return;
  }
  else if(current->getLeft() != NULL) {
    destroy(current->getLeft());
  }
  delete current;
  current = NULL;
}

void Queue::enqueue(Node* newNode) {
  newNode->setLeft(NULL);
  newNode->setRight(NULL);
  if(tail == NULL) {
    head = newNode;
    tail = newNode;
  }
  else {
    tail->setRight(newNode);
    newNode->setLeft(tail);
    tail = newNode;
  }
  size++;
}

Node* Queue::dequeue() {
  if(head == NULL) {
    return NULL;
  }
  Node* returnNode = head;
  Node* afterHead = head->getRight();
  if(afterHead == NULL) {
    tail = NULL;
  }
  else  {
    afterHead->setLeft(NULL);
  }
  head = afterHead;
  size--;
  return returnNode;
}

Node* Queue::peek() {
  if(head == NULL) {
    return NULL;
  }
  return head;
}

int Queue::length() {
  return size;
}
