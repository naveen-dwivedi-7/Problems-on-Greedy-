#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// sort by second element in inc order
bool Compare_Interval(const pair<int, int> &a, const pair<int, int>&b){
   return (a.second<b.second);
}
  
  int main(){
       int N;
       cin>>N;
       int arr[N],dep[N];
       for(int i=0;i<N;i++){
        cin>>arr[i];
       }
        cout<<"\n";
      for(int i=0;i<N;i++){
        cin>>dep[i];
       }
        cout<<"\n";
         sort(arr, arr+N);
         sort(dep, dep+N);
       int maxtrain=0;
       int platform=0;
       int i=0, j=0;
       while(i<N && j<N){
       if(arr[i]<=dep[j]){
           maxtrain++;
           i++;
        }
       else{
            maxtrain--;
            j++;
       }
           platform=max(platform, maxtrain);
     }
     
      cout<<platform;
  }