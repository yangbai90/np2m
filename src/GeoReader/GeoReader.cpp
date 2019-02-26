#include "GeoReader.h"


GeoReader::GeoReader()
{
	//geofilename=RemoveSpace(filename);
	//newgeofilename="new"+geofilename;

	nPoints=0;nLines=0;nSurfaces=0;nVolumes=0;

	nLineLoops=0;nSurfaceLoops=0;

	Lines.clear();Surfaces.clear();Volumes.clear();
	LineLoops.clear();SurfaceLoops.clear();

	Points.clear();
}

//******************************************
void GeoReader::Help() const
{
	cout<<"*******************************************"<<endl;
	cout<<"*** Options:                            ***"<<endl;
	cout<<"*** -help                               ***"<<endl;
	cout<<"*** -print  (print out geo information) ***"<<endl;
	cout<<"*** -size 0.5 (set the mesh size)       ***"<<endl;
	cout<<"*** -domain circle [sphere,cube...]     ***"<<endl;
	cout<<"*** -surface true [false]               ***"<<endl;
	cout<<"*** -boundary true [false]              ***"<<endl;
	cout<<"*** -interface true [false]             ***"<<endl;
	cout<<"*******************************************"<<endl;
}
//******************************************
//
void GeoReader::Run(int args,char *argv[])
{

	// For default options
	//
	SetSplitInterfaceFlag(false);
	SetSplitSurfaceFlag(true);
	SetSplitBoundaryFlag(true);
	SetMeshSize(1.0);
	SetPrintFlag(true);
	SetTolerance(1.0e-3);

	if(args==1)
	{
		// for ./n2m case
		Help();
	}
	else if(args==2)
	{
		if(strcmp("-help",argv[1])==0)
		{
			Help();
		}
		else
		{
			geofilename=string(argv[1]);
			if(geofilename.find(".geo")==string::npos)
			{
				cout<<"**** Error: invalid file format!!!"<<endl;
				cout<<"****        *.geo is required!"<<endl;
				abort();
			}
			newgeofilename="new"+geofilename;
		}
	}
	else
	{
		// format ./n2m my.geo -i sss -3 sss
		geofilename=string(argv[1]);
		newgeofilename="new"+geofilename;

		int i;
		for(i=2;i<args;i++)
		{
			if(strcmp("-print",argv[i])==0)
			{
				SetPrintFlag(true);
			}
			else if(strcmp("-size",argv[i])==0)
			{
				if(i<args-1)
				{
					size=atof(argv[i+1]);
				}
				else
				{
					cout<<"**** Error: no value found after -size !!!"<<endl;
					abort();
				}
			}
			else if(strcmp("-domain",argv[i])==0)
			{
				if(i<args-1)
				{
					if(string(argv[i+1]).find("circle")==string::npos&&
					   string(argv[i+1]).find("sphere")==string::npos&&
					   string(argv[i+1]).find("cube")  ==string::npos&&
					   string(argv[i+1]).find("cylinder")==string::npos)
					{
						cout<<"**** Error: unsupported domain type !!!"<<endl;
						abort();
					}
					domain=string(argv[i+1]);
				}
				else
				{
					cout<<"**** Error: no text found after -domain !!!"<<endl;
					abort();
				}
			}
			else if(strcmp("-surface",argv[i])==0)
			{
				if(i<args-1)
				{
					if(string(argv[i+1]).find("true")!=string::npos)
					{
						SetSplitSurfaceFlag(true);
					}
					else if(string(argv[i+1]).find("false")!=string::npos)
					{
						SetSplitSurfaceFlag(false);
					}
					else
					{
						cout<<"**** Error: unknown flag after -surface !!!"<<endl;
						abort();
					}
				}
				else
				{
					cout<<"**** Error: no flag after -surface !!!"<<endl;
					abort();
				}
			}
			else if(strcmp("-boundary",argv[i])==0)
			{
				if(i<args-1)
				{
					if(string(argv[i+1]).find("true")!=string::npos)
					{
						SetSplitBoundaryFlag(true);
					}
					else if(string(argv[i+1]).find("false")!=string::npos)
					{
						SetSplitBoundaryFlag(false);
					}
					else
					{
						cout<<"*** Error: no flag found after -boundary !!!"<<endl;
						abort();
					}
				}
				else
				{
					cout<<"*** Error: no flag found after -boundary  !!!"<<endl;
				}
			}
			else if(strcmp("-interface",argv[i])==0)
			{
				if(i<args)
				{
					if(string(argv[i+1]).find("true")!=string::npos)
					{
						SetSplitInterfaceFlag(true);
					}
					else if(string(argv[i+1]).find("false")!=string::npos)
					{
						SetSplitInterfaceFlag(false);
					}
					else
					{
						cout<<"**** Error: no flag after -interface !!!"<<endl;
						abort();
					}
				}
				else
				{
					cout<<"**** Error: no flag after -interface !!!"<<endl;
				}
			}
			else if(strcmp("-tol",argv[i])==0)
			{
				if(i<args-1)
				{
					SetTolerance(atof(argv[i+1]));
				}
				else
				{
					cout<<"**** Error: no tolerance is given after -tol !!!"<<endl;
					abort();
				}
			}
		}
	}


	ReadGeoFile();

	if(domain=="circle")
	{
		ModifyForCirlce();
	}
	else if(domain=="sphere")
	{
		ModifyForSphere();
	}

	if(IsPrint)
	{
		PrintInfo();
	}
}
