void Calorimeter_elaser_EnergyResolution()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Mar 10 12:30:20 2021) by ROOT version 6.22/06
   TCanvas *c1 = new TCanvas("c1", "c1",10,32,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->Range(-1.43038,0.01962025,13.75949,0.2094937);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.16);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.16);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[11] = {
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12};
   Double_t Graph0_fy1001[11] = {
   0.1398911,
   0.1065499,
   0.09630551,
   0.08503381,
   0.08208737,
   0.07205452,
   0.07328179,
   0.06052916,
   0.06677205,
   0.05700072,
   0.05392986};
   Double_t Graph0_fex1001[11] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[11] = {
   0.004139878,
   0.003125781,
   0.002818997,
   0.002659446,
   0.002725204,
   0.002450148,
   0.00248043,
   0.001956616,
   0.002539798,
   0.002078022,
   0.001961806};
   TGraphErrors *gre = new TGraphErrors(11,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("#frac{#sigma_{E}}{E}");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","#frac{#sigma_{E}}{E}",100,1,13);
   Graph_Graph01001->SetMinimum(0.05);
   Graph_Graph01001->SetMaximum(0.2);
   Graph_Graph01001->SetDirectory(0);
   Graph_Graph01001->SetStats(0);
   Graph_Graph01001->SetLineWidth(2);
   Graph_Graph01001->SetMarkerStyle(20);
   Graph_Graph01001->SetMarkerSize(1.2);
   Graph_Graph01001->GetXaxis()->SetTitle("Positron Energy [GeV]");
   Graph_Graph01001->GetXaxis()->SetLabelFont(42);
   Graph_Graph01001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01001->GetXaxis()->SetTitleOffset(1.4);
   Graph_Graph01001->GetXaxis()->SetTitleFont(42);
   Graph_Graph01001->GetYaxis()->SetTitle("#frac{#sigma_{E}}{E}");
   Graph_Graph01001->GetYaxis()->SetLabelFont(42);
   Graph_Graph01001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01001->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph01001->GetYaxis()->SetTitleFont(42);
   Graph_Graph01001->GetZaxis()->SetLabelFont(42);
   Graph_Graph01001->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph01001->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph01001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01001);
   
   
   TF1 *Fun21002 = new TF1("Fun2","[0]/TMath::Sqrt(x)",1,13, TF1::EAddToList::kNo);
   Fun21002->SetFillColor(19);
   Fun21002->SetFillStyle(0);
   Fun21002->SetMarkerStyle(20);
   Fun21002->SetMarkerSize(1.2);
   Fun21002->SetLineWidth(3);
   Fun21002->SetChisquare(19.10075);
   Fun21002->SetNDF(10);
   Fun21002->GetXaxis()->SetLabelFont(42);
   Fun21002->GetXaxis()->SetLabelSize(0.05);
   Fun21002->GetXaxis()->SetTitleSize(0.05);
   Fun21002->GetXaxis()->SetTitleOffset(1.4);
   Fun21002->GetXaxis()->SetTitleFont(42);
   Fun21002->GetYaxis()->SetLabelFont(42);
   Fun21002->GetYaxis()->SetLabelSize(0.05);
   Fun21002->GetYaxis()->SetTitleSize(0.05);
   Fun21002->GetYaxis()->SetTitleOffset(1.4);
   Fun21002->GetYaxis()->SetTitleFont(42);
   Fun21002->SetParameter(0,0.1926669);
   Fun21002->SetParError(0,0.001900669);
   Fun21002->SetParLimits(0,0,0);
   Fun21002->SetParent(gre);
   gre->GetListOfFunctions()->Add(Fun21002);
   gre->Draw("ap");
   
   Double_t Graph1_fx1003[11] = {
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12};
   Double_t Graph1_fy1003[11] = {
   0.1398325,
   0.1094674,
   0.09779372,
   0.08407214,
   0.07843358,
   0.07114302,
   0.0699321,
   0.06248596,
   0.06678254,
   0.05794437,
   0.055806};
   Double_t Graph1_fex1003[11] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1003[11] = {
   0.003979772,
   0.003275662,
   0.003015901,
   0.002573637,
   0.002546122,
   0.002316681,
   0.002255448,
   0.002294741,
   0.002341068,
   0.00246393,
   0.002301463};
   gre = new TGraphErrors(11,Graph1_fx1003,Graph1_fy1003,Graph1_fex1003,Graph1_fey1003);
   gre->SetName("Graph1");
   gre->SetTitle("S+B: Sigma E Reco/ E Mean Reco (Gauss Fit) (GeV)");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph11003 = new TH1F("Graph_Graph11003","S+B: Sigma E Reco/ E Mean Reco (Gauss Fit) (GeV)",100,1,13);
   Graph_Graph11003->SetMinimum(0.04447376);
   Graph_Graph11003->SetMaximum(0.1528431);
   Graph_Graph11003->SetDirectory(0);
   Graph_Graph11003->SetStats(0);
   Graph_Graph11003->SetLineWidth(2);
   Graph_Graph11003->SetMarkerStyle(20);
   Graph_Graph11003->SetMarkerSize(1.2);
   Graph_Graph11003->GetXaxis()->SetTitle("Positron Energy (GeV)");
   Graph_Graph11003->GetXaxis()->SetLabelFont(42);
   Graph_Graph11003->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph11003->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph11003->GetXaxis()->SetTitleOffset(1.4);
   Graph_Graph11003->GetXaxis()->SetTitleFont(42);
   Graph_Graph11003->GetYaxis()->SetTitle(" Sigma E Reco/ E Mean Reco");
   Graph_Graph11003->GetYaxis()->SetLabelFont(42);
   Graph_Graph11003->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph11003->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph11003->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph11003->GetYaxis()->SetTitleFont(42);
   Graph_Graph11003->GetZaxis()->SetLabelFont(42);
   Graph_Graph11003->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph11003->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph11003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph11003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph11003);
   
   gre->Draw("p&&");
   
   TLegend *leg = new TLegend(0.52,0.6,0.92,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.05);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","e^{+} w/o bkg from beam","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","e^{+} w/ bkg from beam","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Fun2","#frac{19.3%}{#sqrt{E}}","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.2,0.85,"LUXE");
