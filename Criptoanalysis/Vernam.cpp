#include <iostream>
#include "string"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

int main(){
string name,out="_out";
cout<<"Write file name: ";
cin>>name;
ifstream file(name,ios::in);
string word;
string phrase;

while(!file.eof()){
file>>word;
phrase+=word+" ";
}
int sz=phrase.size();
int num[sz];

for (int j=0; j<sz; j++){
 if(phrase.at(j)=='a') num[j]=1;
 else if (phrase.at(j)=='b') num[j]=2;
 else if (phrase.at(j)=='c') num[j]=3;
 else if (phrase.at(j)=='d') num[j]=4;
 else if (phrase.at(j)=='e') num[j]=5;
 else if (phrase.at(j)=='f') num[j]=6;
 else if (phrase.at(j)=='g') num[j]=7;
 else if (phrase.at(j)=='h') num[j]=8;
 else if (phrase.at(j)=='i') num[j]=9;
 else if (phrase.at(j)=='j') num[j]=10;
 else if (phrase.at(j)=='k') num[j]=11;
 else if (phrase.at(j)=='l') num[j]=12;
 else if (phrase.at(j)=='m') num[j]=13;
 else if (phrase.at(j)=='n') num[j]=14;
 else if (phrase.at(j)=='o') num[j]=15;
 else if (phrase.at(j)=='p') num[j]=16;
 else if (phrase.at(j)=='q') num[j]=17;
 else if (phrase.at(j)=='r') num[j]=18;
 else if (phrase.at(j)=='s') num[j]=19;
 else if (phrase.at(j)=='t') num[j]=20;
 else if (phrase.at(j)=='u') num[j]=21;
 else if (phrase.at(j)=='v') num[j]=22;
 else if (phrase.at(j)=='w') num[j]=23;
 else if (phrase.at(j)=='x') num[j]=24;
 else if (phrase.at(j)=='y') num[j]=25;
 else if (phrase.at(j)=='z') num[j]=26;
 else if (phrase.at(j)==' ') num[j]=27;
 else if (phrase.at(j)=='.') num[j]=28;
 else if (phrase.at(j)=='?') num[j]=29;
 else if (phrase.at(j)==',') num[j]=30;
 else if (phrase.at(j)=='"') num[j]=31;
}

cout<<"I-";
for(int i=0; i<sz; i++){
    cout<<phrase.at(i)<<" ";      
}
cout<<endl;
/*
cout<<endl;
for(int i=0; i<sz; i++){  
    cout<<num[i]<<" ";
}
*/
// ****************************   Input trasformato *********************************

int k[sz];
int enc[sz];

srand (time(NULL));

/*
int c=0;
int n=0;
k[0]=rand()%26+1;
for (int j=1; j<sz; j++){
    while(true){
    n=rand()%sz+1;
    c=0;
    for(int i=0; i<j; i++){
        if(k[i]==n) c++;
    }
    if(c==0) break;
    }
    k[j]=n;
}
*/

for (int j=0; j<sz; j++){
    k[j]=rand()%sz+1;
}

for (int i=0; i<sz; i++){
    if( num[i]<27) enc[i]=(num[i]+k[i])%26;
    else enc[i]=num[i];
}
cout<<"K-";
for (int j=0; j<sz; j++){
    cout<<k[j]<<" ";
}
cout<<endl;

for (int j=0; j<sz; j++){
       if(enc[j]==1) phrase.at(j)='a';
 else if (enc[j]==2) phrase.at(j)='b';
 else if (enc[j]==3) phrase.at(j)='c';
 else if (enc[j]==4) phrase.at(j)='d';
 else if (enc[j]==5) phrase.at(j)='e';
 else if (enc[j]==6) phrase.at(j)='f';
 else if (enc[j]==7) phrase.at(j)='g';
 else if (enc[j]==8) phrase.at(j)='h';
 else if (enc[j]==9) phrase.at(j)='i';
 else if (enc[j]==10) phrase.at(j)='j';
 else if (enc[j]==11) phrase.at(j)='k';
 else if (enc[j]==12) phrase.at(j)='l';
 else if (enc[j]==13) phrase.at(j)='m';
 else if (enc[j]==14) phrase.at(j)='n';
 else if (enc[j]==15) phrase.at(j)='o';
 else if (enc[j]==16) phrase.at(j)='p';
 else if (enc[j]==17) phrase.at(j)='q';
 else if (enc[j]==18) phrase.at(j)='r';
 else if (enc[j]==19) phrase.at(j)='s';
 else if (enc[j]==20) phrase.at(j)='t';
 else if (enc[j]==21) phrase.at(j)='u';
 else if (enc[j]==22) phrase.at(j)='v';
 else if (enc[j]==23) phrase.at(j)='w';
 else if (enc[j]==24) phrase.at(j)='x';
 else if (enc[j]==25) phrase.at(j)='y';
 else if (enc[j]==26) phrase.at(j)='z';
 else if (enc[j]==27) phrase.at(j)=' ';
 else if (enc[j]==28) phrase.at(j)='.';
 else if (enc[j]==29) phrase.at(j)='?';
 else if (enc[j]==30) phrase.at(j)=','; 
 else if (enc[j]==30) phrase.at(j)='"';  
}
cout<<"C-";
for (int i=0; i<sz; i++){
   cout<<phrase.at(i)<<" ";
}
cout<<endl;

ofstream filecrip(name.insert(name.length()-4,out),ios::out);
for(int i=0; i<sz; i++){
filecrip<<phrase.at(i);

}

return 0;
}
