/* 
 * File:   MQconfig.cxx
 * Author: winckler
 * 
 * Created on August 14, 2014, 4:04 PM
 */


#include "MQconfig.h"

MQconfig::MQconfig() : fID(),
    fUserName(),
    fInputFile(),
    fOutputFile(),
    fTreeName(),
    fParameterFile(),
    fBranch(),
    fEventRate(0),
    fNumIoThreads(0),
    fNumInputs(0),
    fNumOutputs(0),
    fOutputSocketType(),
    fOutputSndBufSize(0),
    fOutputMethod(),
    fOutputAddress(),
    fPayloadFormat()
{
    fKeyStringValues.push_back("ID");
    fKeyStringValues.push_back("InputFile");
    fKeyStringValues.push_back("ParameterFile");
    fKeyStringValues.push_back("Branch");
    fKeyStringValues.push_back("OutputSocketType");
    fKeyStringValues.push_back("OutputMethod");
    fKeyStringValues.push_back("OutputAddress");
    fKeyStringValues.push_back("PayloadFormat");
    
    fKeyIntValues.push_back("OutputSndBufSize");
    fKeyIntValues.push_back("EventRate");
    fKeyIntValues.push_back("NumIoThreads");
    fKeyIntValues.push_back("NumInputs");
    fKeyIntValues.push_back("NumOutputs");
}

MQconfig::~MQconfig() {
}


void MQconfig::CheckSKey(string StringKey)
{
    bool notfound=true;
    for(unsigned int k(0);k<fKeyStringValues.size();++k)
    {
        if(fKeyStringValues[k]==StringKey)
        {
            notfound=false;
            break;
            
        }
        
    }
    
    if(notfound)
    {
        stringstream logmsg;
        logmsg<<"Given key '"<<StringKey<<"' is undefined.";
        cout<<logmsg.str()<<endl;
        cout << "Defined keys (with corresponding values) are :";
        map<string,string>::iterator itn = fParameterStringValues.begin();
        for (itn=fParameterStringValues.begin(); itn!=fParameterStringValues.end(); ++itn)
        cout << itn->first << " => " << itn->second << '\n';


    }
    
}

    
