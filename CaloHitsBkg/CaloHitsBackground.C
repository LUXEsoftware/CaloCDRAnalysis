#define CaloHitsBackground_cxx
#include "CaloHitsBackground.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>

void CaloHitsBackground::Loop(TString fout,double scale)
{
//   In a ROOT session, you can do:
//      root> .L CaloHitsBackground.C
//      root> CaloHitsBackground t
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
   
   
   
   
   

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
	  
	   if(jentry%1000000==0)cout<<jentry<<endl;
	  
	  if(detid!=2000) continue;
	  
   double prevE=H_backgroundMap->GetBinContent(cellx+1,celly+1,layerid+1);
	H_backgroundMap->SetBinContent(cellx+1,celly+1,layerid+1,prevE+edep);  
	
	// H_backgroundMap->SetBinError(cellx+1,celly+1,layerid+1,H_backgroundMap->GetBinError(cellx+1,celly+1,layerid+1)+1);
	H_backgroundMapI->SetBinContent(cellx+1,celly+1,layerid+1,H_backgroundMapI->GetBinContent(cellx+1,celly+1,layerid+1)+1);  
	H_backgroundMapF->Fill(cellx+1,celly+1,layerid+1,edep);  
	
	Int_t bins1[4]={cellx+1,celly+1,layerid+1,int(H_backgroundMapI->GetBinContent(cellx+1,celly+1,layerid+1))};
	hn->SetBinContent(bins1,edep);


    prevE=0;prevE=H_XY->GetBinContent(cellx+1,celly+1);
    H_XY->SetBinContent(cellx+1,celly+1,prevE+edep);  

    prevE=0;prevE=H_YZ->GetBinContent(celly+1,layerid+1);
    H_YZ->SetBinContent(celly+1,layerid+1,prevE+edep);  
	
    prevE=0;prevE=H_XZ->GetBinContent(cellx+1,layerid+1);
    H_XZ->SetBinContent(cellx+1,layerid+1,prevE+edep);  
	
	// cout<<layerid<<endl;
    prevE=0;prevE=H_XY_Sp[layerid]->GetBinContent(cellx+1,celly+1);
    H_XY_Sp[layerid]->SetBinContent(cellx+1,celly+1,prevE+edep);  
	
	
  
	// H_XE;
	// H_ZE;
	// H_ZE;  
	  
	  
	  
	  
	  
	  
      // if (Cut(ientry) < 0) continue;
   }

   Scale(H_XY,scale);
   Scale(H_YZ,scale);
   Scale(H_XZ,scale);
   
   
   for(int i=1;i<=H_backgroundMap->GetNbinsX();i++){
	   for(int j=1;j<=H_backgroundMap->GetNbinsY();j++){
		   for(int k=1;k<=H_backgroundMap->GetNbinsZ();k++){
			   H_Edep->Fill(H_backgroundMap->GetBinContent(i,j,k));
			   
			   double edev=0;
			   int count=0;
			   for(int l=1;l<=int(H_backgroundMapI->GetBinContent(i,j,k));l++){
				   Int_t bins2[4]={i,j,k,l};
				   
				   edev+=TMath::Power((hn->GetBinContent(bins2)-H_backgroundMap->GetBinContent(i,j,k)/H_backgroundMapI->GetBinContent(i,j,k)),2);
				   // cout<<" loop "<<i<<"  "<<j<<"  "<<k<<"  "<<int(H_backgroundMapI->GetBinContent(i,j,k)-1)<<" "<<H_backgroundMap->GetBinContent(i,j,k)<<" "<<hn->GetBinContent(bins2)<<"  "<<edev<<endl;
				   
				   
				   count+=1;
			   }
			   edev=sqrt(edev/(H_backgroundMapI->GetBinContent(i,j,k)-1));
			   if(H_backgroundMapI->GetBinContent(i,j,k)>1)H_backgroundMap->SetBinError(i,j,k,edev);
			   // cout<<" done "<<i<<"  "<<j<<"  "<<k<<"  "<<H_backgroundMapI->GetBinContent(i,j,k)<<"  "<<H_backgroundMap->GetBinContent(i,j,k)<<"  "<<H_backgroundMap->GetBinError(i,j,k)<<"  "<<H_backgroundMap->GetBinError(i,j,k)/H_backgroundMap->GetBinContent(i,j,k)<<endl;
		   	 }
		   }
	   }
	   Scale(H_backgroundMap,scale);
   
   
   TFile* file=TFile::Open(fout,"Recreate");
         
   H_backgroundMap->Write();
   H_backgroundMapF->Write();
   H_backgroundMapI->Write();
   
   hn->Write();
   H_XY->Write();
   H_YZ->Write();
   H_XZ->Write();
   H_Edep->Write();
   for(int i=0;i<21;i++){
	Scale(H_XY_Sp[i],scale);
    H_XY_Sp[i]->Write();
   }

   file->Close();
   
   
   
   
}
