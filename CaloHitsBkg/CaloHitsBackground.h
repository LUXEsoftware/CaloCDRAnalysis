//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Dec  9 11:51:31 2020 by ROOT version 6.14/06
// from TTree Hits/Hits in sensitive detectors
// found on file: xaa.root
//////////////////////////////////////////////////////////

#ifndef CaloHitsBackground_h
#define CaloHitsBackground_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <THn.h>


// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class CaloHitsBackground {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t event;
   Int_t eventCount;
   
   Int_t           eventid;
   Int_t           detid;
   Int_t           layerid;
   Int_t           cellx;
   Int_t           celly;
   Double_t        edep;
   Int_t           hitid;
   vector<int>     *track_list;
   vector<double>  *trackx;
   vector<double>  *tracky;
   vector<double>  *trackz;
   Double_t        weight;

   // List of branches
   TBranch        *b_eventid;   //!
   TBranch        *b_detid;   //!
   TBranch        *b_layerid;   //!
   TBranch        *b_cellx;   //!
   TBranch        *b_celly;   //!
   TBranch        *b_edep;   //!
   TBranch        *b_hitid;   //!
   TBranch        *b_track_list;   //!
   TBranch        *b_trackx;   //!
   TBranch        *b_tracky;   //!
   TBranch        *b_trackz;   //!
   TBranch        *b_weight;   //!
   
   
   TH3D* H_backgroundMap;
   TH3I* H_backgroundMapI;
   TH3D* H_backgroundMapF;
   
   
   TH2D* H_XY;  
   TH2D* H_XZ;  
   TH2D* H_YZ;  
   // TH2D* H_XE;
   // TH2D* H_ZE; 
   
   TH1D* H_Edep;
   TH2D* H_XY_Sp[21];
   
   THnF * hn;
   
   


   CaloHitsBackground(TTree *tree=0);
   virtual ~CaloHitsBackground();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString fout="test.root",double scale=1.);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void   Scale(TH1* H1,double scale);
   // virtual void   Scale(TH2* H1);
   // virtual void   Scale(TH3* H1);
   
   
};

#endif

#ifdef CaloHitsBackground_cxx
CaloHitsBackground::CaloHitsBackground(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      // TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("input/AllBackgroundHitTreeCalo.root");
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("input/backgroundFastSim.root");
	  
      if (!f || !f->IsOpen()) {
         // f = new TFile("input/AllBackgroundHitTreeCalo.root");
         f = new TFile("input/backgroundFastSim.root");
		 
      }
      f->GetObject("Hits",tree);

   }
   Init(tree);
}

CaloHitsBackground::~CaloHitsBackground()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CaloHitsBackground::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CaloHitsBackground::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void CaloHitsBackground::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   track_list = 0;
   trackx = 0;
   tracky = 0;
   trackz = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("eventid", &eventid, &b_eventid);
   fChain->SetBranchAddress("detid", &detid, &b_detid);
   fChain->SetBranchAddress("layerid", &layerid, &b_layerid);
   fChain->SetBranchAddress("cellx", &cellx, &b_cellx);
   fChain->SetBranchAddress("celly", &celly, &b_celly);
   fChain->SetBranchAddress("edep", &edep, &b_edep);
   fChain->SetBranchAddress("hitid", &hitid, &b_hitid);
   fChain->SetBranchAddress("track_list", &track_list, &b_track_list);
   fChain->SetBranchAddress("trackx", &trackx, &b_trackx);
   fChain->SetBranchAddress("tracky", &tracky, &b_tracky);
   fChain->SetBranchAddress("trackz", &trackz, &b_trackz);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   Notify();
  
  
    Int_t bins[4] = {115, 11, 21, 1500};
    Double_t xmin[4] = {0.,0.,0.,0.};
    Double_t xmax[4] = {115., 11., 21., 1500.};
    // THnSparseF* hs = new THnSparseF("hs", "hs", 4, bins, xmin, xmax);
	hn = new THnF("hn", "hn", 4, bins, xmin, xmax);
  
  
	   
	H_backgroundMap=new TH3D("backgroundMap","backgroundMap",115,0,115,11,0,11,21,0,21); 
	H_backgroundMap->Sumw2();
	
	H_backgroundMapI=new TH3I("backgroundMapI","backgroundMapI",115,0,115,11,0,11,21,0,21); 
	H_backgroundMapI->Sumw2();
	
	
	H_backgroundMapF=new TH3D("backgroundMapF","backgroundMapF",115,0,115,11,0,11,21,0,21); 
	H_backgroundMapF->Sumw2();
	
	
	H_backgroundMap->GetXaxis()->SetTitle("X Pad");
	H_backgroundMap->GetYaxis()->SetTitle("Y Pad");
	H_backgroundMap->GetZaxis()->SetTitle("Z Layer ID");
	
	
	H_XY  =new TH2D("XY","XY",115,0,115,11,0,11);
	H_XY->GetXaxis()->SetTitle("X Pad");
	H_XY->GetYaxis()->SetTitle("Y Pad");	
	
	
	H_XZ  =new TH2D("XZ","XZ",115,0,115,21,0,21);
	H_XZ->GetXaxis()->SetTitle("X Pad");
	H_XZ->GetYaxis()->SetTitle("Z Layer ID");
	
	
	
	H_YZ  =new TH2D("YZ","YZ",11,0,11,21,0,21);
	H_YZ->GetXaxis()->SetTitle("Y Pad");
	H_YZ->GetYaxis()->SetTitle("Z Layer ID");
	
	// H_XE  =new TH2D("XE","XE",110,0,110,1000,0,0.025);
	// H_ZE  =new TH2D("ZE","ZE",20,0,20,1000,0,0.025);
	// H_ZE  =new TH2D("YE","ZE",10,0,10,1000,0,0.025);

	H_Edep=new TH1D("Edep","Edep",1000,0,0.05);
	H_Edep->GetXaxis()->SetTitle("All Cells Energy deposition (GeV)");
	H_Edep->GetYaxis()->SetTitle("Events/BX");
	
	
   for (int i=0;i<21;i++){
      H_XY_Sp[i]=new TH2D(Form("H_XY_Sp_%i",i),Form("H_XY_Sp_%i",i),115,0,115,11,0,11);
  	  H_XY_Sp[i]->GetXaxis()->SetTitle("X Pad");
  	  H_XY_Sp[i]->GetYaxis()->SetTitle("Y Pad");
	  
	  
   }
   
   
   
}

Bool_t CaloHitsBackground::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CaloHitsBackground::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CaloHitsBackground::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void CaloHitsBackground::Scale(TH1* H1,double scale)
{
for(int i=1;i<=H1->GetNcells();i++)H1->SetBinContent(i,H1->GetBinContent(i)/scale);
}

// void CaloHitsBackground::Scale(TH1* H1,double scale)
// {
// for(int i=1;i<=H1->GetNcells();i++)H1->SetBinContent(i,H1->GetBinContent(i)/Scale);
// }
//
// void CaloHitsBackground::Scale(TH1* H1,double scale)
// {
// for(int i=1;i<=H1->GetNcells();i++)H1->SetBinContent(i,H1->GetBinContent(i)/Scale);
// }

// virtual void   Scale(TH1* H1);
// virtual void   Scale(TH2* H1);
// virtual void   Scale(TH3* H1);



#endif // #ifdef CaloHitsBackground_cxx
