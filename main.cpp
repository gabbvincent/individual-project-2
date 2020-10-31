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
};

int main() {


  vector<Country> countryList(227);
  int count(0);

      ifstream fin("countries.csv");

      if (fin.is_open()) {

        string nextline;
        while(getline(fin, nextline)) {
          if (nextline.size() > 0 && nextline.at(0) != '#') {

          istringstream parser(nextline);

          string name;
          string sPopulation;
          int population;

          getline(parser, name,',');

          getline(parser, sPopulation);
          population = stoi(sPopulation);

          Country c = {name, population};

          countryList[count] = c;

          cout << countryList[count].name << " " << countryList[count].population << endl;
        
        }
        count++;
        }
          fin.close();

        } else {
          cout << "Unable to open countries.csv";
        }
       }
      
