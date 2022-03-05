#include<bits/stdc++.h>
using namespace std;
int Min_Cost_Path_brute(int **input, int m, int n , int i , int  j){
  // base case
  if(i==m-1 && j==n-1){
      return input[i][j];
  }
  // moves Right , Down and diagonal are allowed
   // check on boundary
   if( i>=m || j>=n){
      return INT_MAX;
  }
      // recursive  case

    int x=Min_Cost_Path_brute(input, m ,n, i,j+1);

    int y=Min_Cost_Path_brute(input, m ,n, i+1,j+1);
    int z=Min_Cost_Path_brute(input, m,n ,i+1, j);
    // simple calculation

    int ans=min(x, min(y,z))+ input[i][j];
    return ans;


}
int Min_Cost_Path_brute(int ** input, int m ,int n ){

  return Min_Cost_Path_brute(input, m, n, 0 ,0);

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
  cout<<Min_Cost_Path_brute(input,m ,n);

}