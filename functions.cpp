#include "functions.h"

void dataViewer() {

  cout << string(4, '\n');

  cout << "[ WELCOME TO THE COUNTRY DATA VIEWER ]" << endl;
  
  cout << "\n - Press the ENTER key to continue - ";
  if (cin.get() == '\n') {
    clearScreen();
  }


}

void clearScreen() {
  cout << "\033[2J\033[1;1H";
}