/*
  Stefan Smith
  3/2/2022
  Converts an infix expression into prefix and postfix notation.
 
  Commands:
  quit - Ends the program.
  process - Type an infix expression to start the conversion.
*/

#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Queue.h"

using namespace std;

void shuntYard(char* charArr);
int precedence(Node* inNode);
void makeTree(char input[]);
void printTree(Node* current);
void removeSpace(char input[]);

const int inputSize = 50;

int main() {
  bool running = true;
  char input[inputSize];
  while(running) {
    cout << "Enter command: ";
    cin.getline(input, inputSize);
    if(!strcmp(input, "quit")) {
      running = false;
    }
    else if(!strcmp(input, "process")) {
      char output[inputSize];
      cout << "Infix Expression: ";
      cin.getline(output, inputSize);
      removeSpace(output);
      cout << endl;
      cout << "Infix:   ";
      cout << output << endl;
      shuntYard(output);
      cout << "Prefix:  " << output << endl;
      makeTree(output);
      cout << endl;
    }
  }
  return 0;
}

void removeSpace(char* input) { //removes spaces
  char output[inputSize];
  int outi = 0;
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] != ' ') {
      output[outi] = input[i];
      outi++;
    }
  }
  strcpy(input, output);
}

void shuntYard(char* charArr) { //Shunting algorithm, turns infix into postfix
  Stack* stack = new Stack();
  Queue* queue = new Queue();
  for(int i = 0; i < strlen(charArr); i++) {
    Node* newNode = new Node(charArr[i]);
    if(newNode->getValue() > 47 && newNode->getValue() < 58) { //if it's an integer
      queue->enqueue(newNode);
    }
    else { //operator
      if(newNode->getValue() == 40) { //left parentheses
	stack->push(newNode);
      }
      else if(newNode->getValue() == 41) { //right parentheses
	while(stack->peek() != NULL && stack->peek()->getValue() != 40) {
	  queue->enqueue(stack->pop());
	}
	if(stack->peek() != NULL) {
	  stack->pop(); //pop off the left parentheses
	}
      }
      else {
	while(precedence(newNode) <= precedence(stack->peek())) {
	  queue->enqueue(stack->pop());
	}
	stack->push(newNode);
      }
    }
  }
  while(stack->peek() != NULL) {
    queue->enqueue(stack->pop());
  }
  char output[inputSize];
  int outI = 0;
  for(int i = 0; queue->peek() != NULL; i++) {
    output[i] = queue->dequeue()->getValue();
    outI = i;
  }
  delete stack;
  delete queue;
  strncpy(charArr, output, (outI + 1));
}

void makeTree(char input[]) { //Creates a binary tree for postfix
  Stack* stack = new Stack();
  for(int i = 0; i < strlen(input); i++) {
    Node* newNode = new Node(input[i]);
    if(newNode->getValue() > 47 && newNode->getValue() < 58) { //int
      stack->push(newNode);
    }
    else {
      newNode->setLeft(stack->pop());
      newNode->setRight(stack->pop());
      stack->push(newNode);
    }
  }
  cout << "Postfix: ";
  printTree(stack->pop());
  cout << endl;
}

void printTree(Node* current) { //Prints postfix from binary tree
  if(current == NULL) {
    return;
  }
  cout << current->getValue();
  if(current->getRight() != NULL) {
    printTree(current->getRight());
  }
  if(current->getLeft() != NULL) {
    printTree(current->getLeft());
  } 
}

int precedence(Node* inNode) { //References precedence of operators.
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
