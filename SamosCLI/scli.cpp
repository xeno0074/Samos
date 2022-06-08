//
// Created by Arif Ahmed on 08/06/22.
//
#include "CoreFunction.h"
#include "DataReader.h"
#include "DataWriter.h"
#include "EntryModel.h"
#include "Utilities.h"
#include <cstring>
#include <iostream>

using namespace std;


enum CmdType {
  OTHER = 0,
  EXIT,
  ADD_ENTRY,
  DEL_ENTRY,
  SAVE,
  SAVE_DEFAULT,
  LOAD,
  LOAD_DEFAULT,
  HELP,
};

void printWelcome() {
  cout << "Welcome to SAMOS CLI" << endl;
}

CmdType parseLine(char line[MAX_CLI_INPUT_SZ], char *&cmdArgs) {
  const char delimiter = ' ';
  char *token;
  token = strtok_s(line, &delimiter, &cmdArgs);

  //  exit
  if (!strcmp(token, "exit")) {
    return EXIT;
  }

  //  add
  if (!strcmp(token, "add")) {
    return ADD_ENTRY;
  }

  //  delete
  if (!strcmp(token, "delete")) {
    return DEL_ENTRY;
  }

  //  save
  if (!strcmp(token, "save") && strlen(cmdArgs) == 0) {
    return SAVE_DEFAULT;
  }
  if (!strcmp(token, "save")) {
    return SAVE;
  }

  //  load
  if (!strcmp(token, "load") && strlen(cmdArgs) == 0) {
    return LOAD_DEFAULT;
  }
  if (!strcmp(token, "load")) {
    return LOAD;
  }

  //  help
  if (!strcmp(token, "help")) {
    return HELP;
  }
  return OTHER;
}

void op_add_entry(Core &core, char *&cmdArgs) {
  char entryString[MAX_ENTRY_BYTES];
  strcpy_s(entryString, MAX_ENTRY_BYTES, cmdArgs);
  EntryModel entry(entryString);
  core.addEntry(entry);
}

void op_del_entry(Core &core, char *&cmdArgs) {}

void op_save_core(Core &core) {
  DataWriter dataWriter("saved_entries.csv", core);
}

void op_load_core(Core &core) {
  DataReader dataReader("saved_entries.csv", core);
}

void op_save_core(Core &core, char *&cmdArgs) {
  DataWriter dataWriter(cmdArgs, core);
}

void op_load_core(Core &core, char *&cmdArgs) {
  DataReader dataReader(cmdArgs, core);
}

int main() {
  CmdType cmd;
  char *cmdArgs;
  char inputLine[MAX_CLI_INPUT_SZ];
  Core core;

  printWelcome();

  while (true) {
    cin.clear();
    cmdArgs = nullptr;

    printf(">");

    cin.getline(inputLine, MAX_CLI_INPUT_SZ);
    cmd = parseLine(inputLine, cmdArgs);

    printf("command code %06d\n", cmd);

    switch (cmd) {
      case EXIT:
        return 0;
      case ADD_ENTRY:
        op_add_entry(core, cmdArgs);
        break;
      case DEL_ENTRY:
        op_del_entry(core, cmdArgs);
        break;
      case SAVE_DEFAULT:
        op_save_core(core);
        break;
      case LOAD_DEFAULT:
        op_load_core(core);
        break;
      case SAVE:
        op_save_core(core, cmdArgs);
        break;
      case LOAD:
        op_load_core(core, cmdArgs);
        break;
      case OTHER:
        printf("\"%s\" is an invalid command\n", inputLine);
        break;
      default:
        return 0;
    }
  }
}
