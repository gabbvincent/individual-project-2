#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using namespace std;


struct Country {
  string name;
  int population;
  int area;
  double popDensity;
  double netMigration;
  int GDP;
  double literacy;
  double birthRate;
};

    const int name_width = 23 ;
    const int int_width = 11 ;
    const int dbl_width = 9 ;
    const int num_flds = 7 ;
    const std::string sep = " |" ;
    const int total_width = name_width*2 + int_width*2 + dbl_width*3 + sep.size() * num_flds ;
    const std::string line = sep + std::string( total_width-2, '-' ) + '|' ;

    void header() {
      cout << line << '\n' << sep
        << std::setw(name_width) << "COUNTRY" << sep << std::setw(int_width) << "POPULATION" << sep
        << std::setw(int_width) << "AREA" << sep
        << std::setw(dbl_width) << "POP DENS" << sep << std::setw(dbl_width) << "NET MIG" << sep
        << std::setw(int_width) << "GDP" << sep << std::setw(dbl_width) << "LITERACY" << sep
        << std::setw(dbl_width) << "BIRTH RT" << sep << '\n' << line << '\n' ;
    }

void printItemList(Country c) {
  cout << sep << std::setw(name_width) << c.name << sep << std::setw(int_width) << c.population << sep
       << std::setw(int_width) << c.area << sep
       << std::fixed << std::setprecision(2)
       << std::setw(dbl_width) << c.popDensity << sep << std::setw(dbl_width) << c.netMigration << sep
       << std::setw(int_width) << c.GDP << sep << std::setw(dbl_width) << c.literacy << sep
       << std::setw(dbl_width) << c.birthRate << sep << '\n' ;
}

void clearScreen() {
  cout << "\033[2J\033[1;1H";
}

bool sortByMostPopulous(const Country& x, const Country& y) { 
  return x.population > y.population; 
}

bool sortByLeastPopulous(const Country& x, const Country& y) { 
  return x.population < y.population; 
}

bool sortByMostArea(const Country& x, const Country& y) { 
  return x.area > y.area; 
}

bool sortByLeastArea(const Country& x, const Country& y) { 
  return x.area < y.area; 
}

bool sortByMostPopDensity(const Country& x, const Country& y) { 
  return x.popDensity > y.popDensity; 
}

bool sortByLeastPopDensity(const Country& x, const Country& y) { 
  return x.popDensity < y.popDensity; 
}

bool sortByMostNetMigration(const Country& x, const Country& y) { 
  return x.netMigration > y.netMigration; 
}

bool sortByLeastNetMigration(const Country& x, const Country& y) { 
  return x.netMigration < y.netMigration; 
}

bool sortByMostGDP(const Country& x, const Country& y) { 
  return x.netMigration > y.netMigration; 
}

bool sortByLeastGDP(const Country& x, const Country& y) { 
  return x.GDP < y.GDP; 
}

bool sortByMostLiteracy(const Country& x, const Country& y) { 
  return x.netMigration > y.netMigration; 
}

bool sortByLeastLiteracy(const Country& x, const Country& y) { 
  return x.literacy < y.literacy; 
}

bool sortByMostBirthRate(const Country& x, const Country& y) { 
  return x.netMigration > y.netMigration; 
}

bool sortByLeastBirthRate(const Country& x, const Country& y) {
  return x.birthRate < y.birthRate; 
}



