void readRoryVectors(string name) //takes argument of type string. We're going to give it a file name.
{
  gROOT->Reset(); 
  /* gROOT->Reset() is useful at the beginning of an unnamed script that you want
to execute multiple times. Because variables defined in an unnamed script
are in the global scope, one must delete variables created by previous
executions. */

  string outname(name);  //Start off by taking the same value as the input name
  outname.append(".root"); // and then append .root to the end of it. 
  TFile out_file(outname.c_str(),"RECREATE"); // Open a TFile 
  //And it's going to make that file, instead of with a fixed file name, it's going to use the input file name + .root

  // Create a TTree
  TTree *ntuple = new TTree("ntuple",name.c_str()); //Now we make a TTree, and we make it new in memory so it persists after the code runs. 
  
  // Read in from a file
  Long64_t nlines = ntuple->ReadFile(name.c_str(), "p1x:p1y:p1z:p2x:p2y:p2z",' '); //If we go look at what ReadFile for TTree does, delimiter is a comma, CSV, comma separated values. Read in a CSV format.
  //The data file itself can inform the ROOT code itself what types of data it needs to read in. It's going to recognize string. If you look at Porcello.csv, you'll see /C, or /F for float. C for char
  // If you don't specify, it assumes the NEXT thing u find has the same type as the previous one. Which is why some of them don't have /F or whatever after. 
  cout << " found " << nlines << " points" << endl ;
  
  // Print its contents
  ntuple->Print();

  // Write it to a root file
  out_file.Write();
  out_file.Close();

}
