//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov 20 10:09:56 2020 by ROOT version 6.14/06
// from TTree Tracks/Tracks hitting volumes marked for track interception
// found on file: xaa.root
//////////////////////////////////////////////////////////

#ifndef CaloAnalysis_h
#define CaloAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2F.h>
#include <iostream>
#include <vector>


// Header file for the classes stored in the TTree if any.

class CaloAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           eventid;
   vector<int>     *v_trackid;
   vector<int>     *v_detid;
   vector<int>     *v_pdg;
   vector<int>     *physproc;
   vector<double>  *v_E;
   vector<double>  *v_x;
   vector<double>  *v_y;
   vector<double>  *v_z;
   vector<double>  *t;
   vector<double>  *v_vtxx;
   vector<double>  *v_vtxy;
   vector<double>  *v_vtxz;
   vector<double>  *px;
   vector<double>  *py;
   vector<double>  *pz;
   vector<double>  *theta;
   vector<double>  *phi;
   vector<double>  *xlocal;
   vector<double>  *ylocal;
   vector<double>  *zlocal;
   Double_t        weight;
   vector<int>     *ptrackid;
   vector<int>     *nsecondary;

   // List of branches
   TBranch        *b_eventid;   //!
   TBranch        *b_trackid;   //!
   TBranch        *b_detid;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_physproc;   //!
   TBranch        *b_E;   //!
   TBranch        *b_x;   //!
   TBranch        *b_y;   //!
   TBranch        *b_z;   //!
   TBranch        *b_t;   //!
   TBranch        *b_vtxx;   //!
   TBranch        *b_vtxy;   //!
   TBranch        *b_vtxz;   //!
   TBranch        *b_px;   //!
   TBranch        *b_py;   //!
   TBranch        *b_pz;   //!
   TBranch        *b_theta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_xlocal;   //!
   TBranch        *b_ylocal;   //!
   TBranch        *b_zlocal;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_ptrackid;   //!
   TBranch        *b_nsecondary;   //!
   
   struct histo_group {
	   TString title="";
	   TH1D* energy=0;
	   TH1D* energy_photon=0;
	   TH1D* energy_positron=0;
	   TH1D* energy_electron=0;
	   TH1D* energy_zoomed=0;
	   TH1D* energy_zoomed_photon=0;
	   TH1D* energy_zoomed_positron=0;
	   TH1D* energy_zoomed_electron=0;
	   
	   
	   TH1D* xp_energy=0;
	   TH1D* xp_energy_photon=0;	   
	   TH1D* xp_energy_positron=0; 
	   TH1D* xp_energy_electron=0;   
	   TH1D* xm_energy=0;
	   TH1D* xm_energy_photon=0;   
	   TH1D* xm_energy_positron=0; 
	   TH1D* xm_energy_electron=0;
	   
	   TH1D* xp=0;
	   TH1D* xp_photon=0;	   
	   TH1D* xp_positron=0; 
	   TH1D* xp_electron=0;   
	   TH1D* xm=0;
	   TH1D* xm_photon=0;   
	   TH1D* xm_positron=0; 
	   TH1D* xm_electron=0;
	   
	   
	   TH2F* map2d=0;
	   TH2F* map2d_photon  =0;
	   TH2F* map2d_positron=0;
	   TH2F* map2d_electron=0;
	   
	   double sum_energy=0;
	   double sum_energy_photon=0;
	   double sum_energy_positron=0;
	   double sum_energy_electron=0;
	   
	   
   };
   
   histo_group m_histoCaloEleAll;
   histo_group m_histoCaloEleNoDump;
   histo_group m_histoCaloEleNoCherenkov;
   histo_group m_histoCaloEleNoDumpNoCherenkov;
   
   histo_group m_histoCaloPosAll;
   histo_group m_histoCaloPosNoDump;
   histo_group m_histoCaloPosNoCherenkov;
   histo_group m_histoCaloPosNoDumpNoCherenkov;
   
   histo_group m_histoCaloEle_1GeV_All;
   histo_group m_histoCaloEle_1GeV_NoDump;
   histo_group m_histoCaloEle_1GeV_NoCherenkov;
   histo_group m_histoCaloEle_1GeV_NoDumpNoCherenkov;
   
   histo_group m_histoCaloPos_1GeV_All;
   histo_group m_histoCaloPos_1GeV_NoDump;
   histo_group m_histoCaloPos_1GeV_NoCherenkov;
   histo_group m_histoCaloPos_1GeV_NoDumpNoCherenkov;
   
   histo_group m_histoCaloEle_FrontPlate;
   histo_group m_histoCaloPos_FrontPlate;
   histo_group m_histoCaloEle_1GeV_FrontPlate;
   histo_group m_histoCaloPos_1GeV_FrontPlate;
   
   
   
   
   double m_scaleWeight=1.;
   CaloAnalysis(TTree *tree=0);
   virtual ~CaloAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString outFile, double scale);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     InitHistoGroup(CaloAnalysis::histo_group& hist,TString title);
   
   virtual void WriteHistoGroup(TFile* file, CaloAnalysis::histo_group& hist);
   virtual void ScaleHistoGroup(CaloAnalysis::histo_group& hist);
   virtual void FillHistoGroup(CaloAnalysis::histo_group& hist, double x, double E, double vtxx, double vtxz,int pdg, double weight);
   
};

