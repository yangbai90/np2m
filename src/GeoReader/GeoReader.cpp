#include "GeoReader.h"

GeoReader::GeoReader()
{
    _Xmin=1.0e16;_Xmax=-1.0e16;
    _Ymin=1.0e16;_Ymax=-1.0e16;
    _Zmin=1.0e16;_Zmax=-1.0e16;

    _nDim=0;_nDimMax=0;_nDimMin=0;
    _nNodes=0;_nLines=0;_nSurfaces=0;_nVolumes=0;

    _NodeCoords.clear();
    _Line.clear();
    _LineLoop.clear();
    _SurfaceLoop.clear();


    _GeoFileName="";_NewGeoFileName="";



    _JobType=JobType::CIRCLE;
    _Domain="circle";
}