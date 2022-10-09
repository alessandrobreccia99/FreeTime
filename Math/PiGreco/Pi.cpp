#include <iostream>
#include "string"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <iomanip>

using namespace std;
/*
int main(){
    long double l=sqrt(2);
    long double per=0;
    int i=4;
    long double diff=1;
    cout<<"Lato di partenza lungo "<<l<<endl;
    while(diff>0.000000000000001){
        per=l*i;
        cout<<"Approx pi= "<<setprecision(15)<< per/2<<" con poligono di lati "<<i<<endl;
        l=sqrt(pow(l/2,2)+pow(1-sqrt(1-pow(l/2,2)),2));
        i=i*2;
        diff=fabs(M_PI-per/2);
        cout<<"Diff "<<diff<<endl;
    }
return 0;
}
*/
int main(){
    long double l=0;
    double per=0;
    int j=4;
    int last=0;
    long double diff=1;
    double ang=0;
    while(diff>0.00000000001){
           ang=3.14159265358979323846/j;
        per=j*2*sin(ang);
        //cout<<"Approx pi= "<<setprecision(15)<< per/2<<" con poligono di lati "<<j<<endl;
        j++;
        diff=fabs(3.14159265358979323846-per/2);
        //cout<<"Diff "<<diff<<endl;
        last=j;
    }
    cout<<"Approx pi= "<<setprecision(15)<< per/2<<" con poligono di lati "<<last<<endl;
return 0;
}
