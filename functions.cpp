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
  cout << "\n- ";

  cin >> sortingChoice;

  int howManyCountries(0);

  if (sortingChoice == 1) {
    cout << "How many countries? (1 - 10)" << endl;
    cin >> howManyCountries;
    sortByPopulation(howManyCountries);

  } else if (sortingChoice == 2) {
    cout << "How many countries? (1 - 10)" << endl;
    cin >> howManyCountries;
    sortByArea(howManyCountries);

  } else if (sortingChoice == 3) {
    cout << "How many countries? (1 - 10)" << endl;
    cin >> howManyCountries;
    sortByPopDensity(howManyCountries);

  } else if (sortingChoice == 4) {
    cout << "How many countries? (1 - 10)" << endl;
    cin >> howManyCountries;
    sortByNetMigration(howManyCountries);

  } else if (sortingChoice == 5) {
    cout << "How many countries? (1 - 10)" << endl;
    cin >> howManyCountries;
    sortByGDP(howManyCountries);

  } else if (sortingChoice == 6) {
    cout << "How many countries? (1 - 10)" << endl;
    cin >> howManyCountries;
    sortByLiteracy(howManyCountries);

  } else if (sortingChoice == 7) {
    cout << "How many countries? (1 - 10)" << endl;
    cin >> howManyCountries;
    sortByBirthRate(howManyCountries);

  } else if (sortingChoice == 0) {
    //nothing happens so program ends
  }
}

void sortByPopulation(const vector<Country>& countryList) {

  sort(countryList.begin(), v.end(), greater<int>());

}

void sortByArea(int howManyCountries);

void sortByPopDensity(int howManyCountries);

void sortByNetMigration(int howManyCountries);

void sortByGDP(int howManyCountries);

void sortByLiteracy(int howManyCountries);

void sortByBirthRate(int howManyCountries);