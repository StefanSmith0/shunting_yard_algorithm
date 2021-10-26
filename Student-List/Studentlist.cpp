#include <iostream>
#include <cstring>

using namespace std;

char command[10];
bool stillRunning = true;

void commandID(char command[10]);

struct Student {
  char name[10];
  int id;
  float gpa;
};

int main() {
  while (stillRunning == true) {
    cout << "Command: ";
    cin.getline(command, 10);
    commandID(command);
  }
  return 0;
}

void commandID(char command[10]) {
  if (strcmp(command, "add") == 0) {
    cout << "add: " << endl;
  }
}
