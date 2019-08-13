#include "GeoReader.h"

void GeoReader::PrintHelper()
{
    cout<<"******************************************************************"<<endl;
    cout<<"*** Welcome to use np2m: the nepper to geo file convert tool   ***"<<endl;
    cout<<"*** Usage example: ./np2m my.geo -domain circle -print         ***"<<endl;
	cout<<"*** Options:                                                   ***"<<endl;
	cout<<"***   -help (if -help is given,other options are ignored!)     ***"<<endl;
	cout<<"***   -print  (print out convert information)                  ***"<<endl;
	cout<<"***   -size 0.5 (set the mesh size, the dx assigned to Points) ***"<<endl;
	cout<<"***   -domain circle [rect,sphere,cubic,cylinder]              ***"<<endl;
	cout<<"***   -surface true [false] (label out all the 'surface')      ***"<<endl;
	cout<<"***   -boundary true [false](label out 'left','right','top'..) ***"<<endl;
	cout<<"***   -interface true [false](not support yet!)                ***"<<endl;
	cout<<"***   -tol 5.0e-2 (tolerance for spliting)                     ***"<<endl;
    cout<<"*** Contact: walkandthinker@gmail.com                          ***"<<endl;
	cout<<"******************************************************************"<<endl;
}