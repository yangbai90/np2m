#include "GeoReader.h"

void GeoReader::ReadGeoFile(){
    string line,str,substr;
    vector<double> numbers;
    vector<string> strvec;

    ifstream in;
	in.open(_GeoFileName.c_str(),ios::in);

	_Xmax=-1.0e16;_Xmin=1.0e16;
	_Ymax=-1.0e16;_Ymin=1.0e16;
	_Zmax=-1.0e16;_Zmin=1.0e16;
    double xtol,ytol,ztol;
    xtol=0.0;ytol=0.0;ztol=0.0;

    while(!in.is_open()){
		cout<<"**** Error: can't open file(="<<_GeoFileName<<")!!!"<<endl;
		cout<<"**** input the correct filename=";
		cin>>_GeoFileName;
		in.open(_GeoFileName.c_str(),ios::in);
	}

    _NodeCoords.clear();_nNodes=0;
    _Line.clear();_nLines=0;
    _LineLoop.clear();_nLineLoops=0;
    while(!in.eof()){
        getline(in,line);
        if(line.find("Point (")!=string::npos){
            numbers=SplitNumVecFromString(line);
            if(numbers.size()!=4){
                // Data format:
				// node id, x, y, z
				cout<<"**** Error: Points must have three components!!!"<<endl;
				abort();
            }
            else{
                _NodeCoords.push_back(numbers[1]);
                _NodeCoords.push_back(numbers[2]);
                _NodeCoords.push_back(numbers[3]);

                _nNodes+=1;
                xtol+=numbers[1];
                ytol+=numbers[2];
                ztol+=numbers[3];

                if(numbers[1]>_Xmax) _Xmax=numbers[1];
				if(numbers[1]<_Xmin) _Xmin=numbers[1];

				if(numbers[2]>_Ymax) _Ymax=numbers[2];
				if(numbers[2]<_Ymin) _Ymin=numbers[2];

				if(numbers[3]>_Zmax) _Zmax=numbers[3];
				if(numbers[3]<_Zmin) _Zmin=numbers[3];
            }
        }
        else if(line.find("Line (")!=string::npos){
            numbers=SplitNumVecFromString(line);
            if(numbers.size()!=3){
                cout<<"**** Error: Line ()={} must have 3 numbers"<<endl;
				abort();
            }
            else{
				_Line.push_back(int(numbers[1]));
				_Line.push_back(int(numbers[2]));
				_nLines+=1;
            }
        }
        else if(line.find("Line Loop (")!=string::npos){
            // Read line loop
			numbers=SplitNumVecFromString(line);
            if(numbers.size()<4){
                cout<<"**** Error: Line Loop () must have at least 4 numbers!!!"<<endl;
				abort();
            }
            else{
                vector<int> lineid;
				lineid.clear();
                for(unsigned int i=1;i<numbers.size();i++){
                    lineid.push_back(int(numbers[i]));
                }
                _LineLoop.push_back(lineid);
                _nLineLoops+=1;
            }
        }
        else if(line.find("Plane Surface (")!=string::npos){
            // Read Plane surface information
			strvec=SplitStringVecBySymbol(line,';');
			numbers=SplitNumVecFromString(strvec[0]);
            if(numbers.size()<2){
                cout<<"**** Error: Plane Surface () must have 2 numbers!!!"<<endl;
				abort();
            }
            else{
                
            }
        }
    }

}