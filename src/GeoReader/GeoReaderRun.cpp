#include "GeoReader.h"

void GeoReader::Run(int args,char *argv[]){
    string str,substr;
    bool HasHelper=false;
    bool HasPrint=true;
    bool HasDomain=false;
    bool HasGeoFile=false;
    vector<double> numbers;
    if(args==1){
        cout<<"******************************************************************"<<endl;
        cout<<"*** Error: no geo file name is given !!!                       ***"<<endl;
        return;
    }
    else if(args==2){
        str=string(argv[2-1]);
        substr=str.substr(str.length()-4);
        if(str.compare(0,5,"-help")==0){
            PrintHelper();
            return;
        }
        else{
            cout<<"***------------------------------------------------------------***"<<endl;
            cout<<"*** Error: invalid options for np2m, please check the helper!!!***"<<endl;
            cout<<"***------------------------------------------------------------***"<<endl;
            return;
        }
    }
    else
    {
        for(int i=1;i<args;++i){
            str=string(argv[i]);
            if(str.compare("-help")==0){
                HasHelper=true;
                cout<<"***------------------------------------------------------------***"<<endl;
                cout<<"*** Warning: -help flage detected, ignore other flags!!!       ***"<<endl;
                cout<<"***------------------------------------------------------------***"<<endl;
                PrintHelper();
                return;
            }
            else if(str.compare("-i")==0&&str.size()==2){
                if(i==args-1){
                    cout<<"***------------------------------------------------------------***"<<endl;
                    cout<<"*** Error: no geo file name found after '-i'                   ***"<<endl;
                    cout<<"***------------------------------------------------------------***"<<endl;
                    return;
                }
                else{
                    substr=argv[i+1];
                    if(substr.compare(substr.length()-4,4,".geo")==0){
                        if(substr.length()>4){
                            _GeoFileName=substr;
                            _NewGeoFileName="new"+_GeoFileName;
                            HasGeoFile=true;
                        }
                        else{
                            cout<<"***------------------------------------------------------------***"<<endl;
                            cout<<"*** Error: incorrect geo file name is given !!!                ***"<<endl;
                            cout<<"***------------------------------------------------------------***"<<endl;
                            return;
                        }
                    }
                    else{
                        cout<<"***------------------------------------------------------------***"<<endl;
                        cout<<"*** Error: incorrect geo file name is given !!!                ***"<<endl;
                        cout<<"***------------------------------------------------------------***"<<endl;
                        return;
                    }
                }
            }
            else if(str.compare("-print")==0){
                if(i==args-1){
                    HasPrint=true;
                }
                else{
                    if(string(argv[i+1]).compare("true")==0||
                       string(argv[i+1]).compare("TRUE")==0){
                        HasPrint=true;
                    }
                    else if(string(argv[i+1]).compare("false")==0||
                            string(argv[i+1]).compare("FALSE")==0){
                        HasPrint=false;
                    }
                    else{
                        HasPrint=true;
                    }
                }
            }
            else if(str.compare("-domain")==0){
                
                if(i==args-1){
                    cout<<"*** Error: no flag found after '-domain' !!!                   ***"<<endl;
                    return;
                }
                else{
                    if(string(argv[i+1]).compare("circle")==0||
                       string(argv[i+1]).compare("CIRCLE")==0){
                        _JobType=JobType::CIRCLE;
                        _Domain="circle";
                        HasDomain=true;
                    }
                    else if(string(argv[i+1]).compare("rect")==0||
                            string(argv[i+1]).compare("RECT")==0){
                        _JobType=JobType::RECTANGLE;
                        _Domain="rect";
                        HasDomain=true;
                    }
                    else if(string(argv[i+1]).compare("sphere")==0||
                            string(argv[i+1]).compare("SPHERE")==0){
                        _JobType=JobType::SPHERE;
                        _Domain="sphere";
                        HasDomain=true;
                    }
                    else if(string(argv[i+1]).compare("cubic")==0||
                            string(argv[i+1]).compare("CUBIC")==0){
                        _JobType=JobType::CUBIC;
                        _Domain="cubic";
                        HasDomain=true;
                    }
                    else if(string(argv[i+1]).compare("cylinder")==0||
                            string(argv[i+1]).compare("CYLINDER")==0){
                        _JobType=JobType::CYLINDER;
                        _Domain="cylinder";
                        HasDomain=true;
                    }
                    else{
                        cout<<"*** Error: unsupported flag after '-domain' !!!                ***"<<endl;
                        return;
                    }
                }
            }
            else if(str.compare("-tol")==0){
                if(i==args-1){
                    cout<<"*** Error: no number found after -tol !!!                      ***"<<endl;
                    cout<<"******************************************************************"<<endl;
                    cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
                    cout<<"******************************************************************"<<endl;
                    abort();
                }
                else{
                    substr=string(argv[i+1]);
                    numbers=SplitNumVecFromString(substr);
                    if(numbers.size()<1){
                        cout<<"*** Error: no number found after -tol !!!                      ***"<<endl;
                        cout<<"******************************************************************"<<endl;
                        cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
                        cout<<"******************************************************************"<<endl;
                        abort();
                    }
                    else{
                        if(numbers[0]<1.0e-13){
                            cout<<"*** Error: invalid value for -tol option !!!                   ***"<<endl;
                            cout<<"******************************************************************"<<endl;
                            cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
                            cout<<"******************************************************************"<<endl;
                            abort();
                        }
                        SetTol(numbers[0]);
                    }
                }
            }
            else if(str.compare("-size")==0){
                if(i==args-1){
                    cout<<"*** Error: no number found after -size !!!                     ***"<<endl;
                    cout<<"******************************************************************"<<endl;
                    cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
                    cout<<"******************************************************************"<<endl;
                    abort();
                }
                else{
                    substr=string(argv[i+1]);
                    numbers=SplitNumVecFromString(substr);
                    if(numbers.size()<1){
                        cout<<"*** Error: no number found after -size !!!                     ***"<<endl;
                        cout<<"******************************************************************"<<endl;
                        cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
                        cout<<"******************************************************************"<<endl;
                        abort();
                    }
                    else{
                        if(numbers[0]<1.0e-13){
                            cout<<"*** Error: invalid value for -size option !!!                  ***"<<endl;
                            cout<<"******************************************************************"<<endl;
                            cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
                            cout<<"******************************************************************"<<endl;
                            abort();
                        }
                        SetSize(numbers[0]);
                    }
                }
            }
        }
    }


    if(HasHelper){
        PrintHelper();
        return;
    }

    if(!HasGeoFile){
        cout<<"***------------------------------------------------------------***"<<endl;
        cout<<"*** Error: no geo file name is given, '-i xx.geo' is required!!***"<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
        cout<<"******************************************************************"<<endl;
        abort();
    }


    if(!HasDomain){
        cout<<"***------------------------------------------------------------***"<<endl;
        cout<<"*** Error: no domain is assigned, -domain xxx is required !!!  ***"<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
        cout<<"******************************************************************"<<endl;
        abort();
    }


    // First we read the geofile
    ReadGeoFile();

    switch(_JobType){
    case JobType::CIRCLE:
        RunJobForCircle();
        break;
    case JobType::RECTANGLE:
        RunJobForRect();
        break;
    case JobType::CUBIC:
        RunJobForCubic();
        break;
    default:
        cout<<"******************************************************************"<<endl;
        cout<<"*** Error: unsupported job type, please check the helper !!!   ***"<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"*** np2m exit due to some errors !!!                           ***"<<endl;
        cout<<"******************************************************************"<<endl;
        abort();
    }



    if(HasPrint){
        PrintInfo();
    }
}