/* 
 * File:   SidsDecayTxtField.h
 * Author: winckler
 *
 * Created on August 11, 2014, 2:53 PM
 */

#ifndef SIDSDECAYTXTFIELD_H
#define	SIDSDECAYTXTFIELD_H



#include <TGButton.h>
#include <TGButtonGroup.h>
#include <TGLabel.h>
#include <TGNumberEntry.h>
#include <TG3DLine.h>
#include <TApplication.h>
#include <stdlib.h>

class SidsDecayTxtField : public TGGroupFrame 
{

public:
   SidsDecayTxtField(const TGWindow *p, const char* name, Int_t DecayID=0);
   virtual ~SidsDecayTxtField();
   
   TGTextEntry *GetEntry() const { return fCoordX->GetNumberEntry(); }
   TGTextEntry *GetCoordX() const { return fCoordX->GetNumberEntry(); }
   TGTextEntry *GetCoordY() const { return fCoordY->GetNumberEntry(); }
   void SetCoordX(Int_t number){fCoordX->SetIntNumber(number);}
   void SetCoordY(Int_t number){fCoordY->SetIntNumber(number);}
   void ClearWindow();
   
   
   void GetDecayFreqField(char* val);
   void GetDecayTimeField(char* val);
   int GetDecayFreq() const {return fDecayFreq;}
   int GetDecayTime() const {return fDecayTime;}
   int GetDecayID() const {return fDecayID;}
   

protected:
   
   TGHorizontalFrame *fhorframe1; 
   TGNumberEntry *fCoordX;
   TGNumberEntry *fCoordY;
   TGLabel *flabelT;
   TGLabel *flabelF;
   
   Int_t fDecayID;
   
   int fDecayFreq;
   int fDecayTime;
   
   ClassDef(SidsDecayTxtField, 0);
};



#endif	/* SIDSDECAYTXTFIELD_H */

