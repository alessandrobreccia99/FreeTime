#include <iostream>
#include "string"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <iomanip>
#include <TH2.h>
#include <TH3.h>
#include <TRandom2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>

using namespace std;

void Ranwalk(){
    TRandom2 *rand=new TRandom2();
    long int n=1000;
    long int iter=1000;
//    TH1F *graph = new TH1F("graph","Random walk simulation",1400,-700,700);
//      TH2F *graph = new TH2F("graph","Random walk simulation",400,-200,200,400,-200,200);
    TH3F *graph = new TH3F("graph","Random walk simulation",400,-200,200,400,-200,200,400,-200,200);
    for (int j=0; j<iter; j++) {
    int x=0;
    int y=0;
    int z=0;
      for(int i=0; i<n; i++){
        float ran=rand->Rndm();
          if(ran<(1.0/6.0)){
              x=x+1;
          }
          else if(ran>(1.0/6.0) && ran<(2.0/6.0)){
              x=x-1;
          }
          else if(ran>(2.0/6.0) && ran<(3.0/6.0)){
              y=y+1;
          }
          else if(ran>(3.0/6.0) && ran<(4.0/6.0)){
              y=y-1;
          }
          else if(ran>(4.0/6.0) && ran<(5.0/6.0)){
              z=z+1;
          }
          else{
              z=z-1;
          }
      }
        graph->Fill(x,y,z);
    }

    TCanvas *c= new TCanvas("c","Canvas1",500,100,400,300);
    graph->Draw();
    c->cd();
}
