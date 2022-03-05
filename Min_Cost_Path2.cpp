  #include<bits/stdc++.h>

using namespace std;
  

void addEdge(vector<vector<int>>&adj,int i , int j ,int wt){
  adj[i][j]=wt; // undirected weighted graph
//   adj[j][i]=wt;
}

bool valid(int i, int j, int N){
 if(i<0 || i>=N || j<0 || j>=N  ){
     return 0; // if visited return 0 else 1
 }
 return 1;
}
void min_cost(vector<vector<int>>&adj,int N){
   vector<vector<int>>dist(N, vector<int>(N,INT_MAX)); // distance 2D array=
   
   // Make a bool array to mark visited cells.
	// Initially all cells are unvisited
   
    // bool visited[N][N];
  
    
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
          
    //         visited[i][j] = 0;
    //     }
    // }
    dist[0][0]=adj[0][0]; // base case
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> >pq;
     //In general priority queue is max heap, but here priority act as a min heap , top element of priority is minimum
     int dx[]={1, -1, 0, 0};
     int dy[]={0, 0, 1,-1};

     pq.push({dist[0][0], {0,0}});
     while(!pq.empty()){
        auto it=pq.top(); // it is a priority queue iterator, it point to top element in priority queue
        int cur_d=it.first; // current cost or current distance
        int cur_x=it.second.first;
        int cur_y=it.second.second;
         // Mark this cell as visited
	   //visited[cur_x][cur_y] = 1; 
        pq.pop(); // remove top element in priority queue
          for(int k=0;k<4;k++){
              
 //           examine all non-visited adjacent units in 8 directions 
 //           calculate the accumulated cost of path for
 //           each next move from this unit,
  //          adjust the cost of path for each next adjacent
  //          units to the minimum if possible.
                 int next_x=cur_x+dx[k];
                 int next_y=cur_y+dy[k];
                 cur_d = dist[cur_x][cur_y];
                   if(valid(next_x, next_y, N)){
                     if(dist[next_x][next_y]>= cur_d+ adj[next_x][next_y]){
                      //    update  new distance or cost  newd to cur_d + dis[next_x][next_y]
                            dist[next_x][next_y]= cur_d+ adj[next_x][next_y];  
                      //    update in adj matrix or say in grid of N x N and push into priority queue pw
                           
                            pq.push({ dist[next_x][next_y] ,{next_x, next_y}});
                     }

                   }

          }

     }

    cout<<"\n Your Min cost path:"<<dist[N-1][N-1];

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
    min_cost(adj, N); 

 return 0;

}
