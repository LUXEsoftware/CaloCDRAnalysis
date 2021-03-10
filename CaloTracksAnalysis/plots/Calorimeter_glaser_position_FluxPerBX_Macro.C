
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

void Calorimeter_glaser_position_FluxPerBX_Macro()
{
  SetLuxeStyle();
  
  
	  
  TFile* FileSig=TFile::Open("gamma_laser_w0_5000nm_phase0_nbx1981_final.root");
 // TFile* FileSig=TFile::Open("gamma_laser_w0_8000nm_phase0_nbx1943_final.root");

  TFile* FileBkg=TFile::Open("GammaLaserBkg_final.root");
  
  TH1D* H_photon_sig  =(TH1D*)FileSig->Get("CaloPos_FrontPlate/CaloPos_FrontPlate_xp_photon");
  TH1D* H_photon_bkg  =(TH1D*)FileBkg->Get("CaloPos_FrontPlate/CaloPos_FrontPlate_xp_photon");
  TH1D* H_positron_sig=(TH1D*)FileSig->Get("CaloPos_FrontPlate/CaloPos_FrontPlate_xp_positron");
  TH1D* H_positron_bkg=(TH1D*)FileBkg->Get("CaloPos_FrontPlate/CaloPos_FrontPlate_xp_positron");
  TH1D* H_electron_sig=(TH1D*)FileSig->Get("CaloPos_FrontPlate/CaloPos_FrontPlate_xp_electron");
  TH1D* H_electron_bkg=(TH1D*)FileBkg->Get("CaloPos_FrontPlate/CaloPos_FrontPlate_xp_electron"); 
  


  H_photon_bkg->GetXaxis()->SetTitle("x position [mm]");
  // H_positron_sig->GetYaxis()->SetTitle("#sum E/BX [GeV]");
  H_photon_bkg->GetYaxis()->SetTitle("Particles / BX");
  
  H_photon_bkg->GetXaxis()->SetTitleOffset(1.4);
  H_photon_bkg->GetYaxis()->SetTitleOffset(1.4);
  H_photon_bkg->GetYaxis()->SetRangeUser(1e-3,1e6);
  // H_photon_bkg->GetXaxis()->SetRangeUser(0,700);
  
  // H_photon_sig->SetLineColor(kRed);
  H_photon_bkg->SetLineColor(kRed);
  H_positron_bkg->SetLineColor(kBlue);
  H_electron_bkg->SetLineColor(kBlack);
  
  // H_photon_bkg->SetLineStyle(2);
  
  H_positron_sig->SetLineColor(kGray);
  H_positron_sig->SetFillColor(kGray);
  // H_positron_bkg->SetLineStyle(2);
  
  // H_positron_bkg->SetLineStyle(2);
  
  
  // H_electron_sig->SetLineColor(kBlack);
  // H_electron_sig->SetLineColor(kBlack);
  // H_electron_bkg->SetLineStyle(2);

  
  
  // and plot it
  // H_positron_sig->Draw("Hist");
  H_photon_bkg  ->Draw("Hist");
  H_positron_bkg->Draw("Hist&&same");
  H_electron_bkg->Draw("Hist&&same");
  
  


  //make a legend
  TLegend* leg=new TLegend(0.6,0.65,0.92,0.9);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->SetTextSize(0.05);
  // leg->AddEntry(H_positron_sig,"e^{+}, Signal w_{0}=5#mum","f");
  leg->AddEntry(H_photon_bkg,"#gamma, Background","l");
  leg->AddEntry(H_electron_bkg,"e^{-}, Background","l");
  leg->AddEntry(H_positron_bkg,"e^{+}, Background","l");
  leg->Draw();

  gPad->SetLogy();

#ifdef __CINT__
  gROOT->LoadMacro("LuxeLabels.C");
#endif

  LUXELabel(0.2,0.85,"CDR");
  TLatex l; //l.SetTextAli
  l.SetNDC();
  l.SetTextFont(52);
  // l.SetTextSize(10);
  
  l.SetTextColor(kBlack);
  l.DrawLatex(0.2,0.80,"Calorimeter - #gamma-laser");
  gPad->RedrawAxis();
  
  gPad->Print("Calorimeter_glaser_position_FluxPerBX.png");
  gPad->Print("Calorimeter_glaser_position_FluxPerBX.C");

  return;
}

#ifndef __CINT__
int main() { 
  Calorimeter_glaser_position_FluxPerBX_Macro();

  
  return 0;
}
#endif
