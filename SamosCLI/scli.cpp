//
// Created by Arif Ahmed on 08/06/22.
//
#include "Initializers/RollingFileInitializer.h"
#include "Log.h"
#include "Utilities.h"
#include "iostream"

using namespace std;


void printWelcome() {
  cout << "Welcome to SAMOS CLI" << endl;
}

int main() {
  printWelcome();

  while (1) {
    char inputLine[MAX_CLI_INPUT_SZ];
    cin.getline(inputLine, MAX_CLI_INPUT_SZ);
    if (!strcmp(inputLine, "exit")) {
      break;
    }
    cout << inputLine << endl;
  }
}