#endif

#ifdef CaloAnalysis_cxx
CaloAnalysis::CaloAnalysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("xaa.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("xaa.root");
      }
      f->GetObject("Tracks",tree);

   }
   Init(tree);
}

CaloAnalysis::~CaloAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CaloAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CaloAnalysis::LoadTree(Long64_t entry)
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

void CaloAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
	
    // Set object pointer
    v_trackid = 0;
    v_detid = 0;
    v_pdg = 0;
    physproc = 0;
    v_E = 0;
    v_x = 0;
    v_y = 0;
    v_z = 0;
    t = 0;
    v_vtxx = 0;
    v_vtxy = 0;
    v_vtxz = 0;
    px = 0;
    py = 0;
    pz = 0;
    theta = 0;
    phi = 0;
    xlocal = 0;
    ylocal = 0;
    zlocal = 0;
    ptrackid = 0;
    nsecondary = 0;
    // Set branch addresses and branch pointers
    if (!tree) return;
    fChain = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);

    fChain->SetBranchAddress("eventid", &eventid, &b_eventid);
    fChain->SetBranchAddress("trackid", &v_trackid, &b_trackid);
    fChain->SetBranchAddress("detid", &v_detid, &b_detid);
    fChain->SetBranchAddress("pdg", &v_pdg, &b_pdg);
    fChain->SetBranchAddress("physproc", &physproc, &b_physproc);
    fChain->SetBranchAddress("E", &v_E, &b_E);
    fChain->SetBranchAddress("x", &v_x, &b_x);
    fChain->SetBranchAddress("y", &v_y, &b_y);
    fChain->SetBranchAddress("z", &v_z, &b_z);
    fChain->SetBranchAddress("t", &t, &b_t);
    fChain->SetBranchAddress("vtxx", &v_vtxx, &b_vtxx);
    fChain->SetBranchAddress("vtxy", &v_vtxy, &b_vtxy);
    fChain->SetBranchAddress("vtxz", &v_vtxz, &b_vtxz);
    fChain->SetBranchAddress("px", &px, &b_px);
    fChain->SetBranchAddress("py", &py, &b_py);
    fChain->SetBranchAddress("pz", &pz, &b_pz);
    fChain->SetBranchAddress("theta", &theta, &b_theta);
    fChain->SetBranchAddress("phi", &phi, &b_phi);
    fChain->SetBranchAddress("xlocal", &xlocal, &b_xlocal);
    fChain->SetBranchAddress("ylocal", &ylocal, &b_ylocal);
    fChain->SetBranchAddress("zlocal", &zlocal, &b_zlocal);
    fChain->SetBranchAddress("weight", &weight, &b_weight);
    fChain->SetBranchAddress("ptrackid", &ptrackid, &b_ptrackid);
    fChain->SetBranchAddress("nsecondary", &nsecondary, &b_nsecondary);
   
   // Disable all branches and reenables only a few of them:
   fChain->SetBranchStatus("*",0);
   fChain->SetBranchStatus("x",1);
   fChain->SetBranchStatus("y",1);
   fChain->SetBranchStatus("z",1);
   fChain->SetBranchStatus("E",1);
   
   fChain->SetBranchStatus("vtxx",1);
   fChain->SetBranchStatus("vtxy",1);
   fChain->SetBranchStatus("vtxz",1);
   
   fChain->SetBranchStatus("pdg",1);
   fChain->SetBranchStatus("detid",1);
   fChain->SetBranchStatus("trackid",1);
   fChain->SetBranchStatus("eventid",1);
   fChain->SetBranchStatus("weight",1);
   
   InitHistoGroup(m_histoCaloPosAll					,"CaloPosAll");	   
   InitHistoGroup(m_histoCaloPosNoDump				,"CaloPosNoDump");  
   InitHistoGroup(m_histoCaloPosNoCherenkov			,"CaloPosNoCherenkov");	   
   InitHistoGroup(m_histoCaloPosNoDumpNoCherenkov	,"CaloPosNoDumpNoCherenkov");	   
	   
   InitHistoGroup(m_histoCaloEleAll					,"CaloEleAll");	   
   InitHistoGroup(m_histoCaloEleNoDump				,"CaloEleNoDump");	   
   InitHistoGroup(m_histoCaloEleNoCherenkov			,"CaloEleNoCherenkov");	   
   InitHistoGroup(m_histoCaloEleNoDumpNoCherenkov	,"CaloEleNoDumpNoCherenkov");
   
   
   InitHistoGroup(m_histoCaloEle_1GeV_All              ,"CaloEle_1GeV_All");	
   InitHistoGroup(m_histoCaloEle_1GeV_NoDump           ,"CaloEle_1GeV_NoDump");	
   InitHistoGroup(m_histoCaloEle_1GeV_NoCherenkov      ,"CaloEle_1GeV_NoCherenkov");	
   InitHistoGroup(m_histoCaloEle_1GeV_NoDumpNoCherenkov,"CaloEle_1GeV_NoDumpNoCherenkov");	
   
   InitHistoGroup(m_histoCaloPos_1GeV_All              ,"CaloPos_1GeV_All");	
   InitHistoGroup(m_histoCaloPos_1GeV_NoDump           ,"CaloPos_1GeV_NoDump");	
   InitHistoGroup(m_histoCaloPos_1GeV_NoCherenkov      ,"CaloPos_1GeV_NoCherenkov");	
   InitHistoGroup(m_histoCaloPos_1GeV_NoDumpNoCherenkov,"CaloPos_1GeV_NoDumpNoCherenkov");	
   
   
   InitHistoGroup(m_histoCaloEle_FrontPlate      ,"CaloEle_FrontPlate");	
   InitHistoGroup(m_histoCaloPos_FrontPlate		 ,"CaloPos_FrontPlate");		
   InitHistoGroup(m_histoCaloEle_1GeV_FrontPlate      ,"CaloEle_1GeV_FrontPlate");	
   InitHistoGroup(m_histoCaloPos_1GeV_FrontPlate	  ,"CaloPos_1GeV_FrontPlate");	
  
 
}

