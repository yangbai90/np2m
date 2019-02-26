#include "StringUtils.h"

string RemoveSpace(string instr)
{
	if(instr.size()<=1)
	{
		return instr;
	}

	unsigned int i,length;
	char ch[5000];
	length=0;
	for(i=0;i<instr.size();i++)
	{
		if(instr.at(i)!=' ')
		{
			ch[length]=instr.at(i);
			length+=1;
		}
	}

	string outstr;
	outstr.clear();

	for(i=0;i<length;i++)
	{
		if(ch[i]=='\n')
		{
			break;
		}
		outstr.push_back(ch[i]);
	
	}

	return outstr;
}
