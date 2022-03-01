#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

using namespace std;

void shuntYard(char* charArr);
int precedence(char input);

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
    }
  }
  return 0;
}

void shuntYard(char* charArr) {
  Stack* stack = new Stack();
  Queue* queue = new Queue();
  for(int i; i < strlen(charArr); i++) {
    if(charArr[i] > 47 && charArr[i] < 58) { //if it's an integer
      queue->enqueue(charArr[i]);
    }
    else { //operator
      while(precedence(charArr[i]) <= precedence(stack->peek())) {
	queue->enqueue(stack->pop());
      }
      stack->push(charArr[i]);
    }
  }
  while(stack->peek() != '~') {
    queue->enqueue(stack->pop());
  }
  char output[20];
  int i = 0;
  while(queue->peek() != '~') {
    output[i] = queue->dequeue();
    i++;
  }
  delete stack;
  delete queue;
  strcpy(charArr, output);
}

void makeTree(char[] input) {
  Stack* stack = new Stack();
  for(int i; i < strlen(input); i++) {
    Node* newNode = new Node(input[i]);
    if(newNode->getValue() > 47 && newNode->getValue() < 58) { //int
      stack->pushNode(newNode);
    }
  }
}

int precedence(char input) {
  int output = 1;
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
