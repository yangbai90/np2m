#include "StringUtils.h"

vector<string> SplitStringVecBySymbol(string instr,char symbol)
{
	vector<string> outstr;
	stringstream ss(instr);
	string tok;

	outstr.clear();

	while(getline(ss,tok,symbol))
	{
		outstr.push_back(tok);
	}
	return outstr;
}
