#include "GeoReader.h"

void GeoReader::ModifyForSphere()
{
	//
	ofstream out;
	out.open(newgeofilename.c_str(),ios::out);
	out<<"dx="<<size<<";"<<endl<<endl;
	vector<int> SurfaceID;

	for(int i=0;i<nPoints;i++)
	{
		out<<"Point ("<<i+1<<") = {";
		out<<scientific<<setprecision(6)<<GetIthNodeJthCoords(i+1,1)<<","
			                        <<GetIthNodeJthCoords(i+1,2)<<","
						<<GetIthNodeJthCoords(i+1,3)
						<<",dx};"<<endl;
	}
	out<<endl<<endl;

	// write out line
	for(int i=0;i<nLines;i++)
	{
		out<<"Line ("<<i+1<<") = {";
		out<<Lines[i][0]<<","<<Lines[i][1];
		out<<"};"<<endl;
	}
	out<<endl<<endl;

	// For Line loop
	SurfaceID.clear();
	for(int i=0;i<nLineLoops;i++)
	{
		out<<"Line Loop ("<<i+1<<") = {";
		out<<LineLoops[i][0];
		for(unsigned int j=1;j<LineLoops[i].size();j++)
		{
			out<<","<<LineLoops[i][j];
		}
		out<<"};"<<endl;

		//Plane Surface (1) = {1}; Physical Surface (1) = {1};
		out<<"Plane Surface ("<<i+1<<") = {"<<i+1<<"}; ";
		out<<"Physical Surface ("<<i+1<<") = {"<<i+1<<"};"<<endl;

		if(IsIthSurfaceOnSphereSurface(i+1))
		{
			SurfaceID.push_back(i+1);
		}
	}
	out<<endl<<endl<<endl;

	//  For surface loop
	for(int i=0;i<nSurfaceLoops;i++)
	{
		out<<"Surface Loop ("<<i+1<<") = {";
		out<<SurfaceLoops[i][0];
		for(unsigned int j=1;j<SurfaceLoops[i].size();j++)
		{
			out<<","<<SurfaceLoops[i][j];
		}
		out<<"};"<<endl;
		out<<"Volume ("<<i+1<<") = {"<<i+1<<"};"<<endl;
	}
	out<<endl<<endl<<endl;

	//*****************************************************
	if(IsSplitSurface)
	{
		cout<<"Number of surface surface ID="<<SurfaceID.size()<<endl;
		if(SurfaceID.size()>1)
		{
			out<<"Physical Surface (\"surface\")={";
			out<<SurfaceID[0];
			for(unsigned int j=1;j<SurfaceID.size();j++)
			{
				out<<","<<SurfaceID[j];
			}
			out<<"};"<<endl;
		}
	}

	for(int i=0;i<nVolumes;i++)
	{
		out<<"Physical Volume ("<<i+1<<") = {"<<setw(6)<<i+1<<"};"<<endl;
	}
	out<<endl<<endl;

	out.close();

	cout<<"Xmin="<<Xmin<<", Xmax="<<Xmax<<endl;
	cout<<"Ymin="<<Ymin<<", Ymax="<<Ymax<<endl;
	cout<<"Zmin="<<Zmin<<", Zmax="<<Zmax<<endl;
	cout<<"cx="<<0.5*(Xmax+Xmin)
	    <<", cy="<<0.5*(Ymax+Ymin)
	    <<", cz="<<0.5*(Zmax+Zmin)
	    <<", radius="<<(0.5*(Xmax-Xmin)+0.5*(Ymax-Ymin)+0.5*(Zmax-Zmin))/3.0<<endl;
	cout<<"**** Write to "<<newgeofilename<<" !!!"<<endl;

}
