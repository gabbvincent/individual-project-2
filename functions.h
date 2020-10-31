#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using namespace std;

void dataViewer();

void clearScreen();

void sortingOptions();

void sortByPopulation(const vector<Country>& countryList);

void sortByArea(const vector<Country>& countryList);

void sortByPopDensity(const vector<Country>& countryList);

void sortByNetMigration(const vector<Country>& countryList);

void sortByGDP(const vector<Country>& countryList);

void sortByLiteracy(const vector<Country>& countryList);

void sortByBirthRate(const vector<Country>& countryList);