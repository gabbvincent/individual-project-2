#include "functions.h"

void dataViewer() {

  clearScreen();

  cout << "[ WELCOME TO THE COUNTRY DATA VIEWER ]" << endl;
  
  cout << "\n - Press the ENTER key to continue - ";
  if (cin.get() == '\n') {
    clearScreen();
  } 

  sortingOptions();


}

void clearScreen() {
  cout << "\033[2J\033[1;1H";
}

void sortingOptions() {

  int sortingChoice(0);

  cout << "View countries by..." << endl;

  cout << "\n1. population" << endl;
  cout << "2. area (square miles)" << endl;
  cout << "3. population density (per square mile)" << endl;
  cout << "4. net migration rate (per 1000)" << endl;
  cout << "5. percapita GDP ($ per capita)" << endl;
  cout << "6. literacy (%)" << endl;
  cout << "7. birthrate (per 1000)" << endl;
  cout << "0. EXIT program" << endl; 
  cout << "\n-";

  cin >> sortingChoice;



}