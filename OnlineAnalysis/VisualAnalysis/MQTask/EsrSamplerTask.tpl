/* 
 * File:   EsrSamplerTask.tpl
 * Author: winckler
 *
 * Created on August 6, 2014, 5:47 PM
 */


template <typename TPayloadOut>
EsrSamplerTask<TPayloadOut>::EsrSamplerTask(EsrInjData DecayData) : FairMQSamplerTask("Load ESR decay evt class"),
        fInputFile(),
        fNumEvents(0),
        fReadyToSend(false),
        fDecayData(DecayData)
{
    
}



template <typename TPayloadOut> 
EsrSamplerTask<TPayloadOut>::~EsrSamplerTask()
{
    
}


template <typename TPayloadOut>
InitStatus EsrSamplerTask<TPayloadOut>::Init()
{
    //fSidsAnalysisGui = new SidsGui(gClient->GetRoot(), 700, 400);
    //fSidsAnalysisGui->MapWindow();
    //fReadyToSend=true;
    return kSUCCESS;
}

template <typename TPayloadOut>
void EsrSamplerTask<TPayloadOut>::Exec(Option_t* opt)
{
    bool printinfo=true;
    if (printinfo)
    {
        LOG(INFO)<< "------------------------------------------";
        LOG(INFO)<<"Event Index = "<< fEventIndex ;
    }
    /// convert data : CbmRoot -> Fles
    fDigiVector.push_back(fDecayData);

    /// boost serialization and create FairMQ message
    std::ostringstream buffer;
    TPayloadOut OutputArchive(buffer);
    OutputArchive << fDigiVector;
    int size=buffer.str().length();
    fOutput = fTransportFactory->CreateMessage(size);
    std::memcpy(fOutput->GetData(), buffer.str().c_str(), size);
    // delete the vector content
    if(fDigiVector.size()>0)
        fDigiVector.clear();
    else LOG(INFO)<<"Message empty";
    //fReadyToSend=true;
}


template <typename TPayloadOut>
bool EsrSamplerTask<TPayloadOut>::ReadyToSend()
{
    
    return fReadyToSend;
}