Bool_t CaloAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CaloAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CaloAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void    CaloAnalysis::InitHistoGroup(CaloAnalysis::histo_group& hist,TString title){
   hist.title=title;
   hist.energy          =new TH1D(title+"_energy"         ,title+"_energy"         ,100,0,17.5);
   hist.energy_photon   =new TH1D(title+"_energy_photon"  ,title+"_energy_photon"  ,100,0,17.5);
   hist.energy_positron =new TH1D(title+"_energy_positron",title+"_energy_positron",100,0,17.5);
   hist.energy_electron =new TH1D(title+"_energy_electron",title+"_energy_electron",100,0,17.5);
   
   hist.energy_zoomed          =new TH1D(title+"_energy_zoomed"         ,title+"_energy_zoomed"         ,100,0,0.2);
   hist.energy_zoomed_photon   =new TH1D(title+"_energy_zoomed_photon"  ,title+"_energy_zoomed_photon"  ,100,0,0.2);
   hist.energy_zoomed_positron =new TH1D(title+"_energy_zoomed_positron",title+"_energy_zoomed_positron",100,0,0.2);
   hist.energy_zoomed_electron =new TH1D(title+"_energy_zoomed_electron",title+"_energy_zoomed_electron",100,0,0.2);
   
   hist.xp               =new TH1D(title+"_xp"              ,title+"_xp"              ,100,0,600);
   hist.xp_photon	    =new TH1D(title+"_xp_photon"       ,title+"_xp_photon"       ,100,0,600);
   hist.xp_positron      =new TH1D(title+"_xp_positron"     ,title+"_xp_positron"     ,100,0,600);
   hist.xp_electron      =new TH1D(title+"_xp_electron"     ,title+"_xp_electron"     ,100,0,600);
   
   hist.xm               =new TH1D(title+"_xm"              ,title+"_xm"              ,100,-600,0);
   hist.xm_photon	    =new TH1D(title+"_xm_photon"       ,title+"_xm_photon"       ,100,-600,0);
   hist.xm_positron      =new TH1D(title+"_xm_positron"     ,title+"_xm_positron"     ,100,-600,0);
   hist.xm_electron      =new TH1D(title+"_xm_electron"     ,title+"_xm_electron"     ,100,-600,0);	
 
 
   hist.xp_energy               =new TH1D(title+"_xp_energy"              ,title+"_xp_energy"              ,100,0,600);
   hist.xp_energy_photon	    =new TH1D(title+"_xp_energy_photon"       ,title+"_xp_energy_photon"       ,100,0,600);
   hist.xp_energy_positron      =new TH1D(title+"_xp_energy_positron"     ,title+"_xp_energy_positron"     ,100,0,600);
   hist.xp_energy_electron      =new TH1D(title+"_xp_energy_electron"     ,title+"_xp_energy_electron"     ,100,0,600);
   
   hist.xm_energy               =new TH1D(title+"_xm_energy"              ,title+"_xm_energy"              ,100,-600,0);
   hist.xm_energy_photon	    =new TH1D(title+"_xm_energy_photon"       ,title+"_xm_energy_photon"       ,100,-600,0);
   hist.xm_energy_positron      =new TH1D(title+"_xm_energy_positron"     ,title+"_xm_energy_positron"     ,100,-600,0);
   hist.xm_energy_electron      =new TH1D(title+"_xm_energy_electron"     ,title+"_xm_energy_electron"     ,100,-600,0);	
 
  
   hist.map2d         =new TH2F(title+"_vtx_map2d"     ,title+"_vtx_map2d"     ,400,-2500.,16000.,400,-5500,2500.);	
   hist.map2d_photon  =new TH2F(title+"_vtx_map2d_photon"     ,title+"_vtx_map2d_photon"     ,400,-2500.,16000.,400,-5500,2500.);	
   hist.map2d_positron=new TH2F(title+"_vtx_map2d_positron"     ,title+"_vtx_map2d_positron"     ,400,-2500.,16000.,400,-5500,2500.);	
   hist.map2d_electron=new TH2F(title+"_vtx_map2d_electron"     ,title+"_vtx_map2d_electron"     ,400,-2500.,16000.,400,-5500,2500.);	
   
   
   hist.energy->Sumw2();
   hist.energy_photon->Sumw2();
   hist.energy_positron->Sumw2();
   hist.energy_electron->Sumw2();
   
   
   hist.energy_zoomed->Sumw2();
   hist.energy_zoomed_photon->Sumw2();
   hist.energy_zoomed_positron->Sumw2();
   hist.energy_zoomed_electron->Sumw2();
   
   
   hist.xp->Sumw2();               
   hist.xp_photon->Sumw2();	    
   hist.xp_positron->Sumw2();      
   hist.xp_electron->Sumw2();      
   
   hist.xm->Sumw2();               
   hist.xm_photon->Sumw2();	    
   hist.xm_positron->Sumw2();        
   hist.xm_electron->Sumw2();   
   
   hist.xp_energy   ->Sumw2();           
   hist.xp_energy_photon->Sumw2();    
   hist.xp_energy_positron ->Sumw2();    
   hist.xp_energy_electron ->Sumw2();  
     
   hist.xm_energy      ->Sumw2();        
   hist.xm_energy_photon->Sumw2();    
   hist.xm_energy_positron ->Sumw2();    
   hist.xm_energy_electron  ->Sumw2();    
	   
	   
   hist.map2d->Sumw2(); 
   hist.map2d_photon  ->Sumw2(); 
   hist.map2d_positron->Sumw2(); 
   hist.map2d_electron->Sumw2(); 
}

