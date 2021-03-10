#define CaloAnalysis_cxx
#include "CaloAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <ctime> 
#include <fstream>
// #include <stdlib.h>

void CaloAnalysis::Loop(TString outFile, double scale)
{
//   In a ROOT session, you can do:
//      root> .L CaloAnalysis.C
//      root> CaloAnalysis t
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
	
	
	bool debug=false;
	this->m_scaleWeight=scale;
	std::cout<<"Scale to use"<<scale<<"  "<<this->m_scaleWeight<<std::endl;
	
    std::time_t start = std::time(nullptr);
     std::asctime(std::localtime(&start));
     TFile* file=TFile::Open(outFile,"Recreate");
	 
	 
     // ofstream myfile1;
     // ofstream myfile2;
     //
     // myfile.open ("csv.txt",recreate);
     // myfile << "Writing this to a file.\n";
     // myfile.close();
     //
	
	
	
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
	  if(jentry%1000000==0){
	      std::time_t temp = std::time(nullptr);
	      std::asctime(std::localtime(&temp));
 		  cout<<double(jentry)/double(nentries)<<" "<<jentry<<" "<<nentries<<" elapsed time(s): "<<temp-start<<endl;
	  
	  }
	  vector<int> vec_trackid;
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
	  	  
	  for (int kentry=0;kentry<int(v_E->size());kentry++){
	        double E= v_E->at(kentry);
		    double x= v_x->at(kentry);
		    double y= v_y->at(kentry);
		    double z= v_z->at(kentry);
		    double vtxx=v_vtxx->at(kentry);
		    double vtxy=v_vtxy->at(kentry);
		    double vtxz=v_vtxz->at(kentry);
		    int   detid=v_detid->at(kentry);
		    int   pdg=v_pdg->at(kentry);
			int trackid=v_trackid->at(kentry);
	  	  bool detector=false;
		  // bool primaryevent=false;
		  // cout<<detid<<endl;
		  if(detid==-1&&weight>700000)break;//Do not consider events that contains a primary electrons from the beam for the signal only
		  
	  	  if((detid==2000||detid==2001))detector=true;
		  if(!detector)continue;
			
			
			bool duplicatetrack=false;
			if (vec_trackid.size()==0){
				vec_trackid.push_back(trackid);
			}
			else{
				for (int ivec=0;ivec<int(vec_trackid.size());ivec++){
					if(trackid==vec_trackid.at(ivec)){
						duplicatetrack=true;
						break;
					}
				}
				if(!duplicatetrack)vec_trackid.push_back(trackid);
			}
		 	if(duplicatetrack)continue;
	  
	  
	  bool cherenkov=false;
	  bool dump=false;
	  bool frontplate=false;
	  	  
	  if(vtxz>4200&&vtxz<4400&&vtxx<-50)cherenkov=true;
	  if(vtxz>6800)dump=true;
	  if(z>4254.4&&z<4254.6)frontplate=true;
	  if(!detector)continue;
	 // if(!frontplate)continue;// Only look at the front plane of the calorimeter
	  
	  if(detid==2000){	 
		  
		  //cout<<eventid<<", "<<trackid<<endl;
		  // cout<<eventid<<", "<<trackid<<", "<<x<<", "<<y<<", "<<z<<endl;
		  
		  FillHistoGroup(m_histoCaloPosAll, x, E, vtxx, vtxz, pdg, weight);
		  // if(debug)  std::cout<<"Debug::CaloPos::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  if(!dump){
			  FillHistoGroup(m_histoCaloPosNoDump, x, E, vtxx, vtxz, pdg, weight);
			if(debug)std::cout<<"Debug::CaloPos::NoDump::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  }
		  if(!cherenkov){
			  FillHistoGroup(m_histoCaloPosNoCherenkov, x, E, vtxx, vtxz, pdg, weight);
			  if(debug) std::cout<<"Debug::CaloPos::NoCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  }
		  if(!(dump||cherenkov)){
			  FillHistoGroup(m_histoCaloPosNoDumpNoCherenkov, x, E, vtxx, vtxz, pdg, weight);
			  if(debug)std::cout<<"Debug::CaloPos::NoDumpCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  } 
		  if((frontplate)){
			  // cout<<eventid<<", "<<trackid<<", "<<x<<", "<<y<<", "<<z<<endl;
			  FillHistoGroup(m_histoCaloPos_FrontPlate, x, E, vtxx, vtxz, pdg, weight);
			  if(debug)std::cout<<"Debug::CaloPos::FrontPlate::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  }
		  
		  if(E>1){
			  FillHistoGroup(m_histoCaloPos_1GeV_All, x, E, vtxx, vtxz, pdg, weight);
			  if(!dump){
				  FillHistoGroup(m_histoCaloPos_1GeV_NoDump, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloPos::1GeV::NoDump::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			  if(!cherenkov){
				  FillHistoGroup(m_histoCaloPos_1GeV_NoCherenkov, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloPos::1GeV::NoCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			  if(!(dump||cherenkov)){
				  FillHistoGroup(m_histoCaloPos_1GeV_NoDumpNoCherenkov, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloPos::1GeV::NoDumpCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			  if((frontplate)){
				  FillHistoGroup(m_histoCaloPos_1GeV_FrontPlate, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloPos::1GeV::FrontPlate::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			
		  }//end energy cut
		  
		  
		  
			  
		  
	
	  }//end calo positron arm
	  
	  if(detid==2001){
		  FillHistoGroup(m_histoCaloEleAll, x, E, vtxx, vtxz, pdg, weight);
		  if(!dump){
			  FillHistoGroup(m_histoCaloEleNoDump, x, E, vtxx, vtxz, pdg, weight);
			  if(debug)std::cout<<"Debug::CaloEle::NoDump::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  }
		  if(!cherenkov){
			  FillHistoGroup(m_histoCaloEleNoCherenkov, x, E, vtxx, vtxz, pdg, weight);
			  if(debug)std::cout<<"Debug::CaloEle::NoCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  }
		  if(!(dump||cherenkov)){
			  FillHistoGroup(m_histoCaloEleNoDumpNoCherenkov, x, E, vtxx, vtxz, pdg, weight);
			  if(debug)std::cout<<"Debug::CaloEle::NoDumpCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  }
		  if((frontplate)){
			  FillHistoGroup(m_histoCaloEle_FrontPlate, x, E, vtxx, vtxz, pdg, weight);
			  if(debug)std::cout<<"Debug::CaloEle::FrontPlate::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
		  }
		  
		  
		  if(E>1){
			  FillHistoGroup(m_histoCaloEle_1GeV_All, x, E, vtxx, vtxz, pdg, weight);
			  if(!dump){
				  FillHistoGroup(m_histoCaloEle_1GeV_NoDump, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloEle::1GeV::NoDump::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			  if(!cherenkov){
				  FillHistoGroup(m_histoCaloEle_1GeV_NoCherenkov, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloEle::1GeV::NoCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			  if(!(dump||cherenkov)){
				  FillHistoGroup(m_histoCaloEle_1GeV_NoDumpNoCherenkov, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloEle::1GeV::NoDumpCherenkov::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			  if((frontplate)){
				  FillHistoGroup(m_histoCaloEle_1GeV_FrontPlate, x, E, vtxx, vtxz, pdg, weight);
				  if(debug)std::cout<<"Debug::CaloEle::1GeV::FrontPlate::x:"<<x<<" E:"<<E<<" pdg:"<<pdg<<" weight:"<<weight<<" vtxx:"<<vtxx<<" vtxz:"<<vtxz<<" detid:"<<detid<<std::endl;
			  }
			
		  }//End loop over energy cut.
		  
		  
	  }//End loop over electron arm
	  
    }//End vector loop
   // if(jentry%1000000==0)cout<<ientry<<"  "<<m_histoCaloPosAll.energy->Integral()<<"  "<<m_histoCaloPosAll.energy->GetEntries()<<"  "
 //	   <<m_histoCaloPosAll.energy_photon->Integral()<<"  "<<m_histoCaloPosAll.energy_photon->GetEntries()<<"  "
 //		   <<m_histoCaloPosAll.energy_positron->Integral()<<"  "<<m_histoCaloPosAll.energy_positron->GetEntries()<<"  "
 //	 <<endl;
   }// End for loop
  // cout<<"Final  "<<m_histoCaloPosAll.energy->Integral()<<"  "<<m_histoCaloPosAll.energy->GetEntries()<<"  "
//	   <<m_histoCaloPosAll.energy_photon->Integral()<<"  "<<m_histoCaloPosAll.energy_photon->GetEntries()<<"  "
//		   <<m_histoCaloPosAll.energy_positron->Integral()<<"  "<<m_histoCaloPosAll.energy_positron->GetEntries()<<"  "
//	 <<endl;
	   
   
   WriteHistoGroup(file, m_histoCaloPosAll              );
   WriteHistoGroup(file, m_histoCaloEleAll              );
   WriteHistoGroup(file, m_histoCaloPos_FrontPlate              );
   WriteHistoGroup(file, m_histoCaloEle_FrontPlate              );  
   WriteHistoGroup(file,m_histoCaloEle_1GeV_All              );
   WriteHistoGroup(file,m_histoCaloPos_1GeV_All              );
   WriteHistoGroup(file, m_histoCaloPos_1GeV_FrontPlate              );
   WriteHistoGroup(file, m_histoCaloEle_1GeV_FrontPlate              );     
   
   
   
   WriteHistoGroup(file, m_histoCaloPosNoDump           );
   WriteHistoGroup(file, m_histoCaloPosNoCherenkov      );
   WriteHistoGroup(file, m_histoCaloPosNoDumpNoCherenkov);
   
   WriteHistoGroup(file, m_histoCaloEleNoDump           );
   WriteHistoGroup(file, m_histoCaloEleNoCherenkov      );
   WriteHistoGroup(file, m_histoCaloEleNoDumpNoCherenkov);
   
   WriteHistoGroup(file,m_histoCaloEle_1GeV_NoDump           );
   WriteHistoGroup(file,m_histoCaloEle_1GeV_NoCherenkov      );
   WriteHistoGroup(file,m_histoCaloEle_1GeV_NoDumpNoCherenkov);	
   
   WriteHistoGroup(file,m_histoCaloPos_1GeV_NoDump           );
   WriteHistoGroup(file,m_histoCaloPos_1GeV_NoCherenkov      );
   WriteHistoGroup(file,m_histoCaloPos_1GeV_NoDumpNoCherenkov);	
   
   
   
   file->Close();
   
   std::time_t temp = std::time(nullptr);
   std::asctime(std::localtime(&temp));
  cout<<"elapsed time (s): "<<temp-start<<endl;
   
   
}
