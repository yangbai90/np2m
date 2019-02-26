#include <iostream>
#include <cstring>

#include "StringUtils.h"

#include "GeoReader.h"

using namespace std;


int main(int args,char *argv[])
{
	//**********************************************
	//*** options
	//*** -i test.geo
	//*** -domain circle
	//*** -size 0.5
	//*** -surface true
	//*** -help
	//**********************************************
	
	GeoReader reader;

	reader.Run(args,argv);

	return 0;
}
