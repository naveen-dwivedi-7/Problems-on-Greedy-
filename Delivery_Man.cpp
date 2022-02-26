#include<bits/stdc++.h>
#include<iostream>
using namespace std;
  
 int main(){
   int N, X, Y;
   cin>>N;
   cin>>X;
   cin>>Y;
   int A[N], B[N];
   for(int i=0;i<N;i++){
   cin>>A[i];
   }
    cout<<endl;
   for(int i=0;i<N;i++){
    cin>>B[i];
   }
  //  sort(A, A+N);
  //  sort(B , B+N);
  int sum1=0, sum2=0, total;
                            // last X element fron array A
  for(int i=X-1;i<N;i++){ // N=5, X=3 , i=4, 3 , 2
      sum1=sum1+A[i];

  }
  for(int i=0;i<N-X;i--){
      sum2=sum2+B[i];
      
  }
  total=sum1 +sum2;
  cout<<total;
  return 0;
 } 