/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef NEWDETECTORGEOPAR_H
#define NEWDETECTORGEOPAR_H

#include "FairParGenericSet.h"

class TObjArray;
class FairParamList;

class OscEsrGeoPar       : public FairParGenericSet
{
  public:

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoSensNodes;

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoPassNodes;

    OscEsrGeoPar(const char* name="OscEsrGeoPar",
                      const char* title="OscEsr Geometry Parameters",
                      const char* context="TestDefaultContext");
    ~OscEsrGeoPar(void);
    void clear(void);
    void putParams(FairParamList*);
    Bool_t getParams(FairParamList*);
    TObjArray* GetGeoSensitiveNodes() {return fGeoSensNodes;}
    TObjArray* GetGeoPassiveNodes()   {return fGeoPassNodes;}

  private:
    OscEsrGeoPar(const OscEsrGeoPar&);
    OscEsrGeoPar& operator=(const OscEsrGeoPar&);

    ClassDef(OscEsrGeoPar,1)
};

#endif
