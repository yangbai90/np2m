#include "GeoReader.h"

void GeoReader::RunJobForRect(){
    ofstream out;

    _LeftLineIDSet.clear();_RightLineIDSet.clear();
    _BottomLineIDSet.clear();_TopLineIDSet.clear();
    
    int i,j;

    for(i=1;i<=_nLines;++i){
        if(IsIthLineOnEdge(i,1,_Xmin)){
            _LeftLineIDSet.push_back(i);
        }
        if(IsIthLineOnEdge(i,1,_Xmax)){
            _RightLineIDSet.push_back(i);
        }
        //**************************
        if(IsIthLineOnEdge(i,2,_Ymin)){
            _BottomLineIDSet.push_back(i);
        }
        if(IsIthLineOnEdge(i,2,_Ymax)){
            _TopLineIDSet.push_back(i);
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

    // write out the left line set 
    if(_LeftLineIDSet.size()>0){
        out<<"Physical Line(\"left\")={";
        out<<_LeftLineIDSet[0];
        for(i=1;i<(int)_LeftLineIDSet.size();++i){
            out<<","<<_LeftLineIDSet[i];
        }
        out<<"};\n\n";
    }
    // write out the right line set 
    if(_RightLineIDSet.size()>0){
        out<<"Physical Line(\"right\")={";
        out<<_RightLineIDSet[0];
        for(i=1;i<(int)_RightLineIDSet.size();++i){
            out<<","<<_RightLineIDSet[i];
        }
        out<<"};\n\n";
    }
    // write out the bottom line set
    if(_BottomLineIDSet.size()>0){
        out<<"Physical Line(\"bottom\")={";
        out<<_BottomLineIDSet[0];
        for(i=1;i<(int)_BottomLineIDSet.size();++i){
            out<<","<<_BottomLineIDSet[i];
        }
        out<<"};\n\n";
    }
    // write out the top line set
    if(_TopLineIDSet.size()>0){
        out<<"Physical Line(\"top\")={";
        out<<_TopLineIDSet[0];
        for(i=1;i<(int)_TopLineIDSet.size();++i){
            out<<","<<_TopLineIDSet[i];
        }
        out<<"};\n\n";
    }

    out.close();

}