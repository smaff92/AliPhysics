#ifndef ALIEMCALTRACKINGQATASK_H
#define ALIEMCALTRACKINGQATASK_H

#include "AliAnalysisTaskEmcal.h"

class AliParticleContainer;
class THnSparse;
class TH3;

class AliEmcalTrackingQATask : public AliAnalysisTaskEmcal {

 public:
  AliEmcalTrackingQATask();
  AliEmcalTrackingQATask(const char *name); 
  virtual ~AliEmcalTrackingQATask();

  void                   UserCreateOutputObjects();
  void                   SetGeneratorLevelName(const char* name);
  void                   SetDetectorLevelName(const char* name);
  void                   SetSelectHIJING(Bool_t s)  {fSelectHIJING=s;}

 protected:
  Bool_t                 FillHistograms()                               ;
  void                   ExecOnce()                                     ;
  void                   GenerateHistoBins()                            ;
  void                   AllocateFindableParticlesTHnSparse()           ;
  void                   AllocateMatchedParticlesTHnSparse()            ;
  void                   FillFindableParticlesTHnSparse(Double_t cent, Double_t partEta, Double_t partPhi, Double_t partPt);
  void                   FillMatchedParticlesTHnSparse(Double_t cent, Double_t partEta, Double_t partPhi, Double_t partPt,
						       Double_t trackEta, Double_t trackPhi, Double_t trackPt, Byte_t trackType);

  // Task configuration
  Bool_t                fSelectHIJING          ; //  select HIJING particles

  // Service fields (non-streamed)
  AliParticleContainer* fGeneratorLevel        ; //! generator level container
  AliParticleContainer* fDetectorLevel         ; //! detector level container
  Int_t                 fNPtHistBins           ; //! number of pt bins
  Double_t*             fPtHistBins            ; //! pt bins
  Int_t                 fNEtaHistBins          ; //! number of eta bins
  Double_t*             fEtaHistBins           ; //! eta bins
  Int_t                 fNPhiHistBins          ; //! number of phi bins
  Double_t*             fPhiHistBins           ; //! phi bins
  Int_t                 fNCentHistBins         ; //! number of cent bins
  Double_t*             fCentHistBins          ; //! cent bins
  Int_t                 fNPtResHistBins        ; //! number of pt res bins
  Double_t*             fPtResHistBins         ; //! pt res bins
  Int_t                 fNIntegerHistBins      ; //! number of integer bins
  Double_t*             fIntegerHistBins       ; //! integer bins


  // Histograms
  TH3***                fTracksAll             ; //! all tracks
  TH3***                fTracksSelected        ; //! selected tracks (e.g. remove injected signal in HIJING productions)
  TH3**                 fParticlesAllPhysPrim  ; //! all physical primary particles
  TH3**                 fParticlesSelected     ; //! selected physical primary particles (e.g. remove injected signal in HIJING productions)
  THnSparse*            fParticlesFindable     ; //! findable physical primary particles (use PDG and charge selection)
  THnSparse*            fParticlesMatched      ; //! primary particles matched to detector level tracks
  
 private:
  AliEmcalTrackingQATask(const AliEmcalTrackingQATask&);            // not implemented
  AliEmcalTrackingQATask &operator=(const AliEmcalTrackingQATask&); // not implemented

  ClassDef(AliEmcalTrackingQATask, 1) // Track QA task (efficiency and pt resolution)
};
#endif
