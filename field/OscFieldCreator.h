/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    OscFieldCreator header file                  -----
// -----                Created 26/03/14  by M. Al-Turany              -----
// -------------------------------------------------------------------------


#ifndef OscFieldCreator_H
#define OscFieldCreator_H

#include "FairFieldFactory.h"

class OscFieldPar;

class FairField;

class OscFieldCreator : public FairFieldFactory 
{

 public:
  OscFieldCreator();
  virtual ~OscFieldCreator();
  virtual FairField* createFairField();
  virtual void SetParm();
  ClassDef(OscFieldCreator,1);
  
 protected:
  OscFieldPar* fFieldPar;
  
 private:
  OscFieldCreator(const OscFieldCreator&);
  OscFieldCreator& operator=(const OscFieldCreator&);

};
#endif //OscFieldCreator_H
