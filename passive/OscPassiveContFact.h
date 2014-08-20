/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    OscPassiveContFact  file                    -----
// -----                Created 26/03/14  by M. Al-Turany              -----
// -------------------------------------------------------------------------


#ifndef PNDPASSIVECONTFACT_H
#define PNDPASSIVECONTFACT_H

#include "FairContFact.h"               // for FairContFact, etc
#include "Rtypes.h"                     // for OscPassiveContFact::Class, etc

class FairParSet;

class OscPassiveContFact : public FairContFact
{
  private:
    void setAllContainers();
  public:
    OscPassiveContFact();
    ~OscPassiveContFact() {}
    FairParSet* createContainer(FairContainer*);
    ClassDef( OscPassiveContFact,0) // Factory for all Passive parameter containers
};

#endif  /* !PNDPASSIVECONTFACT_H */
