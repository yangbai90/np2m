#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

string ToLowerCase(string str);
string ToUpperCase(string str);

string RemoveSpace(string str);

vector<string> SplitStringVecBySymbol(string instr,char symbol);

vector<double> SplitNumVecFromString(string instr);

//vector<double> SplitNumVecFromRoundBracketString(string str);
//vector<double> SplitNumVecFromCurlyBracketString(string str);

#endif
