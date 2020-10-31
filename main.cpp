#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

int main() {


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

          cout << count << ".) " <<"Name: " << countryList[count].name << " Population: " << countryList[count].population << " Area: " << countryList[count].area << " Pop. Density: " << countryList[count].popDensity << " Net Migration: " << countryList[count].netMigration << " GDP: " << countryList[count].GDP << " Literacy: " << countryList[count].literacy << " Birthrate: " << countryList[count].birthRate <<  endl;
        
        }
        count++;
        }
          fin.close();
        } else {
          cout << "Unable to open countries.csv";
        }
       }
      
