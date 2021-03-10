{
//Input file
TString fileName="/afs/desy.de/user/l/lhelary/Dust-Luxe/merged/postCDR/08022021_850fd10d_fast_sim_caloSkimming_gammalaser/backgroundFastSim.root";

//Output file
TString fout="GammaLaserBkg_final.root";
TFile* file=TFile::Open(fileName);
TH1F* nentries=(TH1F*)file->Get("hist/h0");

TChain* chain=new TChain("Tracks");
chain->Add(fileName);
double scale=1.;
if(nentries){
	scale=nentries->GetEntries()/1.5e9;
	cout<<scale<<endl;

}
else{
	cout<<"be carefull no hist for the normalisation found!!!!!"<<endl;
}


gROOT->ProcessLine(".L CaloAnalysis.C+");
gROOT->ProcessLine("CaloAnalysis t(chain)");
t.Loop(fout,scale); //Need to set normalization by hand for the signal!

gSystem->Exit(0);
}
