#include "StringUtils.h"


string ToLowerCase(string str)
{
	string outstr=str;
	transform(outstr.begin(),outstr.end(),outstr.end(),::tolower);
	return outstr;
}

//**************************************************
string ToUpperCase(string str)
{
	string outstr=str;
	transform(outstr.begin(),outstr.end(),outstr.end(),::toupper);
	return str;
}
