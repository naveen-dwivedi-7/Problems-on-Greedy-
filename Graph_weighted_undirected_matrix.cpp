#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void addEdge(vector<vector<int>>&adj,int i , int j ,int wt){
  adj[i][j]=wt; // undirected weighted graph
  adj[j][i]=wt;
}

int main(){
  //  for  N X N matrix row and col value be same 
  int N;
  cin>>N;

  int row, col;
   row=N;
   col=N;
   vector<vector<int>>adj(row, vector<int>(col, 0));
   int wt;
   for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
             cin>>wt;
             
             addEdge(adj, i, j, wt);

         }
         cout<<endl;
   }
    cout<<"\n Your Graph is:\n";  
   for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
              cout <<adj[i][j]<<" ";

        }
        cout<<"\n";
   }
     

 return 0;

}