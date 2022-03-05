#include<bits/stdc++.h>
using namespace std;
int mincostPath_better(int **input, int m, int n , int i , int j, int **ans ){
  // base case
  cout<<"i:"<<i<<"  "<<"j:"<<j<<endl;
  if(i==m-1 && j==n-1){
      cout<<"input[i][j]: "<<input[i][j]<<endl;
      return input[i][j];
  }
  // moves -Right , Down and Diagonal are allowed
  if( i>=m || j>=n){
      return INT_MAX;
  }
  // ans[i][j]- will save total minimum cost of path from
  // cell position at (i, j) to Right bottom-most cell at (m-1,n-1); 
  // our aim is ts to find cost of path from  cell at (0,0) i.e. ans[0][0]
  // ans[0][0] will min cost of path from 0,0 to m-1, n-1 cell .
  if(ans[i][j]!=-1){
     return ans[i][j];
  }
    // recursive case
    int x=mincostPath_better(input, m ,n, i+1,j, ans);
    // check is it valid to save ans
     if(x<INT_MAX){
          ans[i+1][j]=x;
    }
    int y=mincostPath_better(input, m ,n, i+1,j+1, ans);
    if(y<INT_MAX){
          ans[i+1][j+1]=y;
    }
    int z=mincostPath_better(input, m,n ,i, j+1, ans);
    if(z<INT_MAX){
          ans[i][j+1]=z;
    }
     ans[i][j]=min(x, min(y,z)) +input[i][j];
  
}

int mincostPath_better(int **input,int m , int n){
 int **ans=new int *[m]; // m x n matrix to save unique call answer
 for(int i=0;i<m;i++){
    ans[i]=new int [n];
     for(int j=0;j<n;j++){

         ans[i][j]=-1;
     }
  
 }

  return mincostPath_better(input , m, n, 0, 0 , ans);
}
int main(){
 int m, n;
 cin>>m>>n;
  cout<<endl;
 int **input=new int*[m];
 for(int i=0;i<m;i++ ){
     input[i] =new int[n];
      for(int j=0;j<n;j++){
         cin>>input[i][j];


      }
     
 }
 cout<<mincostPath_better(input, m,n);  


}