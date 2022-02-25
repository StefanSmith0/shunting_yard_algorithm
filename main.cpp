#include <iostream>
#include <cstring>
#include "Node.h"
#include "Stack.h"

using namespace std;

int main() {
  bool running = true;
  char input[20];
  Stack* stack = new Stack();
  while(running) {
    cout << "Enter command: ";
    cin.getline(input, 20);
    if(!strcmp(input, "quit")) {
      delete stack;
      running = false;
    }
    else if(!strcmp(input, "peek")) {
      char peekValue = stack->peek();
      if(peekValue != '~') {
	cout << "Value at top of stack: " << peekValue << endl;
      }
      else {
	cout << "Stack is empty." << endl;
      }
    }
    else if(!strcmp(input, "push")) {
      char charInput;
      cout << "Value to add to stack: ";
      cin >> charInput;
      stack->push(charInput);
      cin.ignore(10000,'\n');
    }
    else if(!strcmp(input, "pop")) {
      char popValue = stack->pop();
      if(popValue != '~') {
	cout << "Value at top of stack: " << popValue << endl;
      }
      else {
	cout << "Stack is empty." << endl;
      }
    }
  }
  return 0;
}
