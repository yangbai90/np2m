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

private:
    inline int GetPointsNum() const {return _nNodes;}
    inline int GetLinesNum() const {return _nLines;}
    inline int GetSurfacesNum() const {return _nSurfaces;}
    inline int GetVolumesNum() const {return _nVolumes;}

    inline int GetMinDim() const {return _nDimMin;}
    inline int GetMaxDim() const {return _nDimMax;}

private:
    // information for geometric
    double _Xmin,_Xmax,_Ymin,_Ymax,_Zmin,_Zmax;
    int _nDim,_nDimMax,_nDimMin;
    int _nNodes,_nLines,_nLineLoops,_nSurfaces,_nVolumes;

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

};

#endif // GEOREADER_H