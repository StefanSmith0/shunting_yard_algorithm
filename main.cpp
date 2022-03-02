#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

using namespace std;

void shuntYard(char* charArr);
int precedence(Node* inNode);
void makeTree(char input[]);
void printTree(Node* current);

int main() {
  bool running = true;
  char input[20];
  while(running) {
    cout << "Enter command: ";
    cin.getline(input, 20);
    if(!strcmp(input, "quit")) {
      running = false;
    }
    else if(!strcmp(input, "process")) {
      char output[20];
      cout << "Equation: " << endl;
      cin.getline(output, 20);
      shuntYard(output);
      cout << output << endl;
      makeTree(output);
    }
  }
  return 0;
}

void shuntYard(char* charArr) {
  Stack* stack = new Stack();
  Queue* queue = new Queue();
  for(int i; i < strlen(charArr); i++) {
    Node* newNode = new Node(charArr[i]);
    if(newNode->getValue() > 47 && newNode->getValue() < 58) { //if it's an integer
      queue->enqueue(newNode);
    }
    else { //operator
      while(precedence(newNode) <= precedence(stack->peek())) {
	queue->enqueue(stack->pop());
      }
      stack->push(newNode);
    }
  }
  while(stack->peek() != NULL) {
    queue->enqueue(stack->pop());
  }
  char output[20];
  int i = 0;
  while(queue->peek() != NULL) {
    output[i] = queue->dequeue()->getValue();
    i++;
  }
  delete stack;
  delete queue;
  strcpy(charArr, output);
}

void makeTree(char input[]) {
  Stack* stack = new Stack();
  for(int i = 0; i < strlen(input); i++) {
    Node* newNode = new Node(input[i]);
    if(newNode->getValue() > 47 && newNode->getValue() < 58) { //int
      stack->push(newNode);
    }
    else {
      cout << newNode->getValue() << " left set to " << stack->peek()->getValue() << endl;
      newNode->setLeft(stack->pop());
      cout << newNode->getValue() << " right set to " << stack->peek()->getValue() << endl;
      newNode->setRight(stack->pop());
      stack->push(newNode);
    }
  }
  printTree(stack->pop());
}

void printTree(Node* current) {
  cout << "Top of printTree" << endl;
  if(current == NULL) {
    return;
  }
  if(current->getLeft() != NULL) {
    cout << "Into left..." << endl;
    printTree(current->getLeft());
  }
  if(current->getRight() != NULL) {
    cout << "Into right..." << endl;
    printTree(current->getRight());
  }
  cout << "Node: " << current->getValue() << endl;
}

int precedence(Node* inNode) {
  if(inNode == NULL) {
    return 1;
  }
  int output = 1;
  char input = inNode->getValue();
  if(input == '^') {
    output = 4;
  }
  else if(input == '*') {
    output = 3;
  }
  else if(input == '/') {
    output = 3;
  }
  else if(input == '+') {
    output = 2;
  }
  else if(input == '-') {
    output = 2;
  }
  return output;
}
