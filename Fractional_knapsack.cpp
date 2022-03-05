#include<bits/stdc++.h>
using namespace std;

bool compare(int &a , int &b){
    return(a>b);

}
  int main(){
 int N=3, W=50;
  int values[N]={60,100,120};
  int weights[N]={10,20,30};
  int P_By_W[N];
  for(int i=0;i<N;i++){
      P_By_W[i]=(values[i])/(weights[i]);
  }
  sort(P_By_W, P_By_W, compare);
 for(int i=0;i<N;i++){
     cout<<P_By_W[i]<<"  ";
 }  
 float finalvalue=0.0;
    int curWeight = 0; // Current weight in knapsack
   for (int i = 0; i < N; i++) {
        // If adding Item won't overflow, add it completely
        if (curWeight + weights[i] <= W) {
            curWeight += weights[i];
            finalvalue += values[i];
        }
  
        // If we can't add current Item, add fractional part
        // of it
        else {
            int remain = W - curWeight;
            finalvalue +=values[i]
                          * ((double)remain
                             / (double)weights[i]);
            break;
        }
    }
  
    // print final value
     cout<<finalvalue;

  }