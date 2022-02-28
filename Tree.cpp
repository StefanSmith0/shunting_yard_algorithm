#include <iostream>
#include "Tree.h"
#include "Stack.h"
#include <cstring>

using namespace std;

Tree::Tree() {
  size = 0;
  head = NULL;
  root = NULL;
}

Tree::~Tree() {
  destroy(head);
}

void Tree::push(char input[]) {
  Stack* stack = new Stack();
  for(int i; i < strlen(input); i++) {
    if(input[i] > 47 && input[i] < 58) { //if it's an integer
      stack->push(input[i]);
    }
    else {
      Node* newNode = new Node(input[i]);
      if(stack->pop() != '~') {
	Node* newLeft = new Node(stack->pop());
	newNode->setLeft(newLeft);
      }
      if(stack->pop() != '~') {
	Node* newRight = new Node(stack->pop());
	newNode->setRight(newRight);
      }
    }
  }
}

void Tree::destroy(Node* current) {
  if(current == NULL) {
    return;
  }
  else if(current->getLeft() != NULL) {
    destroy(current->getLeft());
  }
  else if(current->getRight() != NULL) {
    destroy(current->getRight());
  }
  delete current;
  current = NULL;
}
