/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                  OscDetectorList header file               -----
// -----                  M. Al-Turany   June 2014                     -----
// -------------------------------------------------------------------------


/** Defines unique identifier for all Osc detectors system **/
/** THis is needed for stack filtring **/

#ifndef OscDetectorList_H
#define OscDetectorList_H 1
// kSTOPHERE is needed for iteration over the enum. All detectors have to be put before.
enum DetectorId {kOscEsr, kSTOPHERE};

#endif
