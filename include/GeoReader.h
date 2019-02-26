#ifndef GEOREADER_H
#define GEOREADER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstring>
#include <cmath>
#include "StringUtils.h"

using namespace std;


class GeoReader
{
public:
	GeoReader();

	void Help() const;
	void Run(int args,char *argv[]);

	void SetDomain(string shape="circle");
	void SetPrintFlag(bool flag=true) {IsPrint=flag;}
	void SetMeshSize(double dx=1.0) {size=dx;}
	void SetSplitSurfaceFlag(bool flag=true) {IsSplitSurface=flag;}
	void SetSplitBoundaryFlag(bool flag=true) {IsSplitBoundary=flag;}
	void SetSplitInterfaceFlag(bool flag=false) {IsSplitInterface=flag;}
	void SetFileName(string filename) {geofilename=filename;}
	void SetTolerance(double tol=1.0e-6) {tolerance=tol;}


	inline double GetIthNodeJthCoords(int i,int j) const {return Points[(i-1)*3+j-1];}
	inline int GetIthLineJthNodeID(int i,int j) const {return Lines[i-1][j-1];}
	inline int GetIthSurfaceLineLoopID(int i) const {return Surfaces[i-1];}
	inline int GetIthVolumeSurfaceLoopID(int i) const {return Volumes[i-1];}


	inline int GetIthLineLoopJthLineID(int i,int j) const {return LineLoops[i-1][j-1];}
	inline int GetIthSurfaceLoopJthSurfaceID(int i,int j) const {return SurfaceLoops[i-1][j-1];}


	void PrintInfo() const;

private:
	void ReadGeoFile();
	void ModifyForCirlce();
	bool IsIthPointOnSphereSurface(int i);
	bool IsIthLineOnSphereSurface(int i);
	bool IsIthSurfaceOnSphereSurface(int i);
	void ModifyForSphere();

private:

	enum JobType
	{
		CIRCLE,
		SPHERE 
	};

	string geofilename,newgeofilename;
	int nPoints,nLines,nSurfaces,nVolumes;
	int nLineLoops,nSurfaceLoops;
	vector<vector<int>> Lines;
	vector<int> Surfaces,Volumes;
	vector<vector<int>> LineLoops,SurfaceLoops;

	vector<double> Points;

	JobType type=CIRCLE;

	bool PrintFlag;
	string domain="circle";
	double size=1.0;
	double tolerance=1.0e-3;
	bool IsPrint=true;
	bool IsSplitSurface=true;
	bool IsSplitInterface=false;
	bool IsSplitBoundary=true;

	double Xmax,Xmin,Ymax,Ymin,Zmax,Zmin;

};

#endif 