void    CaloAnalysis::FillHistoGroup( CaloAnalysis::histo_group& hist, double x, double E, double vtxx, double vtxz, int pdg, double weight){
   // hist.energy->Fill(E,weight);
   // if(x>=0)hist.xp->Fill(x,weight);
   // if(x<0)hist.xm->Fill(x,weight);
   //
   // hist.sum_energy+=E*weight;
   //
   // if(pdg==22){
   // 	   hist.sum_energy_photon+=E*weight;
   // 	   hist.energy_photon->Fill(E,weight);
   // 	   if(x>0)hist.xp_photon->Fill(x,weight);
   // 	   if(x<0)hist.xm_photon->Fill(x,weight);
   // }
   //
   // if(pdg==11){
   // 	   hist.sum_energy_electron+=E*weight;
   // 	   hist.energy_electron->Fill(E,weight);
   // 	   if(x>=0)hist.xp_electron->Fill(x,weight);
   // 	   if(x<0)hist.xm_electron->Fill(x,weight);
   // }
   //
   // if(pdg==-11){
   // 	   hist.sum_energy_positron+=E*weight;
   // 	   hist.energy_positron->Fill(E,weight);
   // 	   if(x>=0)hist.xp_positron->Fill(x,weight);
   // 	   if(x<0)hist.xm_positron->Fill(x,weight);
   // }
   //
   // hist.map2d->Fill(vtxz,vtxx,weight);

    hist.energy->Fill(E,weight);
    hist.energy_zoomed->Fill(E,weight);
	
    if(x>=0)hist.xp->Fill(x,weight); 
    if(x<0)hist.xm->Fill(x,weight);	   
   
    hist.sum_energy+=E*weight;
     
    if(pdg==22){
 	   hist.sum_energy_photon+=E*weight;
 	   hist.energy_photon->Fill(E,weight);
 	   hist.energy_zoomed_photon->Fill(E,weight);
	   
    	   if(x>0)hist.xp_photon->Fill(x,weight);
 	   if(x<0)hist.xm_photon->Fill(x,weight);
       if(x>=0){
   		int binNr=hist.xp_energy_photon->FindBin(x);
   		          hist.xp_energy_photon->SetBinContent(binNr,hist.xp_energy_photon->GetBinContent(binNr)+E*weight);
   		          hist.xp_energy_photon->SetBinError(binNr  ,hist.xp_energy_photon->GetBinError(binNr)+E*weight*E*weight);	
   	   }
       if(x<0){
   		int binNr=hist.xm_energy_photon->FindBin(x);
   		          hist.xm_energy_photon->SetBinContent(binNr,hist.xm_energy_photon->GetBinContent(binNr)+E*weight);
   		          hist.xm_energy_photon->SetBinError(binNr  ,hist.xm_energy_photon->GetBinError(binNr)+E*weight*E*weight);	
   	   }
	   
	   
	   
    }
   
    if(pdg==11){
 	   hist.sum_energy_electron+=E*weight;
 	   hist.energy_electron->Fill(E,weight);
 	   hist.energy_zoomed_electron->Fill(E,weight);
	   
    	   if(x>=0)hist.xp_electron->Fill(x,weight);
 	   if(x<0)hist.xm_electron->Fill(x,weight);
       if(x>=0){
   		int binNr=hist.xp_energy_electron->FindBin(x);
   		          hist.xp_energy_electron->SetBinContent(binNr,hist.xp_energy_electron->GetBinContent(binNr)+E*weight);
   		          hist.xp_energy_electron->SetBinError(binNr  ,hist.xp_energy_electron->GetBinError(binNr)+E*weight*E*weight);	
   	   }
       if(x<0){
   		int binNr=hist.xm_energy_electron->FindBin(x);
   		          hist.xm_energy_electron->SetBinContent(binNr,hist.xm_energy_electron->GetBinContent(binNr)+E*weight);
   		          hist.xm_energy_electron->SetBinError(binNr  ,hist.xm_energy_electron->GetBinError(binNr)+E*weight*E*weight);	
   	   }
	   
	   
	   
    }
   
    if(pdg==-11){
 	   hist.sum_energy_positron+=E*weight;
 	   hist.energy_positron->Fill(E,weight);
 	   hist.energy_zoomed_positron->Fill(E,weight);
	   
    	   if(x>=0)hist.xp_positron->Fill(x,weight);
 	   if(x<0)hist.xm_positron->Fill(x,weight);
       if(x>=0){
   		int binNr=hist.xp_energy_positron->FindBin(x);
   		          hist.xp_energy_positron->SetBinContent(binNr,hist.xp_energy_positron->GetBinContent(binNr)+E*weight);
   		          hist.xp_energy_positron->SetBinError(binNr  ,hist.xp_energy_positron->GetBinError(binNr)+E*weight*E*weight);	
   	   }
       if(x<0){
   		int binNr=hist.xm_energy_positron->FindBin(x);
   		          hist.xm_energy_positron->SetBinContent(binNr,hist.xm_energy_positron->GetBinContent(binNr)+E*weight);
   		          hist.xm_energy_positron->SetBinError(binNr  ,hist.xm_energy_positron->GetBinError(binNr)+E*weight*E*weight);	
   	   }
	   
	   
    }  
   
    hist.map2d->Fill(vtxz,vtxx,weight);
	if(pdg==22)hist.map2d_photon->Fill(vtxz,vtxx,weight);  
	if(pdg==-11)hist.map2d_positron->Fill(vtxz,vtxx,weight);
	if(pdg==11)hist.map2d_electron->Fill(vtxz,vtxx,weight);
	
    if(x>=0){
		int binNr=hist.xp_energy->FindBin(x);
		          hist.xp_energy->SetBinContent(binNr,hist.xp_energy->GetBinContent(binNr)+E*weight);
		          hist.xp_energy->SetBinError(binNr,hist.xp_energy->GetBinError(binNr)+E*weight*E*weight);	
	}
    if(x<0){
		int binNr=hist.xm_energy->FindBin(x);
		          hist.xm_energy->SetBinContent(binNr,hist.xm_energy->GetBinContent(binNr)+E*weight);
		          hist.xm_energy->SetBinError(binNr,hist.xm_energy->GetBinError(binNr)+E*weight*E*weight);	
	}

	
	
	// cout<<hist.energy->GetEntries()<<"  "<<hist.energy->Integral()<<"  "<<hist.energy_photon->GetEntries()<<"  "<<hist.energy_photon->Integral()<<"  "<<hist.energy_electron->GetEntries()<<"  "<<hist.energy_electron->Integral()<<endl;
   
}


