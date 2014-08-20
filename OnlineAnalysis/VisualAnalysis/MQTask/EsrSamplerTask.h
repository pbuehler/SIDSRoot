/* 
 * File:   EsrSamplerTask.h
 * Author: winckler
 *
 * Created on August 6, 2014, 3:38 PM
 */

#ifndef ESRSAMPLERTASK_H
#define	ESRSAMPLERTASK_H

#include <iostream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>

#include "FairMQSamplerTask.h"
#include "EsrInjData.h"

template <typename TPayloadOut> 
class EsrSamplerTask : public FairMQSamplerTask
{
public:
    EsrSamplerTask(EsrInjData DecayData);
    virtual ~EsrSamplerTask();
    
    virtual InitStatus Init();
    virtual void Exec(Option_t* opt);
    
    void SetInputFile(string InputFile) {fInputFile=InputFile;}
    unsigned int GetNumEvents() {return fNumEvents;}
    
    bool ReadyToSend();
    
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & fDigiVector;
    }
    
    
protected:

    string fInputFile;
    unsigned int fNumEvents;
    EsrInjData fDecayData;
    bool fReadyToSend;
    
    vector<EsrInjData> fDigiVector;
    
    friend class boost::serialization::access;
};

#include "EsrSamplerTask.tpl"
#endif	/* ESRSAMPLERTASK_H */

