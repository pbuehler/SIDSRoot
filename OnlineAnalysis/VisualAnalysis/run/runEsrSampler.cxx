/* 
 * File:   runEsrSampler.cxx
 * Author: winckler
 *
 * Created on August 13, 2014, 2:59 PM
 */


#include <cstdlib>
#include <vector>
#include <iostream>
#include <csignal>



#include "TApplication.h"

#include "SidsGui.h"
#include "FairMQLogger.h"

#include "MQconfig.h"

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

int main(int argc, char** argv)
{
    if (argc != 13)
    {
        MQLOG(ERROR)<<"Number of argument incorrect.";
        MQLOG(INFO) <<"Script usage: startVisualAnalysis \t userName inputFile \n";
        MQLOG(INFO) << "Binary usage: EsrSidsSampler$dataFormat \tID inputFile \n"
             <<"\t\t userName treeName branch outputFile\n"
             << "\t\t eventRate numIoTreads\n"
             << "\t\toutputSocketType outputSndBufSize outputMethod outputAddress\n" << endl;
        return 1;
    }


    MQconfig SamplerConfig;

    int i = 1;
    SamplerConfig.SetID(argv[i]);
    ++i;
    
    SamplerConfig.SetInputFile(argv[i]);
    ++i;
    
    SamplerConfig.SetUserName(argv[i]);
    ++i;
    
    SamplerConfig.SetTreeName(argv[i]);
    ++i;
    
    SamplerConfig.SetBranch(argv[i]);
    ++i;
    
    SamplerConfig.SetOutputFile(argv[i]);
    ++i;
    
    int eventRate;
    stringstream(argv[i]) >> eventRate;
    SamplerConfig.SetEventRate(eventRate);
    ++i;

    int numIoThreads;
    stringstream(argv[i]) >> numIoThreads;
    SamplerConfig.SetNumIoThreads(numIoThreads);
    ++i;
    
    SamplerConfig.SetNumInputs(0);
    SamplerConfig.SetNumOutputs(1);

    SamplerConfig.SetOutputSocketType(argv[i]);
    ++i;
    int outputSndBufSize;
    stringstream(argv[i]) >> outputSndBufSize;
    SamplerConfig.SetOutputSndBufSize(outputSndBufSize);

    ++i;
    SamplerConfig.SetOutputMethod(argv[i]);
    ++i;
    SamplerConfig.SetOutputAddress(argv[i]);
    ++i;


    TApplication app("App", &argc, argv);
    MQLOG(INFO)<<"Run start";
    SidsGui* fSidsAnalysisGui = new SidsGui(gClient->GetRoot(), 1000, 600, SamplerConfig);
    fSidsAnalysisGui->MapWindow();
    app.Run();
    

    return 0;
}


