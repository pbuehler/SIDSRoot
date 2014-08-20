/* 
 * File:   SidsDecayTxtField.cxx
 * Author: winckler
 * 
 * Created on August 11, 2014, 2:53 PM
 */

#include "SidsDecayTxtField.h"

SidsDecayTxtField::SidsDecayTxtField(const TGWindow *p, const char* name, Int_t DecayID) : TGGroupFrame(p,name), 
        fhorframe1(NULL), fCoordX(NULL), fCoordY(NULL), flabelT(NULL), flabelF(NULL),
        fDecayID(DecayID), fDecayFreq(0), fDecayTime(0)
{
    SetTitlePos(TGGroupFrame::kCenter);
    fhorframe1 = new TGHorizontalFrame(this, 200, 50);
    
    //freq
    flabelF = new TGLabel(fhorframe1, "Rev. Freq. (bin)");
    fhorframe1->AddFrame(flabelF, new TGLayoutHints( kLHintsExpandY,2,2,2,2));
    
    fCoordX = new TGNumberEntry(fhorframe1, 0, 6, fDecayID, TGNumberFormat::kNESInteger);
    fhorframe1->AddFrame(fCoordX, new TGLayoutHints( kLHintsExpandY,6,2,2,2));

    //time
    flabelT = new TGLabel(fhorframe1, "Time (bin)");
    fhorframe1->AddFrame(flabelT, new TGLayoutHints( kLHintsExpandY,20,2,2,2));
    
    fCoordY = new TGNumberEntry(fhorframe1, 0, 6, fDecayID, TGNumberFormat::kNESInteger);
    fhorframe1->AddFrame(fCoordY, new TGLayoutHints(kLHintsExpandY,6,2,2,2));
    
    //parent frame
    AddFrame(fhorframe1, new TGLayoutHints(kLHintsExpandX, 0, 0, 2, 2));
    
    
}

SidsDecayTxtField::~SidsDecayTxtField() 
{
    
}

void SidsDecayTxtField::ClearWindow()
{
    fhorframe1->RemoveFrame(fCoordX);
    fhorframe1->RemoveFrame(fCoordY);
    fhorframe1->RemoveFrame(flabelT);
    fhorframe1->RemoveFrame(flabelF);
    fCoordX->UnmapWindow();
    fCoordY->UnmapWindow();
    flabelF->UnmapWindow();
    flabelT->UnmapWindow();
    
    RemoveFrame(fhorframe1);
    
    RemoveAll();
    Cleanup();
    UnmapWindow();
}


void SidsDecayTxtField::GetDecayFreqField(char* val)
{
    int value=atoi(val);
    fDecayFreq=value;
}


void SidsDecayTxtField::GetDecayTimeField(char* val)
{
    int value=atoi(val);
    fDecayTime=value;
    
}

ClassImp(SidsDecayTxtField)




