#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
 int T;
 cin>>T;
  while(T--){
      int p;
  cin>>p;
  int curr_pow,total_items=0;;
    for(int i=11;i>=0;--i){
      curr_pow=pow(2, i);
        while(p>=curr_pow){
          p=  p-curr_pow;
          ++ total_items;
        }
    }
    cout<<total_items<<endl;
  }


}