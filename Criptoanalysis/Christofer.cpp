#include <iostream>
#include "string"
#include "vector"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <algorithm>
#include <map>

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

while(file>>word){
phrase+=word+" ";
}

char letter;
float freq=0;
vector <float> f;

while(alphfile>>letter){
   alph.push_back(letter);
   alphfile>>freq;
   f.push_back(freq/100);
}
/*
for (int i = 0; i < f.size(); i++){
   cout<<alph.at(i)<<" ";
   cout<<f.at(i)<<endl;
}
*/
int sz=phrase.length();
int asz=alph.length();
int f;
map<float,char> m;

for (int i = 0; i < asz; i++){
      for (int j=0; j<sz; j++){
           if(phrase.at(j)==alph.at(i)) f++;
     }
    m.insert(phrase.at(i),)   
}



return 0;
}
