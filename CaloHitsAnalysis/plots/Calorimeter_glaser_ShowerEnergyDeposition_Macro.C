
#include "TH1F.h"
#include "TH1D.h"

#include "TPad.h"
#include "TRandom.h"
#include "TFile.h"


#include "LuxeLabels.h"
#include "LuxeStyle.h"

#ifdef __CLING__
// these are not headers - do not treat them as such - needed for ROOT6
#include "LuxeLabels.C"
#endif

void Calorimeter_glaser_ShowerEnergyDeposition_Macro()
{
  SetLuxeStyle();
  
  	const int n=7;
		// double num[n]={14,12,10,8,5,2};
		double num[n]={14,12,10,8,6,4,2};
		TString strnum[n];
		double numerr[n];
		TString strib[n];
		TString stris[n];
		int col[8]={600,616,900,633,797,412,419};
		
		
		for (int i=0;i<n;i++){
			strnum[i]=Form("%i",int(num[i]));
			numerr[i]=0.0;
			TString in=Form("luxe_hics_sig_%igev",int(num[i]));
			strib[i]="b_"+in+".root";
			stris[i]=in+".root";
			
			
		}
		
		
		// TString strnum[n]={"16.5","12","10","8","5","2"};
				
		// int col[8]={600,616,900,633,797,412,419};
TH1F* Hn[n*2];

//make a legend
TLegend* leg=new TLegend(0.52,0.5,0.92,0.9);
leg->SetBorderSize(0);
leg->SetFillColor(0);
leg->SetTextSize(0.04);
leg->SetHeader( "e^{+} Energy","C");
// leg->AddEntry((TObject*)0, " ", "");
leg->SetNColumns(2);
leg->AddEntry((TObject*)0, "w/ beam bkg", "");
leg->AddEntry((TObject*)0, "w/o beam bkg", "");

	for (int i=0;i<n;i++){
			TFile* F1=TFile::Open("../output/"+strib[i],"READ");
		TH1F* H1=(TH1F*)F1->Get("Shower_E");
		
		TFile* F2=TFile::Open("../output/"+stris[i],"READ");
		TH1F* H2=(TH1F*)F2->Get("Shower_E");
	    Int_t ci=col[i];      // for color index setting
	    // TColor *color; // for color definition with alpha
	    // ci = TColor::GetColor("#cccccc");
		H1->SetLineColor(ci);
		H2->SetLineColor(ci);
		H1->SetLineStyle(2);
		Hn[i*2]=H1;
		Hn[i*2+1]=H2;
		
	if(i==0){

	    H1->GetXaxis()->SetTitle("Shower Energy Deposition (GeV)");
	    H1->GetYaxis()->SetTitle("Arbirtary Units");
	    // H_photon_bkg->GetYaxis()->SetTitle("Particles / BX");
  
	    H1->GetXaxis()->SetTitleOffset(1.4);
	    H1->GetYaxis()->SetTitleOffset(1.4);
	    H1->GetYaxis()->SetRangeUser(0,400);
	    H1->GetXaxis()->SetRangeUser(0,0.25);
		
		H1->Draw();
		
	}
	else H1->Draw("same");
	H2->Draw("same");
	// leg->AddEntry(H1,strnum[i]+" GeV e^{+} with bkg from beam","l");
	// leg->AddEntry(H2,strnum[i]+" GeV e^{+} without bkg from beam","l");
	leg->AddEntry(H1,strnum[i]+" GeV","l");
	leg->AddEntry(H2,strnum[i]+" GeV","l");
	
}
	
	  

  //
  // H_positron_sig->GetXaxis()->SetTitle("x position [mm]");
  // H_positron_sig->GetYaxis()->SetTitle("#sum E/BX [GeV]");
  // // H_photon_bkg->GetYaxis()->SetTitle("Particles / BX");
  //
  // H_positron_sig->GetXaxis()->SetTitleOffset(1.4);
  // H_positron_sig->GetYaxis()->SetTitleOffset(1.4);
  // H_positron_sig->GetYaxis()->SetRangeUser(1e-4,1e3);
  // // H_photon_sig->SetLineColor(kRed);
  // H_photon_bkg->SetLineColor(kRed);
  // H_positron_bkg->SetLineColor(kBlue);
  // H_electron_bkg->SetLineColor(kBlack);
  //
  // // H_photon_bkg->SetLineStyle(2);
  //
  // H_positron_sig->SetLineColor(kGray);
  // H_positron_sig->SetFillColor(kGray);
  // // H_positron_bkg->SetLineStyle(2);
  
  // H_positron_bkg->SetLineStyle(2);
  
  
  // H_electron_sig->SetLineColor(kBlack);
  // H_electron_sig->SetLineColor(kBlack);
  // H_electron_bkg->SetLineStyle(2);

  
  
  // and plot it
  // H_positron_sig->Draw("Hist");
  // H_photon_bkg  ->Draw("Hist&&same");
  // H_positron_bkg->Draw("Hist&&same");
  // H_electron_bkg->Draw("Hist&&same");
  
  



  // leg->AddEntry(H_positron_sig,"e^{+}, Signal w_{0}=5#mum","f");
  // leg->AddEntry(H_photon_bkg,"#gamma, Background","l");
  // leg->AddEntry(H_electron_bkg,"e^{-}, Background","l");
  // leg->AddEntry(H_positron_bkg,"e^{+}, Background","l");
  leg->Draw();

  // gPad->SetLogy();

#ifdef __CINT__
  gROOT->LoadMacro("LuxeLabels.C");
#endif

  LUXELabel(0.2,0.85,"CDR");
  TLatex l; //l.SetTextAli
  l.SetNDC();
  l.SetTextFont(52);
  l.SetTextColor(kBlack);
  l.DrawLatex(0.2,0.80,"Calorimeter - #gamma-laser");
  gPad->RedrawAxis();
  
  gPad->Print("Calorimeter_glaser_ShowerEnergyDeposition.png");
  gPad->Print("Calorimeter_glaser_ShowerEnergyDeposition.C");

  return;
}

#ifndef __CINT__
int main() { 
  Calorimeter_glaser_ShowerEnergyDeposition_Macro();

  
  return 0;
}
#endif
