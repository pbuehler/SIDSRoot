/* 
 * File:   EsrFileSink.tpl
 * Author: winckler
 *
 * Created on August 15, 2014, 11:57 AM
 */


template <typename TPayloadIn>
EsrFileSink<TPayloadIn>::EsrFileSink() :
    fOutFile(NULL),
    fTree(NULL),
    fOutput(NULL)
{
    
}

template <typename TPayloadIn>
EsrFileSink<TPayloadIn>::~EsrFileSink()
{
    /*fTree->Write();
    fOutFile->Close();
    if (fEsrDataVector.size() > 0)
        fEsrDataVector.clear();*/
}

template <typename TPayloadIn>
void EsrFileSink<TPayloadIn>::InitOutputFile(TString defaultId)
{
    
    /*
    fOutput = new TClonesArray("FairTestDetectorHit");
    char out[256];
    sprintf(out, "Esrfilesink%s.root", defaultId.Data());

    fOutFile = new TFile(out, "recreate");
    fTree = new TTree("MQOut", "Test output");
    fTree->Branch("Output", "TClonesArray", &fOutput, 64000, 99);
     */
}




// ----- Implementation of EsrFileSink::Run() with Boost transport data format -----

template <typename TPayloadIn>
void EsrFileSink<TPayloadIn>::Run()
{
    
    LOG(INFO) << ">>>>>>> Run <<<<<<<";

    boost::thread rateLogger(boost::bind(&FairMQDevice::LogSocketRates, this));
    int receivedMsgs = 0;
    bool received = false;

    if(fState == RUNNING)
        cout<<"state = running"<<endl;
    else cout<<"state = not running"<<endl;
    
    while (fState == RUNNING)
    {
        FairMQMessage* msg = fTransportFactory->CreateMessage();
        received = fPayloadInputs->at(0)->Receive(msg);

        if (received)
        {
            receivedMsgs++;
            std::string msgStr(static_cast<char*>(msg->GetData()), msg->GetSize());
            std::istringstream ibuffer(msgStr);
            TPayloadIn InputArchive(ibuffer);

            try
            {
                InputArchive >> fEsrDataVector;
            }
            catch (boost::archive::archive_exception& e)
            {
                LOG(ERROR) << e.what();
            }

            int numInput = fEsrDataVector.size();
            for(int i(0);i<numInput;i++)
            {
                fDecayData=fEsrDataVector[i];
                vector<EsrDecayEvent> DecayList=fDecayData.GetECData();
                std::cout<<"---------------- PRINT DECAYS ------------"<<std::endl;
                for(unsigned int j(0);j<DecayList.size();j++)
                {
                    DecayList[j].PrintEvent();        
                }
            }

            //fTree->Fill();
            received = false;
        }
        delete msg;
        if (fEsrDataVector.size() > 0)
            fEsrDataVector.clear();
    }

    LOG(INFO) << "I've received " << receivedMsgs << " messages!";
    boost::this_thread::sleep(boost::posix_time::milliseconds(5000));

    try {
        rateLogger.interrupt();
        rateLogger.join();
    } catch(boost::thread_resource_error& e) {
        LOG(ERROR) << e.what();
    }
    
}

