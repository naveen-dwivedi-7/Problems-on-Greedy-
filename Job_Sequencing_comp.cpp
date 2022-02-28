#include<bits/stdc++.h>
#include<iostream>

using namespace std;
struct jobs_seq{
    int job_id;
    int profit;
    int deadline;


 };
 
 bool compare(jobs_seq J1 , jobs_seq J2){ 
  return (J1.profit>J2.profit);
 }
 

void jobscheduling(jobs_seq arr[], int N){
 sort(arr, arr+N, compare);
 // find maximum deadline
 int maxi=arr[0].deadline;
 for(int i=0;i<N;i++){
     maxi=max(maxi, arr[i].deadline)
 }

//initailly all slot are empty
int slots[maxi+1];
 for(int i=0;i<=maxi;i++){
     slots[i]=-1;
 }
int countjobs=0;
int jobprofit=0;
 for(int i=0;i<N;i++){ // iteare all job id  in dec order of id 
    for(int j=arr[i].deadline;j>0;j--){// for each job id check dead line as late as possible , if found set slot[j]=i;
       if(slots[j]=-1){
           slots[j]=i;
           countjobs++;
           jobprofit+=arr[i].profit;
           break;
       }  
    }
 }
      cout<<"\n No of jobs:"<<countjobs<<endl;
    cout<<" Maximum Profit:"<<jobprofit<<endl;




}
int main(){

int N;
cin>>N;

 jobs_seq job[N];
 
  for(int i=0;i<N;i++){
      cin>>job[i].job_id>>job[i].profit>>job[i].deadline;
        }

  jobscheduling(job, N);



  return 0;
}
