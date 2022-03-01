#include<bits/stdc++.h>
#include<iostream>

using namespace std;
struct jobs_seq{
    int job_id;
    int profit;
    int deadline;


 };
 
 bool compare(jobs_seq &J1 , jobs_seq &J2){ 
  return (J1.profit>J2.profit);
 }

int main(){

int N;
cin>>N;

 jobs_seq job[N];
 
  for(int i=0;i<N;i++){
      cin>>job[i].job_id>>job[i].deadline>>job[i].profit;
     

  }

// sort struct job  by profit in  dec order
sort(job, job+N, compare);


cout<<"After Sorting:"<<endl;
for(int i=0;i<N;i++){
      cout<<job[i].job_id<<" "<<job[i].deadline<<" "<<job[i].profit;
      cout<<endl;

  }

  int maxi=job[0].deadline;
  for(int i=1;i<N;i++){
     if(job[i].deadline>maxi){
       maxi=job[i].deadline;
     }
  }
 // cout<<maxi<<endl;
  int slots[maxi+1];
  for(int i=0;i<=maxi;i++){
    slots[i]=-1;
  }
int countjobs=0;
int jobprofit=0;

  for(int i=0;i<N;i++){ //iterate over job all job id 
    // cout<<job[i].job_id<<endl;
      for(int j=job[i].deadline;j>0;j--){ // take slot  as late as possible
        if(slots[j]==-1){
          slots[j]=i;
          countjobs++;
          jobprofit += job[i].profit;
          break;
        }
      }
  }
     cout<<"\n No of jobs are:"<<countjobs<<endl;
     cout<<"job profit is:"<<jobprofit;
  
  return 0;
}
