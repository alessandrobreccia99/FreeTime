#include <iostream>
#include "string"
#include "vector"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

int main(){
string name,alphname,out="_out";
cout<<"Write input file name: ";
cin>>name;
cout<<"Write alphabet file name: ";
cin>>alphname;
ifstream file(name,ios::in);
ifstream alphfile(alphname,ios::in);
string word;
string phrase;
string alph;

while(!file.eof()){
file>>word;
phrase+=word+" ";
}
float freq=0;
vector <float> f;
while(!alphfile.eof()){
alphfile>>alph;
alphfile>>freq;
f.push_back(freq);
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

int alphsize=alph.length();
/*
cout<<endl;
for(int i=0; i<sz; i++){  
    cout<<num[i]<<" ";
}
*/
// ****************************   Input trasformato *********************************

int k[alphsize][alphsize];

for (int j=0; j<alphsize; j++){
 if(alph.at(j)=='a') k[j][0]=1;
 else if (alph.at(j)=='b') k[j][0]=2;
 else if (alph.at(j)=='c') k[j][0]=3;
 else if (alph.at(j)=='d') k[j][0]=4;
 else if (alph.at(j)=='e') k[j][0]=5;
 else if (alph.at(j)=='f') k[j][0]=6;
 else if (alph.at(j)=='g') k[j][0]=7;
 else if (alph.at(j)=='h') k[j][0]=8;
 else if (alph.at(j)=='i') k[j][0]=9;
 else if (alph.at(j)=='j') k[j][0]=10;
 else if (alph.at(j)=='k') k[j][0]=11;
 else if (alph.at(j)=='l') k[j][0]=12;
 else if (alph.at(j)=='m') k[j][0]=13;
 else if (alph.at(j)=='n') k[j][0]=14;
 else if (alph.at(j)=='o') k[j][0]=15;
 else if (alph.at(j)=='p') k[j][0]=16;
 else if (alph.at(j)=='q') k[j][0]=17;
 else if (alph.at(j)=='r') k[j][0]=18;
 else if (alph.at(j)=='s') k[j][0]=19;
 else if (alph.at(j)=='t') k[j][0]=20;
 else if (alph.at(j)=='u') k[j][0]=21;
 else if (alph.at(j)=='v') k[j][0]=22;
 else if (alph.at(j)=='w') k[j][0]=23;
 else if (alph.at(j)=='x') k[j][0]=24;
 else if (alph.at(j)=='y') k[j][0]=25;
 else if (alph.at(j)=='z') k[j][0]=26;

}


srand (time(NULL));


int c=0;
int n=0;

k[0][1]=rand()%26+1;
for (int j=1; j<alphsize; j++){
    while(true){
    n=rand()%alphsize+1;
    c=0;
    for(int i=0; i<j; i++){
        if(k[i][1]==n) c++;
    }
    if(c==0) break;
    }
    k[j][1]=n;
}
string newalph; 

for (int j=0; j<alphsize; j++){
        if(k[j][1]==1) newalph.push_back('a');
  else if (k[j][1]==2) newalph.push_back('b');
  else if (k[j][1]==3) newalph.push_back('c');
  else if (k[j][1]==4) newalph.push_back('d');
  else if (k[j][1]==5) newalph.push_back('e');
  else if (k[j][1]==6) newalph.push_back('f');
  else if (k[j][1]==7) newalph.push_back('g');
  else if (k[j][1]==8) newalph.push_back('h');
  else if (k[j][1]==9) newalph.push_back('i');
 else if (k[j][1]==10) newalph.push_back('j');
 else if (k[j][1]==11) newalph.push_back('k');
 else if (k[j][1]==12) newalph.push_back('l');
 else if (k[j][1]==13) newalph.push_back('m');
 else if (k[j][1]==14) newalph.push_back('n');
 else if (k[j][1]==15) newalph.push_back('o');
 else if (k[j][1]==16) newalph.push_back('p');
 else if (k[j][1]==17) newalph.push_back('q');
 else if (k[j][1]==18) newalph.push_back('r');
 else if (k[j][1]==19) newalph.push_back('s');
 else if (k[j][1]==20) newalph.push_back('t');
 else if (k[j][1]==21) newalph.push_back('u');
 else if (k[j][1]==22) newalph.push_back('v');
 else if (k[j][1]==23) newalph.push_back('w');
 else if (k[j][1]==24) newalph.push_back('x');
 else if (k[j][1]==25) newalph.push_back('y');
 else if (k[j][1]==26) newalph.push_back('z');
}

cout<<"K-";
for (int j=0; j<alphsize; j++){
      cout<<alph.at(j)<<" ";
    }
cout<<endl<<"  ";
for (int j=0; j<alphsize; j++){
      cout<<newalph.at(j)<<" ";
    }
cout<<endl;

for (int j=0; j<sz; j++){
        if(num[j]==1) phrase.at(j)=newalph.at(0);
  else if (num[j]==2) phrase.at(j)=newalph.at(1);
  else if (num[j]==3) phrase.at(j)=newalph.at(2);
  else if (num[j]==4) phrase.at(j)=newalph.at(3);
  else if (num[j]==5) phrase.at(j)=newalph.at(4);
  else if (num[j]==6) phrase.at(j)=newalph.at(5);
  else if (num[j]==7) phrase.at(j)=newalph.at(6);
  else if (num[j]==8) phrase.at(j)=newalph.at(7);
  else if (num[j]==9) phrase.at(j)=newalph.at(8);
 else if (num[j]==10) phrase.at(j)=newalph.at(9);
 else if (num[j]==11) phrase.at(j)=newalph.at(10);
 else if (num[j]==12) phrase.at(j)=newalph.at(11);
 else if (num[j]==13) phrase.at(j)=newalph.at(12);
 else if (num[j]==14) phrase.at(j)=newalph.at(13);
 else if (num[j]==15) phrase.at(j)=newalph.at(14);
 else if (num[j]==16) phrase.at(j)=newalph.at(15);
 else if (num[j]==17) phrase.at(j)=newalph.at(16);
 else if (num[j]==18) phrase.at(j)=newalph.at(17);
 else if (num[j]==19) phrase.at(j)=newalph.at(18);
 else if (num[j]==20) phrase.at(j)=newalph.at(19);
 else if (num[j]==21) phrase.at(j)=newalph.at(20);
 else if (num[j]==22) phrase.at(j)=newalph.at(21);
 else if (num[j]==23) phrase.at(j)=newalph.at(22);
 else if (num[j]==24) phrase.at(j)=newalph.at(23);
 else if (num[j]==25) phrase.at(j)=newalph.at(24);
 else if (num[j]==26) phrase.at(j)=newalph.at(25);
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
