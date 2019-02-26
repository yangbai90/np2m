#include "GeoReader.h"

void GeoReader::ReadGeoFile()
{
	type=CIRCLE;

	string line;
	vector<double> numbers;
	vector<string> strvec;

	ifstream in;
	in.open(geofilename.c_str(),ios::in);

	while(!in.is_open())
	{
		cout<<"**** Error: can't open file(="<<geofilename<<")!!!"<<endl;
		cout<<"**** input the correct filename=";
		cin>>geofilename;
		in.open(geofilename.c_str(),ios::in);
	}

	while(!in.eof())
	{
		getline(in,line);
		if(line.find("Point (")!=string::npos)
		{
			numbers=SplitNumVecFromString(line);
			if(numbers.size()!=4)
			{
				// Data format:
				// node id, x, y, z
				cout<<"**** Error: Points must have three components!!!"<<endl;
				abort();
			}
			else
			{
				Points.push_back(numbers[1]);
				Points.push_back(numbers[2]);
				Points.push_back(numbers[3]);
				nPoints+=1;
			}
		}
		else if(line.find("Line (")!=string::npos)
		{
			// Read line 
			numbers=SplitNumVecFromString(line);
			if(numbers.size()!=3)
			{
				cout<<"**** Error: Line ()={} must have 3 numbers"<<endl;
				abort();
			}
			else
			{
				vector<int> vec;
				vec.push_back(int(numbers[1]));
				vec.push_back(int(numbers[2]));
				Lines.push_back(vec);
				nLines+=1;
			}
		}
		else if(line.find("Line Loop (")!=string::npos)
		{
			// Read line loop
			numbers=SplitNumVecFromString(line);
			if(numbers.size()<4)
			{
				cout<<"**** Error: Line Loop () must have at least 4 numbers!!!"<<endl;
				abort();
			}
			else
			{
				vector<int> lineid;
				lineid.clear();
				for(unsigned int i=1;i<numbers.size();i++)
				{
					lineid.push_back(int(numbers[i]));
				}
				LineLoops.push_back(lineid);
				nLineLoops+=1;
			}
		}
		else if(line.find("Plane Surface (")!=string::npos)
		{
			// Read Plane surface information
			strvec=SplitStringVecBySymbol(line,';');
			numbers=SplitNumVecFromString(strvec[0]);
			if(numbers.size()<2)
			{
				cout<<"**** Error: Plane Surface () must have 2 numbers!!!"<<endl;
				abort();
			}
			else
			{
				Surfaces.push_back(int(numbers[1]));
				nSurfaces+=1;
			}
		}
		else if(line.find("Surface Loop (")!=string::npos)
		{
			// read surface loop
			numbers=SplitNumVecFromString(line);
			if(numbers.size()<1+4)
			{
				cout<<"**** Error: Surface Loop () must have at least 5 numbers!!!"<<endl;
				abort();
			}
			else
			{
				vector<int> surfaceid;
				surfaceid.clear();
				for(unsigned int i=1;i<numbers.size();i++)
				{
					surfaceid.push_back(int(numbers[i]));
				}
				SurfaceLoops.push_back(surfaceid);
				nSurfaceLoops+=1;
			}
		}
		else if(line.find("Volume (")!=string::npos)
		{
			// Read volume
			numbers=SplitNumVecFromString(line);
			if(numbers.size()!=2)
			{
				cout<<"**** Error: Volume() must have 2 numbers!!!"<<endl;
				abort();
			}
			else
			{
				Volumes.push_back(int(numbers[1]));
				nVolumes+=1;
			}
		}
	}

	// After all the information are ready,
	// we must check the data
	if(nLineLoops!=nSurfaces)
	{
		cout<<"**** Error: nLineLoops("<<nLineLoops<<")!=nSurfaces("<<nSurfaces<<") !!!"<<endl;
		abort();
	}

	if(nSurfaceLoops!=nVolumes)
	{
		cout<<"**** Error: nSurfaceLoops("<<nSurfaceLoops<<")!= nVolumes("<<nVolumes<<") !!!"<<endl;
		abort();
	}

}
