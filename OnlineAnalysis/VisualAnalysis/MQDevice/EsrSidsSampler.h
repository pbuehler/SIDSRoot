/* 
 * File:   EsrSidsSampler.h
 * Author: winckler
 *
 * Created on August 6, 2014, 12:45 PM
 */

#ifndef ESRSIDSSAMPLER_H
#define	ESRSIDSSAMPLER_H


#include <vector>
#include <iostream>

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/timer/timer.hpp>

#include "FairMQDevice.h"
#include "FairMQLogger.h"
#include <memory>

template <typename TSamplerTask>
class EsrSidsSampler : public FairMQDevice
{
public:
    
    enum 
    {
      InputFile = FairMQDevice::Last,
      Branch,
      ParFile,
      EventRate
    };
    
    EsrSidsSampler();

    virtual ~EsrSidsSampler();
    
    void ResetEventCounter();
    virtual void ListenToCommands();
    virtual void SetProperty(const int key, const string& value, const int slot = 0);
    virtual string GetProperty(const int key, const string& default_ = "", const int slot = 0);
    virtual void SetProperty(const int key, const int value, const int slot = 0);
    virtual int GetProperty(const int key, const int default_ = 0, const int slot = 0);
    void SetDecayData(EsrInjData fDecayData);
    void SetTask(std::shared_ptr<TSamplerTask> task);
    
protected:

    //TSamplerTask* fSamplerTask;
    std::shared_ptr<TSamplerTask> fSpSamplerTask;
    string fInputFile;
    string fParFile;
    string fBranch;
    int fEventRate;
    int fEventCounter;
    unsigned int fNumEvents;
    
    virtual void Init();
    virtual void Run();
    
    
};

#include "EsrSidsSampler.tpl"

#endif	/* ESRSIDSSAMPLER_H */

