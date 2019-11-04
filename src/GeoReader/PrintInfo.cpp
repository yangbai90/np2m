#include "GeoReader.h"

void GeoReader::PrintInfo()
{
    cout<<"******************************************************************"<<endl;
    cout<<"*** Information summary:                                       ***"<<endl;
    printf("***   Point=%6d, Line=%6d, Surface=%6d, Volume=%6d ***\n",GetPointsNum(),
                                                                  GetLinesNum(),
                                                                  GetSurfacesNum(),
                                                                  GetVolumesNum());
    printf("***   Physical dim max=%4d, dim min=%4d                      ***\n",GetMaxDim(),GetMinDim());

    printf("***   Domain=%10s                                        ***\n",_Domain.c_str());
    printf("***   tolerance=%14.6e, size=%14.6e            ***\n",_tolerance,_Size);
    printf("***   Input geo file= %-40s ***\n",_GeoFileName.c_str());
    printf("***   Output geo file= %-40s***\n",_NewGeoFileName.c_str());
    switch(_JobType){
    case JobType::RECTANGLE:
        printf("***   LeftBC   lines=%8d, RightBC lines=%8d          ***\n",(int)_LeftLineIDSet.size(),(int)_RightLineIDSet.size());
        printf("***   BottomBC lines=%8d, TopBC   lines=%8d          ***\n",(int)_BottomLineIDSet.size(),(int)_TopLineIDSet.size());
        break;
    case JobType::CUBIC:
        printf("***   LeftBC   surfaces=%8d, RightBC surfaces=%8d    ***\n",(int)_LeftSurfaceIDSet.size(),(int)_RightSurfaceIDSet.size());
        printf("***   BottomBC surfaces=%8d, TopBC   surfaces=%8d    ***\n",(int)_BottomSurfaceIDSet.size(),(int)_TopSurfaceIDSet.size());
        printf("***   BackBC   surfaces=%8d, FrontBC surfaces=%8d    ***\n",(int)_BackSurfaceIDSet.size(),(int)_FrontSurfaceIDSet.size());
        break;
    default:
        break;
    }
    cout<<"******************************************************************"<<endl;
}