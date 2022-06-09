//
// Created by Arif Ahmed on 08/06/22.
//
#include "CoreFunction.h"
#include "DataReader.h"
#include "DataWriter.h"
#include "EntryModel.h"
#include "Initializers/RollingFileInitializer.h"
#include "Log.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


enum CmdType {
  INVALID = 0, // 0
  EXIT,        // 1
  ADD_ENTRY,   // 2
  DEL_ENTRY,   // 3
  SAVE,        // 4
  SAVE_DEFAULT,// 5
  LOAD,        // 6
  LOAD_DEFAULT,// 7
  HELP,        // 8
  GET,         // 9
};

void printWelcome() {
  cout << "Welcome to SAMOS CLI" << endl
       << "This tool was developed by Samos and is only meant to be used by its authorized users." << endl
       << "For more information contact Samos Development Team." << endl
       << "    "
       << ">help for help menu" << endl
       << "    "
       << ">exit to exit SCLI" << endl;
}

void printEntryTable(char data[MAX_ENTRY_BYTES]) {
  stringstream dataStream(data);
  string elements[MAX_COLUMNS];
  char word[MAX_ENTRY_DATA_BYTES];

  int numCols = 0;
  for (Uint8 columnIndex = 0; dataStream.getline(word, MAX_ENTRY_DATA_BYTES, ','); columnIndex++) {
    elements[columnIndex] = word;
    numCols++;
  }

  if (elements[3] == "0") {
    elements[3] = "Debit";
  }
  if (elements[3] == "1") {
    elements[3] = "Credit";
  }
  elements[numCols - 1].pop_back();

  cout << "| " << setfill(' ') << setw(40) << left << elements[0]//
       << "| " << setfill(' ') << setw(10) << left << elements[1]//
       << "| " << setfill(' ') << setw(10) << left << elements[2]//
       << "| " << setfill(' ') << setw(18) << left << elements[3]//
       << "| " << setfill(' ') << setw(20) << left << elements[4]//
       << "| " << setfill(' ') << setw(16) << left << elements[5]//
       << "|" << endl;
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

  //  get
  if (line == "get") {
    return GET;
  }

  return INVALID;
}

void op_add_entry(Core &core, char *cmdArgs) {
  EntryModel entry(cmdArgs);
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

void op_get(Core &core, char *cmdArgs) {
  string param(cmdArgs);

  size_t paramSz = param.find(' ');
  if (paramSz != string::npos) {
    strcpy(cmdArgs, param.substr(paramSz + 1).c_str());
    param = param.substr(0U, paramSz);
  } else {
    cmdArgs[0] = '\0';
  }

  // get num
  if (param == "num") {
    // get number of entries
    if (!strcmp(cmdArgs, "entries")) {
      cout << core.getNumEntries() << endl;
    }
  }
  // get total
  if (param == "total") {
    // get total credit
    if (!strcmp(cmdArgs, "credit")) {
      cout << core.getTotalCredit() << endl;
    }
    // get total debit
    if (!strcmp(cmdArgs, "debit")) {
      cout << core.getTotalDebit() << endl;
    }
    // get total amount
    if (!strcmp(cmdArgs, "amount")) {
      cout << int(core.getTotalCredit() - core.getTotalDebit()) << endl;
    }
  }
  // get last
  if (param == "last") {
    // get last entry
    if (!strcmp(cmdArgs, "entry")) {
      if (core.getNumEntries() == 0) {
        cout << "no available entries" << endl;
        return;
      }
      char entryString[MAX_ENTRY_BYTES];
      core.getLastEntry().toStr(entryString);
      printEntryTable("Data,ID,Amount,Transaction Type,Date & Time,Tags");
      printEntryTable(entryString);
    }
  }
}

int cliProc() {
  CmdType cmd;
  char cmdArgs[MAX_CLI_INPUT_SZ];
  string inputLine;
  Core core;

  printWelcome();

  while (true) {
    cmdArgs[0] = '\0';

    printf(">");

    getline(cin, inputLine);
    cmd = getCmd(inputLine, cmdArgs);

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
      case GET:
        op_get(core, cmdArgs);
        break;
      case INVALID:
        cout << "\"" << inputLine << "\" is not a valid command" << endl;
        break;
      default:
        return 0;
    }

    printf("command code %05d\n", cmd);
  }
}

int main() {
  plog::init(plog::debug, "logs.csv");

  return cliProc();
}
