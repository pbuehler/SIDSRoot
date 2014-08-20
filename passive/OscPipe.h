/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    OscPipe file                                -----
// -----                Created by M. Al-Turany  June 2014             -----
// -------------------------------------------------------------------------

#ifndef PIPE_H
#define PIPE_H

#include "FairModule.h"

class OscPipe : public FairModule {
  public:
    OscPipe(const char * name, const char *Title="Osc Pipe");
    OscPipe();

    virtual ~OscPipe();
    virtual void ConstructGeometry();
   
  ClassDef(OscPipe,1) //OscPIPE

};

#endif //PIPE_H