int main() {

    const int name_width = 15 ;
    const int int_width = 7 ;
    const int dbl_width = 12 ;
    const int num_flds = 7 ;
    const std::string sep = " |" ;
    const int total_width = name_width*2 + int_width*2 + dbl_width*3 + sep.size() * num_flds ;
    const std::string line = sep + std::string( total_width-1, '-' ) + '|' ;



  vector<Country> countryList(228);

  //Parsing and assigning data 
  int count(0);


      ifstream fin("countries.csv");

      if (fin.is_open()) {

        string nextline;
        while(getline(fin, nextline)) {
          if (nextline.size() > 0 && nextline.at(0) != '#') {

          istringstream parser(nextline);

          string name;
          string sPopulation;
          string sArea;
          string sPopDensity;
          string sNetMigration;
          string sGDP;
          string sLiteracy;
          string sBirthRate;
          int population;
          int area;
          double popDensity;
          double netMigration;
          int GDP;
          double literacy;
          double birthRate;

          // Parsing data | from countries.csv
          //              v

          getline(parser, name,',');

          getline(parser, sPopulation, ',');
          population = stoi(sPopulation);

          getline(parser, sArea, ',');
          area = stoi(sArea);

          getline(parser, sPopDensity, ','),
          popDensity = stod(sPopDensity);

          getline(parser, sNetMigration, ',');
          netMigration = stod(sNetMigration);

          getline(parser, sGDP, ',');
          GDP = stoi(sGDP);

          getline(parser, sLiteracy, ',');
          literacy = stod(sLiteracy);

          getline(parser, sBirthRate);
          birthRate = stod(sBirthRate);

          //storing data in struct
          Country c = {name, population, area, popDensity, netMigration, GDP, literacy, birthRate};

          countryList[count] = c; //storing struct into vector

          cout << count << ".) " <<"Name: " << countryList[count].name << " Population: " << countryList[count].population << " Area: " << countryList[count].area << " Pop. Density: " << countryList[count].popDensity << " Net Migration: " << countryList[count].netMigration << " GDP: " << countryList[count].GDP << " Literacy: " << countryList[count].literacy << " Birthrate: " << countryList[count].birthRate <<  endl;
        
        }
        count++; // count +1 to increment which part of the vector the data is stored in then loop.
        }
          fin.close();
        } else {
          cout << "Unable to open countries.csv";
        }

  // data viewer starts
  //clearScreen(); // clears screen for welcome message

  cout << "[ WELCOME TO THE COUNTRY DATA VIEWER ]" << endl;
  
  // clears screen when user presses the enter key
  cout << "\n - Press the ENTER key to continue - ";
  if (cin.get() == '\n') {
    clearScreen();
  } 
  
  int sortingChoice(1);
  while (sortingChoice != 0) { //while sorting choice 
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

    clearScreen();

    int howManyCountries(0);
    int mostOrLeast(0);

    if (sortingChoice == 1) { //if sorting choice is 1 sort by population.
      cout << "How many countries? (1 - ) : ";
      cin >> howManyCountries;
      cout << "1.) Most Populous, or 2.) Least Populous? : ";
      cin >> mostOrLeast;
      if (mostOrLeast == 1) {
      sort(countryList.begin(), countryList.end(), sortByMostPopulous);
      cout << "(Viewing countries by MOST populous";
      header();
      for (int i = 0; i <= howManyCountries -1; i ++) {
        
        printItemList(countryList[i]);
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        } 
      } else if (mostOrLeast == 2) {
        sort(countryList.begin(), countryList.end(), sortByLeastPopulous);
        header();
        for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        }
      }

    } else if (sortingChoice == 2) { //if sorting choice is 2 sort by area.
      cout << "How many countries? (1 - 10)" << endl;
      cin >> howManyCountries;
      cout << "1.) Most Area, or 2.) Least Area?" << endl;
      cin >> mostOrLeast;
      if (mostOrLeast == 1) {
      sort(countryList.begin(), countryList.end(), sortByMostArea);
      header();
      for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
      } else if (mostOrLeast == 2) {
        sort(countryList.begin(), countryList.end(), sortByLeastArea);
        header();
        for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
      }
      
    } else if (sortingChoice == 3) { //if sorting choice is 3 sort by pop. density.

      cout << "How many countries? (1 - 227) : ";
      cin >> howManyCountries;
      cout << "1.) Most Pop. Density, or 2.) Least Pop. Density? : ";
      cin >> mostOrLeast;
      if (mostOrLeast == 1) { //if mostOrLeast = 1 sort by most Pop.cDensity
      sort(countryList.begin(), countryList.end(), sortByMostPopDensity);
      cout << "(Viewing countries by MOST Pop. Density)\n\n";
      header();
      for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        } 
      } else if (mostOrLeast == 2) { // if mostOrLeast = 2 sort by least area
        sort(countryList.begin(), countryList.end(), sortByLeastPopDensity);
        cout << "Viewing countries by LEAST Pop. Density)\n\n";
        header();
        for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        }
      }
      

    } else if (sortingChoice == 4) { //if sorting choice is 4 sort by net. migration.
     cout << "How many countries? (1 - 227) : ";
      cin >> howManyCountries;
      cout << "1.) Most Net Mig, or 2.) Least Net. Mig? : ";
      cin >> mostOrLeast;
      if (mostOrLeast == 1) { //if mostOrLeast = 1 sort by most Pop.cDensity
      sort(countryList.begin(), countryList.end(), sortByMostNetMigration);
      cout << "(Viewing countries by MOST Net. Mig)\n\n";
      header();
      for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        } 
      } else if (mostOrLeast == 2) { // if mostOrLeast = 2 sort by least area
        sort(countryList.begin(), countryList.end(), sortByLeastNetMigration);
        cout << "Viewing countries by LEAST Net. Mig)\n\n";
        header();
        for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        }
      }
     

    } else if (sortingChoice == 5) { //if sorting choice is 5 sort by GDP.
     cout << "How many countries? (1 - 227) : ";
      cin >> howManyCountries;
      cout << "1.) Most GDP, or 2.) Least GDP? : ";
      cin >> mostOrLeast;
      if (mostOrLeast == 1) { //if mostOrLeast = 1 sort by most Pop.cDensity
      sort(countryList.begin(), countryList.end(), sortByMostGDP);
      cout << "(Viewing countries by MOST GDP)\n\n";
      header();
      for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        } 
      } else if (mostOrLeast == 2) { // if mostOrLeast = 2 sort by least area
        sort(countryList.begin(), countryList.end(), sortByLeastGDP);
        cout << "(Viewing countries by LEAST GDP)\n\n";
        header();
        for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        }
      }
    } else if (sortingChoice == 6) { //if sorting choice is 6 sort by literacy.
     cout << "How many countries? (1 - 227) : ";
      cin >> howManyCountries;
      cout << "1.) Most Literacy, or 2.) Least Literacy? : ";
      cin >> mostOrLeast;
      if (mostOrLeast == 1) { //if mostOrLeast = 1 sort by most Pop.cDensity
      sort(countryList.begin(), countryList.end(), sortByMostLiteracy);
      cout << "(Viewing countries by MOST Literacy)\n\n";
      header();
      for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        } 
      } else if (mostOrLeast == 2) { // if mostOrLeast = 2 sort by least area
        sort(countryList.begin(), countryList.end(), sortByLeastLiteracy);
        cout << "(Viewing countries by LEAST Literacy)\n\n";
        header();
        for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        }
      }
      

    } else if (sortingChoice == 7) { //if sorting choice is 7 sort by birth rate.
      cout << "How many countries? (1 - 227) : ";
      cin >> howManyCountries;
      cout << "1.) Most Birth Rate, or 2.) Least Birth Rate? : ";
      cin >> mostOrLeast;
      if (mostOrLeast == 1) { //if mostOrLeast = 1 sort by most Pop.cDensity
      sort(countryList.begin(), countryList.end(), sortByMostBirthRate);
      cout << "(Viewing countries by MOST Birth Rate)\n\n";
      header();
      for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        } 
      } else if (mostOrLeast == 2) { // if mostOrLeast = 2 sort by least area
        sort(countryList.begin(), countryList.end(), sortByLeastBirthRate);
        cout << "(Viewing countries by LEAST BirthRate)\n\n";
        header();
        for (int i = 0; i <= howManyCountries -1; i ++) {
        printItemList(countryList[i]);
        
        }
        // clears screen when user presses the enter key
        cout << "\n - Press the ENTER key to continue - ";
        cin.get();
        if (cin.get() == '\n') {
        clearScreen();
        }
      }
      

    } else if (sortingChoice == 0) { //if sorting choice is 0 exit program.
      //nothing happens so program ends
    }
  }
}
  
