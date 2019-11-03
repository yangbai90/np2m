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

    cout<<"******************************************************************"<<endl;
}