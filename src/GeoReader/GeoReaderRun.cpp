#include "GeoReader.h"

void GeoReader::Run(int args,char *argv[]){
    string str,substr;
    bool HasHelper=false;
    bool HasPrint=false;
    bool HasDomain=false;
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
        else if(string(argv[2-1]).compare(0,4,".geo")==0){
            if(str.length()>4){
                _GeoFileName=str;
            }
            else{
                cout<<"*** Error: incorrect geo file name is given !!!                ***"<<endl;
                return;
            }
        }
    }
    else
    {
        if(string(argv[2-1]).compare(0,4,".geo")==0){
            if(str.length()>4){
                _GeoFileName=str;
            }
            else{
                cout<<"*** Error: incorrect geo file name is given !!!                ***"<<endl;
                return;
            }
        }
        for(int i=2;i<args;++i){
            str=string(argv[i]);
            if(str.compare("-help")==0){
                HasHelper=true;
                cout<<"***------------------------------------------------------------***"<<endl;
                cout<<"*** Warning: -help flage detected, ignore other flags!!!       ***"<<endl;
                cout<<"***------------------------------------------------------------***"<<endl;
                PrintHelper();
                return;
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
        }
    }


    if(HasHelper){
        PrintHelper();
        return;
    }


    if(!HasDomain){
        cout<<"*** Warning: no domain is assigned, then 'circle' is taken !!! ***"<<endl;
    }


    if(HasPrint){
        PrintInfo();
    }
}