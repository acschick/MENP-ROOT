//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Oct 28 12:57:27 2019 by ROOT version 6.16/00
// from TTree ntuple/lepton_v18.dat
// found on file: lepton_v18.dat.root
//////////////////////////////////////////////////////////

#ifndef LeptonAnalyzer_h
#define LeptonAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class LeptonAnalyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         p1x;
   Float_t         p1y;
   Float_t         p1z;
   Float_t         p2x;
   Float_t         p2y;
   Float_t         p2z;

   // List of branches
   TBranch        *b_p1x;   //!
   TBranch        *b_p1y;   //!
   TBranch        *b_p1z;   //!
   TBranch        *b_p2x;   //!
   TBranch        *b_p2y;   //!
   TBranch        *b_p2z;   //!

   LeptonAnalyzer(TTree *tree=0);
   virtual ~LeptonAnalyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef LeptonAnalyzer_cxx
LeptonAnalyzer::LeptonAnalyzer(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("lepton_v18.dat.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("lepton_v18.dat.root");
      }
      f->GetObject("ntuple",tree);

   }
   Init(tree);
}

LeptonAnalyzer::~LeptonAnalyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LeptonAnalyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t LeptonAnalyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void LeptonAnalyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("p1x", &p1x, &b_p1x);
   fChain->SetBranchAddress("p1y", &p1y, &b_p1y);
   fChain->SetBranchAddress("p1z", &p1z, &b_p1z);
   fChain->SetBranchAddress("p2x", &p2x, &b_p2x);
   fChain->SetBranchAddress("p2y", &p2y, &b_p2y);
   fChain->SetBranchAddress("p2z", &p2z, &b_p2z);
   Notify();
}

Bool_t LeptonAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void LeptonAnalyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t LeptonAnalyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef LeptonAnalyzer_cxx
