
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

void Calorimeter_glaser_sOsb_Macro()
{
  SetLuxeStyle();

	const int n=11;
	int start=2;
	double num[n];
	double numerr[n];
	TString strib[n];
	TString stris[n];
	
	double Sig_mean[n];
	double Sig_mean_err[n];
	
	double Bkg_mean[n];
	double Bkg_mean_err[n];
	
	double Sig_sigmaSmean[n];
	double Sig_sigmaSmean_err[n];
	
	double Bkg_sigmaSmean[n];
	double Bkg_sigmaSmean_err[n];
	
	double Sig_sigma[n];
	double Sig_sigma_err[n];
	
	double Bkg_sigma[n];
	double Bkg_sigma_err[n];
	double yr[n];
	double yrerr[n];
	
	
	for (int i=0;i<n;i++){
		num[i]=double(i+start);
			numerr[i]=0.0;
		TString in=Form("luxe_hics_sig_%igev",i+start);
		
		if(i==0&&start==0){
			num[i]=1.5;
			in="luxe_hics_sig_1_5gev";

		}
		if(i==16){
			num[i]=16.5;
			in="luxe_hics_sig_16_5gev";
		}
		
		
		
		
		strib[i]="b_"+in+".root";
		stris[i]=in+".root";
			
				
		TFile* F1=TFile::Open("../output/"+stris[i],"READ");
		TH1F* H1=(TH1F*)F1->Get("H_Shower_E_more");
		TF1* Fun=new TF1("Fun","gaus");
		H1->Fit(Fun);

		Sig_mean[i]=Fun->GetParameter(1);
		Sig_mean_err[i]=Fun->GetParError(1);

		Sig_sigma[i]=Fun->GetParameter(2);
	    Sig_sigma_err[i]=Fun->GetParError(2);


		Sig_sigmaSmean[i]=Sig_sigma[i]/Sig_mean[i];
		Sig_sigmaSmean_err[i]=Sig_sigmaSmean[i]*sqrt((Sig_mean_err[i]/Sig_mean[i])*(Sig_mean_err[i]/Sig_mean[i])+(Sig_sigma_err[i]/Sig_sigma[i])*(Sig_sigma_err[i]/Sig_sigma[i]));

		F1->Close();
	}
	for (int i=0;i<n;i++){
		TFile* F1=TFile::Open("../output/"+strib[i],"READ");
		TH1F* H1=(TH1F*)F1->Get("H_Shower_E_more");
		TF1* Fun=new TF1("Fun","gaus");
		H1->Fit(Fun);

		Bkg_mean[i]=Fun->GetParameter(1);
		Bkg_mean_err[i]=Fun->GetParError(1);

		Bkg_sigma[i]=Fun->GetParameter(2);
	    Bkg_sigma_err[i]=Fun->GetParError(2);

		Bkg_sigmaSmean[i]=Bkg_sigma[i]/Bkg_mean[i];
		Bkg_sigmaSmean_err[i]=Bkg_sigmaSmean[i]*sqrt((Bkg_mean_err[i]/Bkg_mean[i])*(Bkg_mean_err[i]/Bkg_mean[i])+(Bkg_sigma_err[i]/Bkg_sigma[i])*(Bkg_sigma_err[i]/Bkg_sigma[i]));

		yr[i]=Bkg_mean[i]/Sig_mean[i];
		yrerr[i]=yr[i]*sqrt((Sig_mean_err[i]/Sig_mean[i])*(Sig_mean_err[i]/Sig_mean[i])+(Bkg_sigma_err[i]/Bkg_sigma[i])*(Bkg_sigma_err[i]/Bkg_sigma[i]));

		// cout<<yr[i]<<"  "<<ys[i]<<"  "<<yb[i]<<endl;
		// yrerr[i]=yr[i]*sqrt((yserr[i]/ys[i])*(yserr[i]/ys[i])+(yberr[i]/yb[i])*(yberr[i]/yb[i]));

		F1->Close();


	}
	


auto gr5 = new TGraphErrors(n,num,yr,numerr,yrerr);
gr5->SetTitle("S/S+B");

gr5->GetYaxis()->SetTitle("#bar{E_{S+B}}/#bar{E_{S}}");
gr5->SetMarkerColor(4);
gr5->GetXaxis()->SetTitle("Positron Energy [GeV]");
gr5->SetMarkerSize(1.);
gr5->SetMarkerStyle(20);
gr5->Draw("AP");
gr5->GetYaxis()->SetRangeUser(0.5,1.5);



	
	// TLegend* leg=new TLegend(0.55,0.5,0.9,0.9);
	// leg->SetBorderSize(0);
	// leg->SetFillColor(0);
	// leg->SetTextSize(0.03);
	//


// leg->AddEntry(gr5,"e^{+} without bkg from beam","P");
//   leg->Draw();

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
  
  gPad->Print("Calorimeter_glaser_sOsb.png");
  gPad->Print("Calorimeter_glaser_sOsb.C");

  return;
}

#ifndef __CINT__
int main() { 
  Calorimeter_glaser_sOsb_Macro();

  
  return 0;
}
#endif
