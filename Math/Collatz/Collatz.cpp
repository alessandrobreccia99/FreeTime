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

void Collatz(){
    long int y=10000;
    TH2F *graph = new TH2F("graph","Collatz results",10000,-0.01,10000,10000,0,300);
    int i=0;
    long int x=0;
    long int z=0;
    for(x=1; x<y; x++){
        i=0;
        z=x;
      while(z!=1){
          if(z%2==0) z=z/2;
          else z=3*z+1;
          i++;
      }
        graph->Fill(x,i);
    }
    TCanvas *c= new TCanvas("c","Canvas1",500,100,400,300);
    graph->Draw();
    c->cd();
}
