#ifndef GEOREADER_H
#define GEOREADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

#include "StringUtils.h"

using namespace std;

class GeoReader
{
public:
    GeoReader();
    void Run(int args,char *argv[]);


private:
    void PrintHelper();
    void PrintInfo();

private:
    void ReadGeoFile();
    void RunJobForCircle();
    void RunJobFor14thCircle();
    void RunJobForRect();
    void RunJobForSphere();
    void RunJobFor18thSphere();
    void RunJobForCubic();
    void RunJobForCylinder();

//********************************
//*** Judge fun
private:
    bool IsIthPointOnEdge(const int &i,const int &component,const double &coord) const;
    bool IsIthLineOnEdge(const int &i,const int &component,const double &coord) const;
    bool IsIthSurfaceOnEdge(const int &i,const int &component,const double &coord) const;

private:
    void SetTol(double tol){_tolerance=tol;}
    void SetSize(double size){_Size=size;}
private:
    inline int GetPointsNum() const {return _nNodes;}
    inline int GetLinesNum() const {return _nLines;}
    inline int GetSurfacesNum() const {return _nSurfaces;}
    inline int GetVolumesNum() const {return _nVolumes;}

    inline int GetMinDim() const {return _nDimMin;}
    inline int GetMaxDim() const {return _nDimMax;}

private:
    inline double GetIthNodeJthCoord(const int &i,const int &j)const{
        return _NodeCoords[(i-1)*3+j-1];
    }
    //**********************************
    inline int GetIthLineJthNodeID(const int &i,const int &j)const{
        return _Line[(i-1)*2+j-1];
    }
    //**********************************
    inline int GetIthLineLoopLength(const int &i)const{
        return (int)_LineLoop[i-1].size();
    }
    inline int GetIthLineLoopJthLineID(const int &i,const int &j)const{
        return _LineLoop[i-1][j-1];
    }
    //***********************************
    inline int GetIthSurfaceLoopLength(const int &i)const{
        return (int)_SurfaceLoop[i-1].size();
    }
    inline int GetIthSurfaceLoopJthSurfaceID(const int &i,const int &j)const{
        return _SurfaceLoop[i-1][j-1];
    }

private:
    // information for geometric
    double _Xmin,_Xmax,_Ymin,_Ymax,_Zmin,_Zmax;
    int _nDim,_nDimMax,_nDimMin;
    double _tolerance=5.0e-2;
    double _Size=1.0;
    int _nNodes,_nLines,_nLineLoops,_nSurfaces,_nSurfaceLoops,_nVolumes;

    vector<double> _NodeCoords;
    vector<int> _Line;
    vector<vector<int>> _LineLoop,_SurfaceLoop;

private:
    string _GeoFileName,_NewGeoFileName;


private:
    // For job related information
    enum class JobType{
        RECTANGLE,
        CIRCLE,
        SPHERE,
        CUBIC,
        CYLINDER
    };
    JobType _JobType;
    string _Domain;
private:
    // array for split information
    vector<int> _LeftLineIDSet,_RightLineIDSet;
    vector<int> _BottomLineIDSet,_TopLineIDSet;

    vector<int> _LeftSurfaceIDSet,_RightSurfaceIDSet;
    vector<int> _BottomSurfaceIDSet,_TopSurfaceIDSet;
    vector<int> _BackSurfaceIDSet,_FrontSurfaceIDSet;


};

#endif // GEOREADER_H