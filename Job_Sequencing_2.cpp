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

int main(){

int N;
cin>>N;

 jobs_seq job[N];
 
  for(int i=0;i<N;i++){
      cin>>job[i].job_id>>job[i].profit>>job[i].deadline;
     

  }

// sort struct job  by profit in  dec order
sort(job, job+N, compare);


cout<<"After Sorting:"<<endl;
for(int i=0;i<N;i++){
      cout<<job[i].job_id<<" "<<job[i].profit<<"  "<<job[i].deadline;
      cout<<endl;

  }
  return 0;
}
