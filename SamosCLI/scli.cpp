//
// Created by Arif Ahmed on 08/06/22.
//
#include "CoreFunction.h"
#include "DataReader.h"
#include "DataWriter.h"
#include "EntryModel.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


enum CmdType {
  INVALID = 0,
  EXIT = 1,
  ADD_ENTRY = 2,
  DEL_ENTRY = 3,
  SAVE = 4,
  SAVE_DEFAULT = 5,
  LOAD = 6,
  LOAD_DEFAULT = 7,
  HELP = 8,
};

void printWelcome() {
  cout << "Welcome to SAMOS CLI" << endl;
}

CmdType getCmd(string &line, char cmdArgs[MAX_CLI_INPUT_SZ]) {
  size_t cmdSz = line.find(' ');
  if (cmdSz != string::npos) {
    strcpy(cmdArgs, line.substr(cmdSz + 1).c_str());
    line = line.substr(0U, cmdSz);
  }

  //  exit
  if (line == "exit") {
    return EXIT;
  }

  //  add
  if (line == "add") {
    return ADD_ENTRY;
  }

  //  delete
  if (line == "delete") {
    return DEL_ENTRY;
  }

  //  save
  if (line == "save" && strlen(cmdArgs) == 0) {
    return SAVE_DEFAULT;
  }
  if (line == "save") {
    return SAVE;
  }

  //  load
  if (line == "load" && strlen(cmdArgs) == 0) {
    return LOAD_DEFAULT;
  }
  if (line == "load") {
    return LOAD;
  }

  //  help
  if (line == "help") {
    return HELP;
  }

  return INVALID;
}

void op_add_entry(Core &core, char *cmdArgs) {
  char entryString[MAX_ENTRY_BYTES];
  snprintf(entryString, MAX_ENTRY_BYTES, cmdArgs);
  EntryModel entry(entryString);
  core.addEntry(entry);
}

void op_del_entry(Core &core, char *cmdArgs) {}

void op_save_core(Core &core) {
  DataWriter dataWriter("saved_entries.csv", core);
}

void op_load_core(Core &core) {
  DataReader dataReader("saved_entries.csv", core);
}

void op_save_core(Core &core, char *cmdArgs) {
  DataWriter dataWriter(cmdArgs, core);
}

void op_load_core(Core &core, char *cmdArgs) {
  DataReader dataReader(cmdArgs, core);
}

int main() {
  CmdType cmd;
  char cmdArgs[MAX_CLI_INPUT_SZ];
  string inputLine;
  Core core;

  printWelcome();

  while (true) {
    //    cin.clear();
    //    cmdArgs = nullptr;

    cout << ">";

    getline(cin, inputLine);
    cmd = getCmd(inputLine, cmdArgs);

    cout << "command code " << setfill('0') << std::setw(5) << cmd << endl;

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
      case INVALID:
        cout << "\"" << inputLine << "\" is not a valid command" << endl;
        break;
      default:
        return 0;
    }
  }
}
