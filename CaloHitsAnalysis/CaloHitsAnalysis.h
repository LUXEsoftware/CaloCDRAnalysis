//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Dec  9 11:51:31 2020 by ROOT version 6.14/06
// from TTree Hits/Hits in sensitive detectors
// found on file: xaa.root
//////////////////////////////////////////////////////////

#ifndef CaloHitsAnalysis_h
#define CaloHitsAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>


class CaloHitsAnalysis {
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
   
   
   TH1D* H_NEvents;
   
   TH1D* H_Shower_E;
   TH1D* H_Shower_E_more;
   
   TH1D* H_Shower_EMean;
   TH1D* H_Shower_EDeviation;
   
   TH1D* H_Shower_NCells_XMean;
   TH1D* H_Shower_NCells_XDeviation;
   TH1D* H_Shower_NCells_YMean;
   TH1D* H_Shower_NCells_YDeviation;   
   TH1D* H_Shower_NCells_ZMean;
   TH1D* H_Shower_NCells_ZDeviation;    
   
   TH1D* H_Shower_E_XMean;
   TH1D* H_Shower_E_XDeviation;
   TH1D* H_Shower_E_YMean;
   TH1D* H_Shower_E_YDeviation;   
   TH1D* H_Shower_E_ZMean;
   TH1D* H_Shower_E_ZDeviation;
   
   
   TH1D* H_NcellsShower;
     
   
   TH1D* H_EMaxCell;   
   TH1D* H_XMaxCell;
   TH1D* H_YMaxCell;
   TH1D* H_ZMaxCell;
   
   TH3D* H_backgroundMap;
   
   
// 

   TH2D* H_XY_NCells_Sp[1000];
   TH2D* H_XZ_NCells_Sp[1000];
   TH2D* H_YZ_NCells_Sp[1000];
   
   TH2D* H_XY_E_Sp[1000];
   TH2D* H_XZ_E_Sp[1000];
   TH2D* H_YZ_E_Sp[1000];
   
   
   TH2D* H_XE_Sp[1000];
   TH2D* H_ZE_Sp[1000];
   TH1D* H_edep_Sp[1000];
   TH1D* H_X_E_Sp[1000];
   TH1D* H_Y_E_Sp[1000];
   TH1D* H_Z_E_Sp[1000];
   TH1D* H_X_NCells_Sp[1000];
   TH1D* H_Y_NCells_Sp[1000];
   TH1D* H_Z_NCells_Sp[1000];
   
   
//
   
   

   CaloHitsAnalysis(TTree *tree=0);
   virtual ~CaloHitsAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString fout="test.root",bool dobkg=false,TString bkgmap="bkgmap.root");
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CaloHitsAnalysis_cxx
CaloHitsAnalysis::CaloHitsAnalysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("xaa.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("xaa.root");
      }
      f->GetObject("Hits",tree);

   }
   Init(tree);
}

CaloHitsAnalysis::~CaloHitsAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CaloHitsAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CaloHitsAnalysis::LoadTree(Long64_t entry)
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