void CaloAnalysis::ScaleHistoGroup(CaloAnalysis::histo_group& hist){
	
	double scale=this->m_scaleWeight;
	hist.energy->Scale(1./scale);
	hist.energy_photon->  Scale(1./scale);
	hist.energy_positron->Scale(1./scale);
	hist.energy_electron->Scale(1./scale);
	
	hist.energy_zoomed->         Scale(1./scale);
	hist.energy_zoomed_photon->  Scale(1./scale);
	hist.energy_zoomed_positron->Scale(1./scale);
	hist.energy_zoomed_electron->Scale(1./scale);
	
	hist.xm->         Scale(1./scale);         
	hist.xp_photon->  Scale(1./scale);	  
	hist.xp_positron->Scale(1./scale);   
	hist.xp_electron->Scale(1./scale);   
	
	hist.xm->         Scale(1./scale);          
	hist.xm_photon->  Scale(1./scale);;	  
	hist.xm_positron->Scale(1./scale);  
	hist.xm_electron->Scale(1./scale); 
	
	for(int inbin=1;inbin<= hist.xp_energy->GetNbinsX();inbin++){
		hist.xp_energy           ->SetBinError(inbin,sqrt(hist.xp_energy           ->GetBinError(inbin)));
		hist.xp_energy_photon    ->SetBinError(inbin,sqrt(hist.xp_energy_photon    ->GetBinError(inbin)));
		hist.xp_energy_positron  ->SetBinError(inbin,sqrt(hist.xp_energy_positron  ->GetBinError(inbin)));
		hist.xp_energy_electron  ->SetBinError(inbin,sqrt(hist.xp_energy_electron  ->GetBinError(inbin)));
		hist.xm_energy           ->SetBinError(inbin,sqrt(hist.xm_energy           ->GetBinError(inbin)));
		hist.xm_energy_photon    ->SetBinError(inbin,sqrt(hist.xm_energy_photon    ->GetBinError(inbin)));
		hist.xm_energy_positron  ->SetBinError(inbin,sqrt(hist.xm_energy_positron  ->GetBinError(inbin)));
		hist.xm_energy_electron  ->SetBinError(inbin,sqrt(hist.xm_energy_electron  ->GetBinError(inbin)));
		
	}
		
	
    hist.xp_energy           ->         Scale(1./scale); 
    hist.xp_energy_photon    ->         Scale(1./scale); 
    hist.xp_energy_positron  ->         Scale(1./scale); 
    hist.xp_energy_electron  ->         Scale(1./scale); 
   
    hist.xm_energy           ->         Scale(1./scale); 
    hist.xm_energy_photon    ->         Scale(1./scale); 
    hist.xm_energy_positron  ->         Scale(1./scale); 
    hist.xm_energy_electron  ->         Scale(1./scale); 
	
	
	hist.map2d->Scale(1./scale); 
    hist.map2d_photon  ->Scale(1./scale); 
    hist.map2d_positron->Scale(1./scale); 
    hist.map2d_electron->Scale(1./scale); 
	
	
	
    hist.sum_energy=hist.sum_energy/scale;
    hist.sum_energy_electron=hist.sum_energy_electron/scale;
	
 	hist.sum_energy_photon=hist.sum_energy_photon/scale;
 	hist.sum_energy_positron=hist.sum_energy_positron/scale;
	
	

}


