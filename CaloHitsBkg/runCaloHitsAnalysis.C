{

//Input file:
TString fileName="~/Dust-Luxe/merged/postCDR/08022021_850fd10d_fast_sim_caloSkimming_gammalaser/backgroundFastSim.root";

//Output file:
TString fout="Fast_background_gammaLaser_final.root";

TFile* file=TFile::Open(fileName);
TH1F* nentries=(TH1F*)file->Get("hist/h0");
double scale=1.;
if(nentries){
	scale=nentries->GetEntries()/1.5e9;
	cout<<scale<<endl;

}
else{
	cout<<"be carefull no hist for the normalisation found!!!!!"<<endl;
}
	
TChain* chain=new TChain("Hits");
chain->Add(fileName);
cout<<chain->GetEntries()<<endl;

gROOT->ProcessLine(".L CaloHitsBackground.C+");
gROOT->ProcessLine("CaloHitsBackground t(chain)");

t.Loop(fout,scale);

gSystem->Exit(0);
}
