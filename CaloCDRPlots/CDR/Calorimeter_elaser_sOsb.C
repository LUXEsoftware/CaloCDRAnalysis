void Calorimeter_elaser_sOsb()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Jan 14 16:02:52 2021) by ROOT version 6.22/02
   TCanvas *c1 = new TCanvas("c1", "c1",10,32,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->Range(-1.43038,0.2974684,13.75949,1.563291);
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
   1.00832,
   1.019566,
   1.034873,
   1.041418,
   1.049733,
   1.074386,
   1.097681,
   1.115154,
   1.154252,
   1.195793,
   1.235047};
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
   0.02828175,
   0.02955299,
   0.03191061,
   0.03086495,
   0.03337185,
   0.03734034,
   0.03605097,
   0.03827211,
   0.04225813,
   0.05322544,
   0.04764233};
   TGraphErrors *gre = new TGraphErrors(11,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("S/S+B");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","S/S+B",100,1,13);
   Graph_Graph01001->SetMinimum(0.5);
   Graph_Graph01001->SetMaximum(1.5);
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
   Graph_Graph01001->GetYaxis()->SetTitle("#bar{E_{S+B}}/#bar{E_{S}}");
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
   
   gre->Draw("ap");
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
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
