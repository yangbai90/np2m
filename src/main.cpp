#include <iostream>
#include <cstring>
#include <chrono>

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
	
	

	auto start=chrono::high_resolution_clock::now();
	GeoReader reader;
	reader.Run(args,argv);
	auto end=chrono::high_resolution_clock::now();
	printf("*** Convert finished! Time elpased: %14.6f [s] !       ***\n",chrono::duration_cast<chrono::microseconds>(end-start).count()/1.0e6);
	cout<<"******************************************************************"<<endl;
	return 0;
}