tex->SetNDC();
   tex->SetTextFont(52);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2982959,0.85,"CDR");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.8,"Calorimeter - e-laser");
tex->SetNDC();
   tex->SetTextFont(52);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *Graph_copy = new TH1F("Graph_copy","#frac{#sigma_{E}}{E}",100,1,13);
   Graph_copy->SetMinimum(0.05);
   Graph_copy->SetMaximum(0.2);
   Graph_copy->SetDirectory(0);
   Graph_copy->SetStats(0);
   Graph_copy->SetLineWidth(2);
   Graph_copy->SetMarkerStyle(20);
   Graph_copy->SetMarkerSize(1.2);
   Graph_copy->GetXaxis()->SetTitle("Positron Energy [GeV]");
   Graph_copy->GetXaxis()->SetLabelFont(42);
   Graph_copy->GetXaxis()->SetLabelSize(0.05);
   Graph_copy->GetXaxis()->SetTitleSize(0.05);
   Graph_copy->GetXaxis()->SetTitleOffset(1.4);
   Graph_copy->GetXaxis()->SetTitleFont(42);
   Graph_copy->GetYaxis()->SetTitle("#frac{#sigma_{E}}{E}");
   Graph_copy->GetYaxis()->SetLabelFont(42);
   Graph_copy->GetYaxis()->SetLabelSize(0.05);
   Graph_copy->GetYaxis()->SetTitleSize(0.05);
   Graph_copy->GetYaxis()->SetTitleOffset(1.4);
   Graph_copy->GetYaxis()->SetTitleFont(42);
   Graph_copy->GetZaxis()->SetLabelFont(42);
   Graph_copy->GetZaxis()->SetLabelSize(0.05);
   Graph_copy->GetZaxis()->SetTitleSize(0.05);
   Graph_copy->GetZaxis()->SetTitleOffset(1);
   Graph_copy->GetZaxis()->SetTitleFont(42);
   Graph_copy->Draw("sameaxis");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
