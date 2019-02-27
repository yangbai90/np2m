#include "GeoReader.h"


void GeoReader::PrintInfo() const
{
	cout<<"*************************************"<<endl;
	cout<<"*** Geo file information:         ***"<<endl;
	cout<<"*** file name= "<<geofilename<<endl;
	cout<<"*** new  name= "<<newgeofilename<<endl;
	cout<<"*** number of points= "<<nPoints<<endl;
	cout<<"*** number of lines= "<<nLines<<endl;
	cout<<"*** number of line loops= "<<nLineLoops<<endl;
	cout<<"*** number of surfaces= "<<nSurfaces<<endl;
	cout<<"*** number of surface loops= "<<nSurfaceLoops<<endl;
	cout<<"*** number of volumes= "<<nVolumes<<endl;
	cout<<"*** tolerance="<<tolerance<<endl;
	cout<<"*** domain="<<domain<<endl;
	if(type==CIRCLE)
	{
		cout<<"*** JobType = cirlce case"<<endl;
	}
	else if(type==SPHERE)
	{
		cout<<"*** JobType = sphere case"<<endl;
	}
	if(IsSplitSurface)
	{
		cout<<"*** Split surface = true"<<endl;
	}
	else
	{
		cout<<"*** Split surface = false"<<endl;
	}
	cout<<"*************************************"<<endl<<endl;
}
