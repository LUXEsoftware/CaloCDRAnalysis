#define CaloHitsAnalysis_cxx
#include "CaloHitsAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>


void CaloHitsAnalysis::Loop(TString fout,bool dobkg,TString bkgmap)
{
//   In a ROOT session, you can do:
//      root> .L CaloHitsAnalysis.C
//      root> CaloHitsAnalysis t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   
   event=-1;
   eventCount=-1;
   bool newEvent=false;
   
  std::vector<double> vec_E;
  std::vector<int>    vec_X;
  std::vector<double> vec_Y;
  std::vector<double> vec_Z;
  
  double mean_E=0;
  double mean_X=0;
  double mean_Y=0;
  double mean_Z=0;
  
  
  double max_E=0;
  int max_X=0;
  int max_Y=0;
  int max_Z=0;
  
  double sumE=0;
   
   
//  TFile* FIn=TFile::Open("pos_bppp_background_fast_test_04012021_backgroundMap.root");
  TFile* FIn=TFile::Open(bkgmap);
  TH3D* H3=(TH3D*)FIn->Get("backgroundMap");
 
   

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
	  
	   if(jentry%1000000==0)std::cout<<jentry<<std::endl;
	  
	  if(detid!=2000) continue;// Check whether the hit belong to the calo
	  
	  if(event==-1){//Check if this is the first event
		  event=eventid;
		  eventCount+=1;
	  	  }
		  double edepUpdate=edep;
		  if(dobkg)edepUpdate+=H3->GetBinContent(H3->FindBin(cellx,celly,layerid));
	  
	  if(eventid!=event){//Check whether we are in a new event  
		  event=eventid;
		  eventCount+=1;
		  
	      H_NEvents->Fill(eventCount);
		  
		  
		  int npart=int(vec_E.size());
		  H_Shower_E->Fill(sumE);
		  H_Shower_E_more->Fill(sumE);
		  
		  H_EMaxCell->Fill(max_E);
		  H_XMaxCell->Fill(max_X);
		  H_YMaxCell->Fill(max_Y);
          H_ZMaxCell->Fill(max_Z);
		  H_NcellsShower->Fill(npart);
		  
		  
		  // mean_E=mean_E/double(npart);
		  // mean_X=mean_X/double(npart);
		  // mean_Y=mean_Y/double(npart);
		  mean_Z=mean_Z/double(npart);
		  
		  if(eventCount>0&&eventCount<1000){
		     H_Shower_EMean->Fill(H_edep_Sp[eventCount-1]->GetMean());
		     H_Shower_E_XMean->Fill(H_X_E_Sp   [eventCount-1]->GetMean());
		     H_Shower_E_YMean->Fill(H_Y_E_Sp   [eventCount-1]->GetMean());
		     H_Shower_E_ZMean->Fill(H_Z_E_Sp   [eventCount-1]->GetMean());
			 
		     H_Shower_NCells_XMean->Fill(H_X_NCells_Sp   [eventCount-1]->GetMean());
		     H_Shower_NCells_YMean->Fill(H_Y_NCells_Sp   [eventCount-1]->GetMean());
		     H_Shower_NCells_ZMean->Fill(H_Z_NCells_Sp   [eventCount-1]->GetMean());
			 
			 
	      }
		  
		  
		  double E_dev=0;
		  double X_dev=0;
		  double Y_dev=0;
		  double Z_dev=0;
		  
			  
			  
		  // for (int i=0;i<vec_E.size();i++){
		  // 			 E_dev+=(vec_E.at(i)-mean_E)*(vec_E.at(i)-mean_E);
		  // 			 X_dev+=(vec_X.at(i)-mean_X)*(vec_X.at(i)-mean_X);
		  // 			 Y_dev+=(vec_Y.at(i)-mean_Y)*(vec_Y.at(i)-mean_Y);
		  // 			 Z_dev+=(vec_Z.at(i)-mean_Z)*(vec_Z.at(i)-mean_Z);
		  // }
		  // E_dev=sqrt(E_dev/(npart-1));
		  // X_dev=sqrt(X_dev/(npart-1));
		  // Y_dev=sqrt(Y_dev/(npart-1));
		  // Z_dev=sqrt(Z_dev/(npart-1));
		  if(eventCount>0&&eventCount<1000){
		     H_Shower_EDeviation->Fill(H_edep_Sp[eventCount-1]->GetRMS());
		     H_Shower_NCells_XDeviation->Fill(H_X_NCells_Sp   [eventCount-1]->GetRMS());
		     H_Shower_NCells_YDeviation->Fill(H_Y_NCells_Sp   [eventCount-1]->GetRMS());
		     H_Shower_NCells_ZDeviation->Fill(H_Z_NCells_Sp   [eventCount-1]->GetRMS());
			 
		     H_Shower_E_XDeviation->Fill(H_X_E_Sp   [eventCount-1]->GetRMS());
		     H_Shower_E_YDeviation->Fill(H_Y_E_Sp   [eventCount-1]->GetRMS());
		     H_Shower_E_ZDeviation->Fill(H_Z_E_Sp   [eventCount-1]->GetRMS());
			 
	      }
		  vec_E.clear();
		  vec_X.clear();
		  vec_Y.clear();
		  vec_Z.clear();
  
		  mean_E=0;
		  mean_X=0;
		  mean_Y=0;
		  mean_Z=0;
  
  
		  max_E=0;
		  max_X=0;
		  max_Y=0;
		  max_Z=0;
  
		  sumE=0;
		  newEvent=false;
	  }
	  
	  
	  if(eventCount>0&&eventCount<1000){	// Fill the 1000 "event display"
		  
		    
		 H_edep_Sp[eventCount]->Fill(edepUpdate);
	 		// cout<<edep<<"  "<<H3->GetBinContent(H3->FindBin(cellx,celly,layerid))<<endl;
	
	     H_X_NCells_Sp[eventCount]->Fill(cellx);
	     H_Y_NCells_Sp[eventCount]->Fill(celly);
	     H_Z_NCells_Sp[eventCount]->Fill(layerid);
		 
		 H_XY_NCells_Sp[eventCount]->Fill(cellx,celly);
		 H_XZ_NCells_Sp[eventCount]->Fill(cellx,layerid);
		 H_YZ_NCells_Sp[eventCount]->Fill(celly,layerid);
		 
		 
	     double prevE=0;prevE=H_X_E_Sp[eventCount]->GetBinContent(cellx);
	     H_X_E_Sp[eventCount]->SetBinContent(cellx,prevE+edepUpdate);  
		 
	     prevE=0;prevE=H_Y_E_Sp[eventCount]->GetBinContent(celly);
	     H_Y_E_Sp[eventCount]->SetBinContent(celly,prevE+edepUpdate);  
		 
	     prevE=0;prevE=H_Z_E_Sp[eventCount]->GetBinContent(layerid);
	     H_Z_E_Sp[eventCount]->SetBinContent(layerid,prevE+edepUpdate);  
		 
	     prevE=0;prevE=H_XY_E_Sp[eventCount]->GetBinContent(cellx,celly);
	     H_XY_E_Sp[eventCount]->SetBinContent(cellx,celly,prevE+edepUpdate);  
		 
	     prevE=0;prevE=H_XZ_E_Sp[eventCount]->GetBinContent(cellx,layerid);
	     H_XZ_E_Sp[eventCount]->SetBinContent(cellx,layerid,prevE+edepUpdate);  
		 
	     prevE=0;prevE=H_YZ_E_Sp[eventCount]->GetBinContent(celly,layerid);
	     H_YZ_E_Sp[eventCount]->SetBinContent(celly,layerid,prevE+edepUpdate);  
		 
		 
		 H_XE_Sp[eventCount]->Fill(cellx,edepUpdate);
		 H_ZE_Sp[eventCount]->Fill(layerid,edepUpdate);
		 
		 
      }
	 
	 
	  //Fill the energy and cells positions

	  vec_E.push_back(edepUpdate);
	  vec_X.push_back(cellx);
	  vec_Y.push_back(celly);
	  vec_Z.push_back(layerid);

  	  sumE+=edepUpdate;

		
		
		
		
	  if(max_E<edepUpdate){
	  	  		max_E=edepUpdate;
		  		max_X=cellx;
		  		max_Y=celly;
		  		max_Z=layerid;
	  		
	  	  	}	
		
	  
	  
	  
      // if (Cut(ientry) < 0) continue;
   }// End loop on entries
      
   TFile* file=TFile::Open(fout,"Recreate");
   
   H_NEvents->Write();
   H_Shower_E->Write();
   H_Shower_E_more->Write();
   H_Shower_EMean->Write();
   H_Shower_EDeviation->Write();
   H_Shower_NCells_XMean     ->Write();
   H_Shower_NCells_XDeviation->Write();
   H_Shower_NCells_YMean     ->Write();
   H_Shower_NCells_YDeviation->Write();
   H_Shower_NCells_ZMean     ->Write();
   H_Shower_NCells_ZDeviation->Write();
   H_Shower_E_XMean     ->Write();
   H_Shower_E_XDeviation->Write();
   H_Shower_E_YMean     ->Write();
   H_Shower_E_YDeviation->Write();
   H_Shower_E_ZMean     ->Write();
   H_Shower_E_ZDeviation->Write();
   
   H_NcellsShower     ->Write();
   H_EMaxCell         ->Write();
   H_XMaxCell         ->Write();
   H_YMaxCell         ->Write();
   H_ZMaxCell         ->Write();
   // file->mkdir("events");
   // file->Cd("events");
   // for (int i=1;i<1000;i++){
   // 	   // file->mkdir(Form("/events_%i",i));
   // 	   // file->Cd(Form("/events_%i",i));
   //    H_edep_Sp[i]->Write();
   //    H_X_NCells_Sp   [i]->Write();
   //    H_Y_NCells_Sp   [i]->Write();
   //    H_Z_NCells_Sp   [i]->Write();
   //
   // 	  H_XY_NCells_Sp  [i]->Write();
   // 	  H_XZ_NCells_Sp  [i]->Write();
   // 	  H_YZ_NCells_Sp  [i]->Write();
   //
   //
   //
   //    H_X_E_Sp   [i]->Write();
   //    H_Y_E_Sp   [i]->Write();
   //    H_Z_E_Sp   [i]->Write();
   // 	  H_XY_E_Sp  [i]->Write();
   // 	  H_XZ_E_Sp  [i]->Write();
   // 	  H_YZ_E_Sp  [i]->Write();
   //
   //
   // 	  H_XE_Sp  [i]->Write();
   // 	  H_ZE_Sp  [i]->Write();
   // 	  // file->Cd("/");
   // }

   file->Close();
   FIn->Close();
   
   
   
   
   
}