void CaloHitsAnalysis::Init(TTree *tree)
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
   
   
   
   H_NEvents=new TH1D("NEvents","NEvents",1000,0,1000);
   H_NEvents->GetXaxis()->SetTitle("Number of events processed");
   
   
   H_Shower_E         =new TH1D("Shower_E",         "Shower_E"         ,300,0,0.75); 
   H_Shower_E_more    =new TH1D("H_Shower_E_more",         "H_Shower_E_more"         ,3000,0,0.75); 
   H_Shower_E->GetXaxis()->SetTitle("Shower Energy deposition (GeV)");
   H_Shower_E->GetYaxis()->SetTitle("N positron");
   
   
   H_Shower_EMean	   =new TH1D("Shower_EMean",         "Shower_EMean",100,0,0.01);   
   H_Shower_EMean->GetXaxis()->SetTitle("Cells Energy Mean (GeV)");
   H_Shower_EMean->GetYaxis()->SetTitle("N positron");
   
   
   H_Shower_EDeviation=new TH1D("Shower_EDeviation",    "Shower_EDeviation",1000,0,0.025);
   H_Shower_EDeviation->GetXaxis()->SetTitle("Cells Energy RMS (GeV)");
   H_Shower_EDeviation->GetYaxis()->SetTitle("N positron");
   
	 
	 
   H_Shower_NCells_XMean     =new TH1D("Shower_NCells_XMean",     "Shower_NCells_XMean"     ,115,0,115);
   H_Shower_NCells_XMean->GetXaxis()->SetTitle("X Pad Mean");
   H_Shower_NCells_XMean->GetYaxis()->SetTitle("N positron");
   
   
   
   H_Shower_NCells_XDeviation=new TH1D("Shower_NCells_XDeviation","Shower_NCells_XDeviation",10,0,10);
   H_Shower_NCells_XDeviation->GetXaxis()->SetTitle("X Pad RMS");
   H_Shower_NCells_XMean->GetYaxis()->SetTitle("N positron");
   
   
   H_Shower_NCells_YMean     =new TH1D("Shower_NCells_YMean"     ,"Shower_NCells_YMean"     ,11,0,11);
   H_Shower_NCells_YMean->GetXaxis()->SetTitle("Y Pad Mean");
   H_Shower_NCells_YMean->GetYaxis()->SetTitle("N positron");
   
   
   H_Shower_NCells_YDeviation=new TH1D("Shower_NCells_YDeviation","Shower_NCells_YDeviation",10,0,10);
   H_Shower_NCells_YDeviation->GetXaxis()->SetTitle("Y Pad RMS");
   H_Shower_NCells_YDeviation->GetYaxis()->SetTitle("N positron");
   
   
   H_Shower_NCells_ZMean     =new TH1D("Shower_NCells_ZMean"     ,"Shower_NCells_ZMean"     ,21,0,21);
   H_Shower_NCells_ZMean->GetXaxis()->SetTitle("Z Pad Mean");
   H_Shower_NCells_ZMean->GetYaxis()->SetTitle("N positron");
   
   H_Shower_NCells_ZDeviation=new TH1D("Shower_NCells_ZDeviation","Shower_NCells_ZDeviation",10,0,10);  
   H_Shower_NCells_ZDeviation->GetXaxis()->SetTitle("Z Pad RMS");
   H_Shower_NCells_ZDeviation->GetYaxis()->SetTitle("N positron");
   
   H_NcellsShower     =new TH1D("NcellsShower",     "NcellsShower"     ,500,0,500);
   H_NcellsShower->GetXaxis()->SetTitle("N Cells in the shower");
   H_NcellsShower->GetYaxis()->SetTitle("N positron");   
   
   
   H_Shower_E_XMean     =new TH1D("Shower_E_XMean",     "Shower_E_XMean"     ,115,0,115);
   H_Shower_E_XMean->GetXaxis()->SetTitle("X Pad Mean");
   H_Shower_E_XMean->GetYaxis()->SetTitle("N positron");
   
   H_Shower_E_XDeviation=new TH1D("Shower_E_XDeviation","Shower_E_XDeviation",10,0,10);
   H_Shower_E_XDeviation->GetXaxis()->SetTitle("X Pad RMS");
   H_Shower_E_XDeviation->GetYaxis()->SetTitle("N positron");  
   
   H_Shower_E_YMean     =new TH1D("Shower_E_YMean"     ,"Shower_E_YMean"     ,11,0,11);
   H_Shower_E_YMean->GetXaxis()->SetTitle("Y Pad Mean");
   H_Shower_E_YMean->GetYaxis()->SetTitle("N positron");
   
   H_Shower_E_YDeviation=new TH1D("Shower_E_YDeviation","Shower_E_YDeviation",10,0,10);
   H_Shower_E_YDeviation->GetXaxis()->SetTitle("Y Pad RMS");
   H_Shower_E_YDeviation->GetYaxis()->SetTitle("N positron");   
   
   H_Shower_E_ZMean     =new TH1D("Shower_E_ZMean"     ,"Shower_E_ZMean"     ,21,0,21);
   H_Shower_E_ZMean->GetXaxis()->SetTitle("Z Pad Mean");
   H_Shower_E_ZMean->GetYaxis()->SetTitle("N positron");
   
   H_Shower_E_ZDeviation=new TH1D("Shower_E_ZDeviation","Shower_E_ZDeviation",10,0,10);     
   H_Shower_E_ZDeviation->GetXaxis()->SetTitle("Z Pad RMS");
   H_Shower_E_ZDeviation->GetYaxis()->SetTitle("N positron");
   
   
   H_EMaxCell         =new TH1D("EMaxCell",         "EMaxCell"     ,2000,0,0.05);   
   H_EMaxCell->GetXaxis()->SetTitle("E Max cell");
   H_EMaxCell->GetYaxis()->SetTitle("N positron");
   
   
   H_XMaxCell         =new TH1D("H_XMaxCell",     "H_XMaxCell"     ,115,0,115);
   H_XMaxCell->GetXaxis()->SetTitle("X Pad");
   H_XMaxCell->GetYaxis()->SetTitle("N positron");
   
   
   H_YMaxCell         =new TH1D("H_YMaxCell"     ,"H_YMaxCell"     ,11,0,11);
   H_YMaxCell->GetXaxis()->SetTitle("Y Pad");
   H_YMaxCell->GetYaxis()->SetTitle("N positron");
   
   
   H_ZMaxCell         =new TH1D("H_ZMaxCell"     ,"H_ZMaxCell"     ,21,0,21);
   H_ZMaxCell->GetXaxis()->SetTitle("Y Pad");
   H_ZMaxCell->GetYaxis()->SetTitle("N positron");
   
   
	   for (int i=0;i<1000;i++){
	H_XY_NCells_Sp  [i]=new TH2D(Form("H_XY_NCells_Sp_%i",i),Form("H_XY_NCells_Sp_%i",i),115,0,115,11,0,11);
    H_XY_NCells_Sp  [i]->GetXaxis()->SetTitle("X Pad");
    H_XY_NCells_Sp  [i]->GetYaxis()->SetTitle("Y Pad");
	
	
	H_XZ_NCells_Sp  [i]=new TH2D(Form("H_XZ_NCells_Sp_%i",i),Form("H_XZ_NCells_Sp_%i",i),115,0,115,21,0,21);
    H_XZ_NCells_Sp  [i]->GetXaxis()->SetTitle("X Pad");
    H_XZ_NCells_Sp  [i]->GetYaxis()->SetTitle("Z Layer ID");
	
	
	H_YZ_NCells_Sp  [i]=new TH2D(Form("H_YZ_NCells_Sp_%i",i),Form("H_YZ_NCells_Sp_%i",i),11,0,11,21,0,21);
    H_YZ_NCells_Sp  [i]->GetXaxis()->SetTitle("X Pad");
    H_YZ_NCells_Sp  [i]->GetYaxis()->SetTitle("Z Layer ID");
	
	H_XY_E_Sp  [i]=new TH2D(Form("H_XY_E_Sp_%i",i),Form("H_XY_E_Sp_%i",i),115,0,115,11,0,11);
    H_XY_E_Sp  [i]->GetXaxis()->SetTitle("X Pad");
    H_XY_E_Sp  [i]->GetYaxis()->SetTitle("Y Pad");
	
	H_XZ_E_Sp  [i]=new TH2D(Form("H_XZ_E_Sp_%i",i),Form("H_XZ_E_Sp_%i",i),115,0,115,21,0,21);
    H_XZ_E_Sp  [i]->GetXaxis()->SetTitle("X Pad");
    H_XZ_E_Sp  [i]->GetYaxis()->SetTitle("Z Layer ID");
	
	
	H_YZ_E_Sp  [i]=new TH2D(Form("H_YZ_E_Sp_%i",i),Form("H_YZ_E_Sp_%i",i),11,0,11,21,0,21);
    H_XZ_E_Sp  [i]->GetXaxis()->SetTitle("X Pad");
    H_YZ_E_Sp  [i]->GetYaxis()->SetTitle("Z Layer ID");
	
	
	H_XE_Sp  [i]=new TH2D(Form("H_XE_Sp_%i",i),Form("H_XE_Sp_%i",i),115,0,115,2000,0,0.05);
	H_ZE_Sp  [i]=new TH2D(Form("H_ZE_Sp_%i",i),Form("H_ZE_Sp_%i",i),21,0,21,2000,0,0.05);
	H_edep_Sp[i]=new TH1D(Form("H_edep_Sp_%i",i),Form("H_edep_Sp_%i",i) ,2000,0,0.05);
	H_X_NCells_Sp   [i]=new TH1D(Form("H_X_NCells_Sp_%i",i),Form("H_X_NCells_Sp_%i",i) ,115,0,115);
	H_Y_NCells_Sp   [i]=new TH1D(Form("H_Y_NCells_Sp_%i",i),Form("H_Y_NCells_Sp_%i",i) ,11,0,11);
	H_Z_NCells_Sp   [i]=new TH1D(Form("H_Z_NCells_Sp_%i",i),Form("H_Z_NCells_Sp_%i",i) ,21,0,21);
	H_X_E_Sp   [i]=new TH1D(Form("H_X_E_Sp_%i",i),Form("H_X_E_Sp_%i",i) ,115,0,115);
	H_Y_E_Sp   [i]=new TH1D(Form("H_Y_E_Sp_%i",i),Form("H_Y_E_Sp_%i",i) ,11,0,11);
	H_Z_E_Sp   [i]=new TH1D(Form("H_Z_E_Sp_%i",i),Form("H_Z_E_Sp_%i",i) ,21,0,21);
	
	   }
	   
	H_backgroundMap=new TH3D("backgroundMap","backgroundMap",115,0,115,11,0,11,21,0,21); 

   
   
   
   
   
}

Bool_t CaloHitsAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CaloHitsAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CaloHitsAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CaloHitsAnalysis_cxx
