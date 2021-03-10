#include <fstream>

void loop(int n);
void makeFileTracks(){
for (int i=0;i<1;i++){
cout<<i<<endl;
loop(i);
}

}

void loop(int n){
TChain* Chain=new TChain("Tracks");

TString stringn=Form("%i",n);
std::ifstream file("./list_root_hics_background_fast_9f6b6590_34_35.txt");//Input file list from Sasha
if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        // using printf() in all tests for consistency
	Chain->Add(line.c_str());
        printf("%s", line.c_str());
    }
    file.close();
}




TFile* File=TFile::Open("backgroundFastSim_Tracks.root","recreate");//Output file
TTree* Tree=(TTree*)Chain->CopyTree("detid==2000||detid==2001"); //Select calorimeter on each side of the spectrometer.
Tree->Write();
File->Close();
delete Chain;
}
