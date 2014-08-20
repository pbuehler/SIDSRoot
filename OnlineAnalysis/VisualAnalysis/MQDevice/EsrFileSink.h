/* 
 * File:   EsrFileSink.h
 * Author: winckler
 *
 * Created on August 15, 2014, 11:46 AM
 */

#ifndef ESRFILESINK_H
#define	ESRFILESINK_H

#include <iostream>

#include "Rtypes.h"
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TVector3.h"
#include "TString.h"

#include "FairMQDevice.h"
#include "FairMQLogger.h"
#include "EsrInjData.h"

#include "TMessage.h"

#ifndef __CINT__
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/serialization/access.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#endif //__CINT__

class TVector3;
class TFile;
class TTree;
class TClonesArray;

template <typename TPayloadIn>
class EsrFileSink : public FairMQDevice
{
  public:
    EsrFileSink();
    virtual ~EsrFileSink();
    virtual void InitOutputFile(TString defaultId = "100");

    template <class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& fEsrDataVector;
    }

  protected:
    virtual void Run();

  private:
    TFile* fOutFile;
    TTree* fTree;
    TClonesArray* fOutput;
    EsrInjData fDecayData;
#ifndef __CINT__ // for BOOST serialization
    friend class boost::serialization::access;
    std::vector<EsrInjData> fEsrDataVector;
    bool fHasBoostSerialization;
#endif // for BOOST serialization
};

////////// Template implementation of Run() in EsrFileSink.tpl :
#include "EsrFileSink.tpl"


#endif	/* ESRFILESINK_H */

