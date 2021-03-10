#include <fstream>

void loop(int n);
void makeFileHits(){
for (int i=0;i<1;i++){
cout<<i<<endl;
loop(i);
}

}

void loop(int n){
TChain* Chain=new TChain("Hits");

TString stringn=Form("%i",n);
std::ifstream file("./list_root_hics_background_fast_9f6b6590_34_35.txt");//Input file list from Sasha
int count=0;
if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        // using printf() in all tests for consistency
	Chain->Add(line.c_str());
        printf("%s\n", line.c_str());
	count++;
    }
    file.close();
}
cout<<"files to process "<<count<<endl;



TFile* File=TFile::Open("backgroundFastSim_Hits.root","recreate");// Output file
TTree* Tree=(TTree*)Chain->CopyTree("detid==2000||detid==2001"); //Select calorimeter from electron and positron arm:
Tree->Write();
File->Close();
delete Chain;
}
