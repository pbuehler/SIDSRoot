/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "OscEsrContFact.h"

#include "OscEsrGeoPar.h"

#include "FairRuntimeDb.h"

#include <iostream>

ClassImp(OscEsrContFact)

static OscEsrContFact gOscEsrContFact;

OscEsrContFact::OscEsrContFact()
  : FairContFact()
{
  /** Constructor (called when the library is loaded) */
  fName="OscEsrContFact";
  fTitle="Factory for parameter containers in libOscEsr";
  setAllContainers();
  FairRuntimeDb::instance()->addContFactory(this);
}

void OscEsrContFact::setAllContainers()
{
  /** Creates the Container objects with all accepted
      contexts and adds them to
      the list of containers for the OscEsr library.
  */

  FairContainer* p= new FairContainer("OscEsrGeoPar",
                                      "OscEsr Geometry Parameters",
                                      "TestDefaultContext");
  p->addContext("TestNonDefaultContext");

  containers->Add(p);
}

FairParSet* OscEsrContFact::createContainer(FairContainer* c)
{
  /** Calls the constructor of the corresponding parameter container.
      For an actual context, which is not an empty string and not
      the default context
      of this container, the name is concatinated with the context.
  */
  const char* name=c->GetName();
  FairParSet* p=NULL;
  if (strcmp(name,"OscEsrGeoPar")==0) {
    p=new OscEsrGeoPar(c->getConcatName().Data(),
                            c->GetTitle(),c->getContext());
  }
  return p;
}
