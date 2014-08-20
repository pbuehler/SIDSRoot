/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    OscCave  file                               -----
// -----                Created 26/03/14  by M. Al-Turany              -----
// -------------------------------------------------------------------------


#ifndef Cave_H
#define Cave_H

#include "FairModule.h"                 // for FairModule

#include "Rtypes.h"                     // for OscCave::Class, ClassDef, etc

class OscCave : public FairModule
{
  public:
    OscCave(const char* name, const char* Title="Exp Cave");
    OscCave();
    virtual ~OscCave();
    virtual void ConstructGeometry();


  private:
    Double_t world[3];
    ClassDef(OscCave,1) //PNDCaveSD
};

#endif //Cave_H

