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
	r=0.0;
	if(domain=="circle")
	{
		cz=0.0;
		r=0.5*(0.5*(Xmax-Xmin)+0.5*(Ymax-Ymin));
	}
	else if(domain=="sphere")
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

//**********************************************
//*** For rectangle
//*********************************************
bool GeoReader::IsIthPointOnLeftSurface(int i)
{
    double x=GetIthNodeJthCoords(i,1);
    if(abs(x-Xmin)<tolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//*********************************
bool GeoReader::IsIthLineOnLeftSurface(int i)
{
   if(IsIthPointOnLeftSurface(Lines[i-1][0])&&
      IsIthPointOnLeftSurface(Lines[i-1][1]))
   {
       return true;
   } 
   return false;
}
//**********************************
bool GeoReader::IsIthSurfaceOnLeftSurface(int i)
{
    bool IsSurfaceOn=true;
    int lineid;
    for(unsigned int j=0;j<LineLoops[i-1].size();j++)
    {
        lineid=LineLoops[i-1][j];
        if(lineid<0) lineid=-lineid;
        if(IsIthLineOnLeftSurface(lineid))
        {
            IsSurfaceOn=true;
        }
        else
        {
            IsSurfaceOn=false;
            return false;
        }
    }
    return IsSurfaceOn;
}
//**********************************************
bool GeoReader::IsIthPointOnRightSurface(int i)
{
    double x=GetIthNodeJthCoords(i,1);
    if(abs(x-Xmax)<tolerance)
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthLineOnRightSurface(int i)
{
    if(IsIthPointOnRightSurface(Lines[i-1][0])&&
       IsIthPointOnRightSurface(Lines[i-1][1]))
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthSurfaceOnRightSurface(int i)
{
    bool IsSurfaceOn;
    int lineid;
    for(unsigned int j=0;j<LineLoops[i-1].size();j++)
    {
        lineid=LineLoops[i-1][j];
        if(lineid<0) lineid=-lineid;
        if(IsIthLineOnRightSurface(lineid))
        {
            IsSurfaceOn=true;
        }
        else
        {
            IsSurfaceOn=false;
            return false;
        }
    }
    return IsSurfaceOn;
}
//*********************************************
bool GeoReader::IsIthPointOnBottomSurface(int i)
{
    double y=GetIthNodeJthCoords(i,2);
    if(abs(y-Ymin)<tolerance)
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthLineOnBottomSurface(int i)
{
    if(IsIthPointOnBottomSurface(Lines[i-1][0])&&
       IsIthPointOnBottomSurface(Lines[i-1][1]))
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthSurfaceOnBottomSurface(int i)
{
    bool IsSurfaceOn;
    int lineid;
    for(unsigned int j=0;j<LineLoops[i-1].size();j++)
    {
        lineid=LineLoops[i-1][j];
        if(lineid<0) lineid=-lineid;
        if(IsIthLineOnBottomSurface(lineid))
        {
            IsSurfaceOn=true;
        }
        else
        {
            IsSurfaceOn=false;
            return false;
        }
    }
    return IsSurfaceOn;
}
//************************************
bool GeoReader::IsIthPointOnTopSurface(int i)
{
    double y=GetIthNodeJthCoords(i,2);
    if(abs(y-Ymax)<tolerance)
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthLineOnTopSurface(int i)
{
    if(IsIthPointOnTopSurface(Lines[i-1][0])&&
       IsIthPointOnTopSurface(Lines[i-1][1]))
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthSurfaceOnTopSurface(int i)
{
    bool IsSurfaceOn;
    int lineid;
    for(unsigned int j=0;j<LineLoops[i-1].size();j++)
    {
        lineid=LineLoops[i-1][j];
        if(lineid<0) lineid=-lineid;
        if(IsIthLineOnTopSurface(lineid))
        {
            IsSurfaceOn=true;
        }
        else
        {
            IsSurfaceOn=false;
            return false;
        }
    }
    return IsSurfaceOn;
}
//****************************************
bool GeoReader::IsIthPointOnBackSurface(int i)
{
    double z=GetIthNodeJthCoords(i,3);
    if(abs(z-Zmin)<tolerance)
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthLineOnBackSurface(int i)
{
    if(IsIthPointOnBackSurface(Lines[i-1][0])&&
       IsIthPointOnBackSurface(Lines[i-1][1]))
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthSurfaceOnBackSurface(int i)
{
    bool IsSurfaceOn;
    int lineid;
    for(unsigned int j=0;j<LineLoops[i-1].size();j++)
    {
        lineid=LineLoops[i-1][j];
        if(lineid<0) lineid=-lineid;
        if(IsIthLineOnBackSurface(lineid))
        {
            IsSurfaceOn=true;
        }
        else
        {
            IsSurfaceOn=false;
            return false;
        }
    }
    return true;
}
//******************************
bool GeoReader::IsIthPointOnFrontSurface(int i)
{
    double z=GetIthNodeJthCoords(i,3);
    if(abs(z-Zmax)<tolerance)
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthLineOnFrontSurface(int i)
{
    if(IsIthPointOnFrontSurface(Lines[i-1][0])&&
       IsIthPointOnFrontSurface(Lines[i-1][1]))
    {
        return true;
    }
    return false;
}
bool GeoReader::IsIthSurfaceOnFrontSurface(int i)
{
    bool IsSurfaceOn;
    int lineid;
    for(unsigned int j=0;j<LineLoops[i-1].size();j++)
    {
        lineid=LineLoops[i-1][j];
        if(lineid<0) lineid=-lineid;
        if(IsIthLineOnFrontSurface(lineid))
        {
            IsSurfaceOn=true;
        }
        else
        {
            IsSurfaceOn=false;
            return false;
        }
    }
    return IsSurfaceOn;
}
