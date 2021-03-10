
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

void Calorimeter_elaser_EnergyResolution_Macro()
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

		yr[i]=Sig_mean[i]/Bkg_mean[i];
		yrerr[i]=yr[i]*sqrt((Sig_mean_err[i]/Sig_mean[i])*(Sig_mean_err[i]/Sig_mean[i])+(Bkg_sigma_err[i]/Bkg_sigma[i])*(Bkg_sigma_err[i]/Bkg_sigma[i]));

		// cout<<yr[i]<<"  "<<ys[i]<<"  "<<yb[i]<<endl;
		// yrerr[i]=yr[i]*sqrt((yserr[i]/ys[i])*(yserr[i]/ys[i])+(yberr[i]/yb[i])*(yberr[i]/yb[i]));

		F1->Close();


	}
	
	
	
//
//
// auto gr = new TGraphErrors(n,num,Sig_mean,numerr,Sig_mean_err);
// gr->SetTitle("S: ETruth vs Mean gauss");
// gr->GetXaxis()->SetTitle("Positron E Gene (GeV)");
// gr->GetYaxis()->SetTitle("Mean E Reco (Gauss Fit) (GeV)");
//
// gr->SetMarkerColor(4);
// gr->SetMarkerStyle(21);
// gr->Draw("ALP");
//
// new TCanvas();
//
// auto gr2 = new TGraphErrors(n,num,Bkg_mean,numerr,Bkg_mean_err);
// gr2->SetTitle("S+B: ETruth vs Mean gauss");
// gr2->SetMarkerColor(4);
// gr2->GetXaxis()->SetTitle("Positron E Gene (GeV)");
//  gr2->GetYaxis()->SetTitle("Mean E Reco (Gauss Fit) (GeV)");
// gr2->SetMarkerStyle(21);
// gr2->Draw("ALP");
//
// new TCanvas();
//
// auto gr3 = new TGraphErrors(n,num,Sig_sigma,numerr,Sig_sigma_err);
// gr3->SetTitle("S: ETruth vs Sigma gauss");
// gr3->GetXaxis()->SetTitle("Positron E Gene (GeV)");
// gr3->GetYaxis()->SetTitle("Sigma E Reco (Gauss Fit) (GeV)");
// gr3->SetMarkerColor(4);
// gr3->SetMarkerStyle(21);
// gr3->Draw("ALP");
//
// new TCanvas();
//
// auto gr4 = new TGraphErrors(n,num,Bkg_sigma,numerr,Bkg_sigma_err);
// gr4->SetTitle("S+B: ETruth vs Sigma gauss");
// gr4->SetMarkerColor(4);
// gr4->GetXaxis()->SetTitle("Positron E Gene (GeV)");
//  gr4->GetYaxis()->SetTitle("Sigma E Reco (Gauss Fit) (GeV)");
//
// gr4->SetMarkerStyle(21);
// gr4->Draw("ALP");
//
// new TCanvas();



	/**
auto gr5 = new TGraphErrors(n,num,yr,numerr,yrerr);
gr5->SetTitle("S/S+B");

gr5->GetYaxis()->SetTitle("Signal E Mean reco/ S+B E Mean Reco");
gr5->SetMarkerColor(4);
gr5->GetXaxis()->SetTitle("Positron E Gene (GeV)");
gr5->SetMarkerStyle(21);
gr5->Draw("AP");


new TCanvas();
**/
	
	TLegend* leg=new TLegend(0.52,0.6,0.92,0.9);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->SetTextSize(0.05);
	




auto gr6 = new TGraphErrors(n,num,Sig_sigmaSmean,numerr,Sig_sigmaSmean_err);
gr6->SetTitle("#frac{#sigma_{E}}{E}");
gr6->GetYaxis()->SetTitle("#frac{#sigma_{E}}{E}");
gr6->GetYaxis()->SetRangeUser(0.05,0.2);
gr6->SetMarkerColor(kRed);
gr6->SetLineColor(kRed);
gr6->SetMarkerStyle(20);
gr6->SetMarkerSize(1.);


gr6->GetXaxis()->SetTitle("Positron Energy [GeV]");
// gr6->SetMarkerStyle(21);

TF1* Fun2=new TF1("Fun2","[0]/TMath::Sqrt(x)",0,17);
gr6->Fit(Fun2);
gr6->Draw("AP");
Fun2->SetParameter(0,0.193);
TLatex latex;
latex.SetTextSize(0.05);

TString reso=Form("#frac{%2.1f%}{#sqrt{E}}",Fun2->GetParameter(0)*100.);
// latex.DrawLatexNDC(.7,.4,reso);


// new TCanvas();

auto gr7 = new TGraphErrors(n,num,Bkg_sigmaSmean,numerr,Bkg_sigmaSmean_err);
gr7->SetTitle("S+B: Sigma E Reco/ E Mean Reco (Gauss Fit) (GeV)");
gr7->GetYaxis()->SetTitle(" Sigma E Reco/ E Mean Reco");
gr7->SetMarkerColor(kBlue);
gr7->SetLineColor(kBlue);
gr7->SetMarkerStyle(20);
gr6->SetMarkerSize(1.);


gr7->GetXaxis()->SetTitle("Positron Energy (GeV)");
// gr7->SetMarkerStyle(21);

// TF1* Fun3=new TF1("Fun3","[0]/TMath::Sqrt(x)",0,17);
// gr7->Fit(Fun3);
gr7->Draw("P&&same");
// reso=Form("#frac{%2.1f%}{#sqrt{E}}",Fun3->GetParameter(0)*100.);
// latex.DrawLatexNDC(.7,.4,reso);

for (int i=0;i<n;i++)cout<<num[i]<<" "<<endl;
	// endl;

leg->AddEntry(gr6,"e^{+} w/o bkg from beam","P");
leg->AddEntry(gr7,"e^{+} w/ bkg from beam","P");
leg->AddEntry(Fun2,reso,"l");


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
  l.DrawLatex(0.2,0.80,"Calorimeter - e-laser");
  gPad->RedrawAxis();
  
  gPad->Print("Calorimeter_elaser_EnergyResolution.png");
  gPad->Print("Calorimeter_elaser_EnergyResolution.C");

  return;
}

#ifndef __CINT__
int main() { 
  Calorimeter_elaser_EnergyResolution_Macro();

  
  return 0;
}
#endif
