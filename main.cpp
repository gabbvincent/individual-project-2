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

    const int name_width = 15 ;
    const int int_width = 11 ;
    const int dbl_width = 12 ;
    const int num_flds = 7 ;
    const std::string sep = " |" ;
    const int total_width = name_width*2 + int_width*2 + dbl_width*3 + sep.size() * num_flds ;
    const std::string line = sep + std::string( total_width-1, '-' ) + '|' ;

    void header() {
      cout << line << '\n' << sep
        << std::setw(name_width) << "COUNTRY" << sep << std::setw(int_width) << "POPULATION" << sep
        << std::setw(dbl_width) << "POP DENS" << sep << std::setw(dbl_width) << "NET MIG" << sep
        << std::setw(int_width) << "GDP" << sep << std::setw(dbl_width) << "LITERACY" << sep
        << std::setw(dbl_width) << "BIRTH RT" << sep << '\n' << line << '\n' ;
    }

void printItemList(Country c) {
  cout << sep << std::setw(name_width) << c.name << sep << std::setw(int_width) << c.population << sep
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

int main() {

    const int name_width = 15 ;
    const int int_width = 7 ;
    const int dbl_width = 12 ;
    const int num_flds = 7 ;
    const std::string sep = " |" ;
    const int total_width = name_width*2 + int_width*2 + dbl_width*3 + sep.size() * num_flds ;
    const std::string line = sep + std::string( total_width-1, '-' ) + '|' ;



  vector<Country> countryList(228);
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


          Country c = {name, population, area, popDensity, netMigration, GDP, literacy, birthRate}; // storing data in struct

          countryList[count] = c; // storing struct into vector

          // cout << count << ".) " <<"Name: " << countryList[count].name << " Population: " << countryList[count].population << " Area: " << countryList[count].area << " Pop. Density: " << countryList[count].popDensity << " Net Migration: " << countryList[count].netMigration << " GDP: " << countryList[count].GDP << " Literacy: " << countryList[count].literacy << " Birthrate: " << countryList[count].birthRate <<  endl;
        
        }
        count++; // count +1 to increment which part of the vector the data is stored in then loop.
        }
          fin.close();
        } else {
          cout << "Unable to open countries.csv";
        }

  // data viewer starts
  clearScreen();

  cout << "[ WELCOME TO THE COUNTRY DATA VIEWER ]" << endl;
  
  cout << "\n - Press the ENTER key to continue - ";
  if (cin.get() == '\n') {
    clearScreen();
  } 
  
  int sortingChoice;
  while (sortingChoice != 0) {
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

    if (sortingChoice == 1) {
      cout << "How many countries? (1 - 10) : ";
      cin >> howManyCountries;
      cout << "1.) Most Populous, or 2.) Least Populous? : ";
      cin >> mostOrLeast;
      if (mostOrLeast == 1) {
      sort(countryList.begin(), countryList.end(), sortByMostPopulous);
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

    } else if (sortingChoice == 2) {
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
      
    } else if (sortingChoice == 3) {
      cout << "How many countries? (1 - 10)" << endl;
      cin >> howManyCountries;
      

    } else if (sortingChoice == 4) {
      cout << "How many countries? (1 - 10)" << endl;
      cin >> howManyCountries;
     

    } else if (sortingChoice == 5) {
      cout << "How many countries? (1 - 10)" << endl;
      cin >> howManyCountries;
   

    } else if (sortingChoice == 6) {
      cout << "How many countries? (1 - 10)" << endl;
      cin >> howManyCountries;
      

    } else if (sortingChoice == 7) {
      cout << "How many countries? (1 - 10)" << endl;
      cin >> howManyCountries;
      

    } else if (sortingChoice == 0) {
      //nothing happens so program ends
    }
  }
}
         
