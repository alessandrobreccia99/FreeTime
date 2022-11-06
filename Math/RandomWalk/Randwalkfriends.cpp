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

void Randwalkfriends(){
    TRandom2 *rand1=new TRandom2();
    long int iter=10000;
    TH1F *time = new TH1F("time","Random walk simulation",iter,0,iter);
    int l;
    float N=0;
    cout<<"Insert distance between them: "<<endl;
    cin>>l;
    for (int j=0; j<iter; j++) {
        int x1=0;
        int x2=l;
        int n=0;
        while(x1!=x2){
                float ran1=rand1->Rndm();
            if(ran1<0.25){
                x1=x1-1;
                x2=x2-1;
            }
            else if(ran1>0.25 && ran1<0.5){
                x1=x1+1;
                x2=x2+1;
            }
            else if(ran1>0.5 && ran1<0.75){
                x1=x1+1;
                x2=x2-1;
            }
            else {
                x1=x1-1;
                x2=x2+1;
            }
            n++;
            if(n==3000) break;
        }
        time->Fill(n);
    }
    TCanvas *c1= new TCanvas("c1","Canvas1",500,100,400,300);
    time->Draw();
    c1->cd();
}
    
    
    
    
    
    
/*
    TRandom2 *rand=new TRandom2();
    long int n=1000;
    long int iter=1000;
    int dim;
    while(1){
        cout<<"Insert dimension, insert 0 to quit"<<endl;
        if(dim==0) break;
        cin>>dim;
        if(dim==1){
            TH1F *graph = new TH1F("graph1","Random walk simulation",1400,-700,700);
            for (int j=0; j<iter; j++) {
                int x=0;
                for(int i=0; i<n; i++){
                    float ran=rand->Rndm();
                    if(ran<0.5) x=x-1;
                    else x=x+1;
                }
                graph->Fill(x);
            }
            TCanvas *c1= new TCanvas("c1","Canvas1",500,100,400,300);
            graph->Draw();
            c1->cd();
        }
        else if(dim==2){
            TH2F *graph = new TH2F("graph2","Random walk simulation",600,-300,300,600,-300,300);
            for (int j=0; j<iter; j++) {
                int x=0;
                int y=0;
                for(int i=0; i<n; i++){
                    float ran=rand->Rndm();
                    if(ran<0.25) x=x-1;
                    else if(ran>0.25 && ran <0.5) x=x+1;
                    else if(ran>0.5 && ran <0.75) y=y-1;
                    else y=y+1;
                    }
                graph->Fill(x,y);
            }
            TCanvas *c2= new TCanvas("c2","Canvas1",500,100,400,300);
            graph->Draw();
            c2->cd();
        }
        else if(dim==3){
            TH3F *graph = new TH3F("graph3","Random walk simulation",400,-200,200,400,-200,200,400,-200,200);
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
            TCanvas *c3= new TCanvas("c3","Canvas1",500,100,400,300);
            graph->Draw();
            c3->cd();
        }
    }
}
*/
