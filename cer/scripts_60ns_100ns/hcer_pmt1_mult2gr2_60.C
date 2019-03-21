void hcer_pmt1_mult2gr2_60(){
  gStyle->SetOptStat(111);
  gStyle->SetPaintTextFormat("5.4g");
  gStyle->SetTitleFontSize(0.06);
  gStyle->SetTitleOffset(0.06);
  gStyle->SetTitleFont(40);
  gStyle->SetTitleYOffset(1.1);
  gStyle->SetTitleXOffset(0.9);
  gStyle->SetTitleYSize(0.05);
  gStyle->SetTitleXSize(0.05);
  gStyle->SetLabelFont(40,"X");
  gStyle->SetLabelFont(40,"Y");
  gStyle->SetTitleFont(40,"X");
  gStyle->SetTitleFont(40,"Y");
  gStyle->SetLabelSize(0.034,"X");
  gStyle->SetLabelSize(0.034,"Y");
  gStyle->SetPaperSize(18,22);
  gStyle->SetAxisColor(17);

 

  

  auto f1 = new TFile("ROOTfiles/mar17_55ns_old_cer_6263_-1.root");
  auto f2 = new TFile("ROOTfiles/mar17_55ns_new_cer_6263_-1.root");




  TTree *t1 = (TTree *)f1->Get("T");
  TTree *t2 = (TTree *)f2->Get("T");



  TH1F *h1 = new TH1F("h1","Time Pmt1 Old Mult2 or More 55ns", 175, 70, 140);
  TH2F *h2 = new TH2F("h2","Amp vs Time Pmt1 Old Mult2 or More 55ns", 175, 70, 140, 620, -20, 1000); 
  TH1F *h3 = new TH1F("h3","Time Pmt1 New Mult2 or More 55ns", 175, 70, 140);
  TH2F *h4 = new TH2F("h4","Amp vs Time Pmt1 New Mult2 or More 55ns", 175, 70, 140, 620, -20, 1000);


  t1->Draw("H.cer.goodAdcTdcDiffTime[0]>>h1","H.cer.goodAdcMult[0]>=2");
  t1->Draw("H.cer.goodAdcPulseAmp[0]:H.cer.goodAdcTdcDiffTime[0]>>h2","H.cer.goodAdcMult[0]>=2");

  t2->Draw("H.cer.goodAdcTdcDiffTime[0]>>h3","H.cer.goodAdcMult[0]>=2");
  t2->Draw("H.cer.goodAdcPulseAmp[0]:H.cer.goodAdcTdcDiffTime[0]>>h4","H.cer.goodAdcMult[0]>=2");

  TCanvas *c1 = new TCanvas ("c1", "c1", 1000, 1000);
  c1->Divide(2,2);

  c1->cd(1);gPad->SetLogy();gPad->SetGrid();
  h1->Draw();
  h1->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime_PMT1");
  h1->GetXaxis()->CenterTitle();
  h1->GetYaxis()->SetTitle("Entries");
  h1->GetYaxis()->CenterTitle();
  // h1->SetLineWidth(1.5);

  c1->cd(2);gPad->SetLogz();gPad->SetGrid();
  h2->Draw("colz");
  h2->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime_PMT1");
  h2->GetXaxis()->CenterTitle();
  h2->GetYaxis()->SetTitle("H.cer.goodAdcPulseAmp");
  h2->GetYaxis()->CenterTitle();



  c1->cd(3);gPad->SetLogy();gPad->SetGrid();
  h3->Draw();
  h3->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime_PMT1");
  h3->GetXaxis()->CenterTitle();
  h3->GetYaxis()->SetTitle("Entries");
  h3->GetYaxis()->CenterTitle();
  //h3->SetLineWidth(1.5);

  c1->cd(4);gPad->SetLogz();gPad->SetGrid();
  h4->Draw("colz");
  h4->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime_PMT1");
  h4->GetXaxis()->CenterTitle();
  h4->GetYaxis()->SetTitle("H.cer.goodAdcPulseAmp");
  h4->GetYaxis()->CenterTitle();

  c1->SaveAs("pdf/hcer_pmt1_mult2gr2_55.pdf");




}
