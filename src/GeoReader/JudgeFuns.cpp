#include "GeoReader.h"

bool GeoReader::IsIthPointOnEdge(const int &i,const int &component,const double &coord) const{
    if(abs(GetIthNodeJthCoord(i,component)-coord)<_tolerance){
        return true;
    }
    return false;
}
//*************************************
bool GeoReader::IsIthLineOnEdge(const int &i,const int &component,const double &coord) const{
    int id1=GetIthLineJthNodeID(i,1);
    int id2=GetIthLineJthNodeID(i,2);
    if(IsIthPointOnEdge(id1,component,coord)&&IsIthPointOnEdge(id2,component,coord)){
        return true;
    }
    return false;
}
//**************************************
bool GeoReader::IsIthSurfaceOnEdge(const int &i,const int &component,const double &coord) const{
    bool IsOnEdge=true;
    int j,lineid;
    for(j=1;j<=GetIthLineLoopLength(i);++j){
        lineid=GetIthLineLoopJthLineID(i,j);
        if(lineid<0) lineid=-lineid;
        if(IsIthLineOnEdge(lineid,component,coord)){
            IsOnEdge=true;
        }
        else{
            IsOnEdge=false;
            return false;
        }
    }
    return IsOnEdge;
}