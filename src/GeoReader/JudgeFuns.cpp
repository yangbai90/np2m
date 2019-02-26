#include "GeoReader.h"


bool GeoReader::IsIthPointOnSphereSurface(int i)
{
	double cx,cy,cz,r,dist;
	double x,y,z;
	x=GetIthNodeJthCoords(i,1);
	y=GetIthNodeJthCoords(i,2);
	z=GetIthNodeJthCoords(i,3);

	cx=0.5*(Xmax+Xmin);
	cy=0.5*(Ymax+Ymin);
	cz=0.0;
	if(type==CIRCLE)
	{
		cz=0.0;
		r=0.5*(0.5*(Xmax-Xmin)+0.5*(Ymax-Ymin));
	}
	else if(type==SPHERE)
	{
		cz=0.5*(Zmax+Zmin);
		r=(0.5*(Xmax-Xmin)+0.5*(Ymax-Ymin)+0.5*(Zmax-Zmin))/3.0;
	}

	dist=sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy)+(z-cz)*(z-cz));


	if(abs(dist-r)<=tolerance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//**************************************
bool GeoReader::IsIthLineOnSphereSurface(int i)
{
	if(IsIthPointOnSphereSurface(Lines[i-1][0])&&
	   IsIthPointOnSphereSurface(Lines[i-1][1]))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//*****************************************************
bool GeoReader::IsIthSurfaceOnSphereSurface(int i)
{
	bool IsOnSurface=true;
	int lineid;
	for(unsigned int j=0;j<LineLoops[i-1].size();j++)
	{
		lineid=LineLoops[i-1][j];
		if(lineid<0) lineid=-lineid;
		if(IsIthLineOnSphereSurface(lineid))
		{
			IsOnSurface=true;
		}
		else
		{
			IsOnSurface=false;
			return false;
		}
	}

	return IsOnSurface;

}
