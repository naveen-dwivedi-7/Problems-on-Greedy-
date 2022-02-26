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
       int S[N],E[N];
       for(int i=0;i<N;i++){
        cin>>S[i];
       }
        cout<<"\n";
      for(int i=0;i<N;i++){
        cin>>E[i];
       }
        cout<<"\n";

      
           vector<pair<int, int>>Vec_int;
        
     
       for(int i=0;i<N;i++){
           Vec_int.push_back(make_pair(S[i], E[i]));
       }
        for(int i=0;i<N; i++){
            cout<<Vec_int[i].first<<"  "<< Vec_int[i].second<<endl; 
        }
        // Now  sort by second element
       sort(Vec_int.begin(), Vec_int.end(),Compare_Interval);
         cout<<"After sorting:"<<endl;
         for(int i=0;i<N; i++){
            cout<<Vec_int[i].first<<"  "<< Vec_int[i].second<<endl; 
        }
            int count=1;
            int d=Vec_int[0].second;
            for(int i=1;i<N;i++)
            {
                if(Vec_int[i].first>d){
                  ++count;
                  d=Vec_int[i].second;
                   }
          
            }

          cout<<count;      

       
      
            
  }