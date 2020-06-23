#include "GeoReader.h"

void GeoReader::RunJobForCubic(){
    ofstream out;

    _LeftSurfaceIDSet.clear();_RightSurfaceIDSet.clear();
    _BottomSurfaceIDSet.clear();_TopSurfaceIDSet.clear();
    _BackSurfaceIDSet.clear();_TopSurfaceIDSet.clear();
    
    int i,j;

    for(i=1;i<=_nSurfaces;++i){
        if(IsIthSurfaceOnEdge(i,1,_Xmin)){
            _LeftSurfaceIDSet.push_back(i);
        }
        if(IsIthSurfaceOnEdge(i,1,_Xmax)){
            _RightSurfaceIDSet.push_back(i);
        }
        //**************************
        if(IsIthSurfaceOnEdge(i,2,_Ymin)){
            _BottomSurfaceIDSet.push_back(i);
        }
        if(IsIthSurfaceOnEdge(i,2,_Ymax)){
            _TopSurfaceIDSet.push_back(i);
        }
        //**************************
        if(IsIthSurfaceOnEdge(i,3,_Zmin)){
            _BackSurfaceIDSet.push_back(i);
        }
        if(IsIthSurfaceOnEdge(i,3,_Zmax)){
            _FrontSurfaceIDSet.push_back(i);
        }
    }
    out.open(_NewGeoFileName,ios::out);
    if(!out.is_open()){
        cout<<"******************************************************************"<<endl;
        printf("***   can\'t write to %-30s file !!!   ***\n",_NewGeoFileName.c_str());
        cout<<"****   make sure you have the write permission !!!             ***"<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
        cout<<"******************************************************************"<<endl;
        abort();
    }

    out<<"dx="<<_Size<<";\n";

    // write out the Point information
    for(i=1;i<=_nNodes;++i){
        out<<"Point ("<<i<<")={";
        out<<scientific<<setprecision(6)<<GetIthNodeJthCoord(i,1)<<",";
        out<<scientific<<setprecision(6)<<GetIthNodeJthCoord(i,2)<<",";
        out<<scientific<<setprecision(6)<<GetIthNodeJthCoord(i,3)<<",dx};\n";
    }
    out<<"\n\n";

    // write out the Line information
    for(i=1;i<=_nLines;++i){
        out<<"Line ("<<i<<")={"<<GetIthLineJthNodeID(i,1)<<","<<GetIthLineJthNodeID(i,2)<<"};\n";
    }
    out<<"\n\n";

    // write out the line loop
    for(i=1;i<=_nLineLoops;++i){
        out<<"Line Loop ("<<i<<")={";
        out<<GetIthLineLoopJthLineID(i,1);
        for(j=2;j<=GetIthLineLoopLength(i);++j){
            out<<","<<GetIthLineLoopJthLineID(i,j);
        }
        out<<"};\n";
        // for plane surface and physical surface
        //Plane Surface (1) = {1}; Physical Surface (1) = {1};
        out<<"Plane Surface ("<<i<<")={"<<i<<"}; ";
        out<<"Physical Surface ("<<i<<")={"<<i<<"};\n";
    }
    out<<"\n\n";

    // write out the surface loop
    for(i=1;i<=_nSurfaceLoops;++i){
        out<<"Surface Loop ("<<i<<")={";
        out<<GetIthSurfaceLoopJthSurfaceID(i,1);
        for(j=2;j<=GetIthSurfaceLoopLength(i);++j){
            out<<","<<GetIthSurfaceLoopJthSurfaceID(i,j);
        }
        out<<"};\n";
        // write out volume and physical volume
        out<<"Volume ("<<i<<")={"<<i<<"}; ";
        out<<"Physical Volume ("<<i<<")={"<<i<<"};\n";
    }
    out<<"\n\n";

    // write out the left line set 
    if(_LeftSurfaceIDSet.size()>0){
        out<<"Physical Surface (\"left\")={";
        out<<_LeftSurfaceIDSet[0];
        for(i=1;i<(int)_LeftSurfaceIDSet.size();++i){
            out<<","<<_LeftSurfaceIDSet[i];
        }
        out<<"};\n\n";
    }
    // write out the right line set 
    if(_RightSurfaceIDSet.size()>0){
        out<<"Physical Surface (\"right\")={";
        out<<_RightSurfaceIDSet[0];
        for(i=1;i<(int)_RightSurfaceIDSet.size();++i){
            out<<","<<_RightSurfaceIDSet[i];
        }
        out<<"};\n\n";
    }
    // write out the bottom line set
    if(_BottomSurfaceIDSet.size()>0){
        out<<"Physical Surface (\"bottom\")={";
        out<<_BottomSurfaceIDSet[0];
        for(i=1;i<(int)_BottomSurfaceIDSet.size();++i){
            out<<","<<_BottomSurfaceIDSet[i];
        }
        out<<"};\n\n";
    }
    // write out the top line set
    if(_TopSurfaceIDSet.size()>0){
        out<<"Physical Surface (\"top\")={";
        out<<_TopSurfaceIDSet[0];
        for(i=1;i<(int)_TopSurfaceIDSet.size();++i){
            out<<","<<_TopSurfaceIDSet[i];
        }
        out<<"};\n\n";
    }

    // write out the back surface set
    if(_BackSurfaceIDSet.size()>0){
        out<<"Physical Surface (\"back\")={";
        out<<_BackSurfaceIDSet[0];
        for(i=1;i<(int)_BackSurfaceIDSet.size();++i){
            out<<","<<_BackSurfaceIDSet[i];
        }
        out<<"};\n\n";
    }
    // write out the front surface set
    if(_FrontSurfaceIDSet.size()>0){
        out<<"Physical Surface (\"front\")={";
        out<<_FrontSurfaceIDSet[0];
        for(i=1;i<(int)_FrontSurfaceIDSet.size();++i){
            out<<","<<_FrontSurfaceIDSet[i];
        }
        out<<"};\n\n";
    }

    out.close();

}