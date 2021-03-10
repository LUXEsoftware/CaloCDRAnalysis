#include <TChain.h>
#include <CaloHitsAnalysis.C+>

void runCaloHitsAnalysis(int stri, int dobkg,TString type, TString bkgmap){
	// TString type="e_laser";
	// TString bkgmap="CaloHitsBkg/Fast_background_gammaLaser_3.root";
	
	cout<<"process::"<<type<<" with bkgmap:"<<bkgmap<<" number: "<<stri<<" dobkg: "<<dobkg<<endl;
	//
	TString in=Form("luxe_hics_sig_%igev",stri);
	
	if(stri==1){
		in="luxe_hics_sig_1_5gev";
	}
	if(stri==17){
		in="luxe_hics_sig_16_5gev";
	}
	
	// TString in="luxe_hics_sig_165gev";
	// TString in="luxe_hics_sig_15gev";
	// TString in="luxe_hics_sig_12gev";
	// TString in="luxe_hics_sig_10gev";
	// TString in="luxe_hics_sig_8gev";
	// TString in="luxe_hics_sig_5gev";
	// TString in="luxe_hics_sig_2gev";
	// TString in="luxe_hics_sig_1_5gev";
	
	
	cout<<in<<endl;
TChain* chain=new TChain("Hits");
chain->Add(type+"/input/"+in+".root");
// gROOT->ProcessLine(".L CaloHitsAnalysis.C+");
CaloHitsAnalysis* t=new CaloHitsAnalysis(chain);
if(dobkg)t->Loop(type+"/output/b_"+in+".root",1,bkgmap);
else t->Loop(type+"/output/"+in+".root",0,bkgmap);
delete t;

// gROOT->ProcessLine("CaloHitsAnalysis* t=new CaloHitsAnalysis(chain)");
// if(dobkg) gROOT->ProcessLine("t->Loop(\"g_laser/output/b_"+in+".root\",1);");
// else gROOT->ProcessLine("t->Loop(\"g_laser/output/"+in+".root\",0);");
// gROOT->ProcessLine("delete t;");

gSystem->Exit(0);
}
