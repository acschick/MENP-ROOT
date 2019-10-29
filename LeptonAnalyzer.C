#define LeptonAnalyzer_cxx
#include "LeptonAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

const double ElectronMass = 5.109989461e-4;

void LeptonAnalyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L LeptonAnalyzer.C
//      root> LeptonAnalyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch



   TLorentzVector p1; TLorentzVector p2;


   TFile* oFile = TFile::Open("Histograms.root", "RECREATE");
   TH1F* Hist_W2e = new TH1F("W2e", ";Invariant Mass (GeV/c^2)", 234, 0, 1.4);


   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;


      p1.SetXYZM(p1x,p1y,p1z,ElectronMass); //v=(x,y,z,e=Sqrt(x*x+y*y+z*z+m*m))
      p2.SetXYZM(p2x,p2y,p2z,ElectronMass);

      double W2e = sqrt((p1 + p2).Mag2()); 

      Hist_W2e->Fill(W2e);   

      

   }

   oFile->Write();
   oFile->Close();

}