void CaloAnalysis::WriteHistoGroup(TFile* file, CaloAnalysis::histo_group& hist){
	
	ScaleHistoGroup(hist);
	file->Cd("/");
	file->mkdir(hist.title);
	file->Cd(hist.title);
	cout<<" Number of particles in Calo "<<hist.title<<" Total:"<<hist.energy->Integral()<<" Number of photons: "<<hist.energy_photon->Integral()<<" Number of electrons: "<<hist.energy_electron->Integral()<<" Number of positrons: "<<
	hist.energy_positron->Integral()<<endl;
	// cout<<" adress of particles in Calo "<<hist.title<<" Total:"<<hist.energy<<" Number of photons: "<<hist.energy_photon<<" Number of electrons: "<<hist.energy_electron<<" Number of positrons: "<<
	// hist.energy_positron<<endl;
	// cout<<" Number of particles in Calo "<<hist.title<<" Total:"<<hist.energy->GetEntries()<<" Number of photons: "<<hist.energy_photon->GetEntries()<<" Number of electrons: "<<hist.energy_electron->GetEntries()<<" Number of positrons: "<<
	// hist.energy_positron->GetEntries()<<endl;
	// cout<<" Total energy in Calo from hist"<<hist.title<<" Total:"<<hist.energy->Integral(0,100,"width")<<" Number of photons: "<<hist.energy_photon->Integral(0,100,"width")<<" Number of electrons: "<<hist.energy_electron->Integral(0,100,"width")<<" Number of positrons: "<<
	// hist.energy_positron->Integral(0,100,"width")<<endl;
	cout<<" Total energy in Calo from sum"<<hist.title<<" Total:"<<hist.sum_energy<<" Number of photons: "<<hist.sum_energy_photon<<" Number of electrons: "<<hist.sum_energy_electron<<" Number of positrons: "<<
	hist.sum_energy_positron<<endl;

		
		hist.energy->Write();
		hist.energy_photon->Write();  
		hist.energy_positron->Write();
		hist.energy_electron->Write();
		
		hist.energy_zoomed->Write();
		hist.energy_zoomed_photon->Write();  
		hist.energy_zoomed_positron->Write();
		hist.energy_zoomed_electron->Write();
		
		hist.xp->Write();             
		hist.xp_photon->Write();	  
		hist.xp_positron->Write();    
		hist.xp_electron->Write();    
		hist.xm->Write();             
		hist.xm_photon->Write();	  
		hist.xm_positron->Write();    
		hist.xm_electron->Write();  
		
		
		hist.xp_energy->Write();             
		hist.xp_energy_photon->Write();	  
		hist.xp_energy_positron->Write();    
		hist.xp_energy_electron->Write();
		    
		hist.xm_energy->Write();             
		hist.xm_energy_photon->Write();	  
		hist.xm_energy_positron->Write();    
		hist.xm_energy_electron->Write(); 
		
		hist.map2d->Write(); 
		hist.map2d_photon  ->Write(); 
		hist.map2d_positron->Write(); 
		hist.map2d_electron->Write(); 
}




#endif // #ifdef CaloAnalysis_cxx
