
//best and easy  logic -min cost path

int minimumCostPath(vector<vector<int>>& grid) 

    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int i=0, j=0;
        
        vector<vector<int>> dist(m+1, vector<int>(n+1, INT_MAX));
        
        dist[i][j] = grid[0][0];
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            int cd = it.first;
            int cx = it.second.first;
            int cy = it.second.second;
            pq.pop();
            
            for(int k=0; k<4; k++){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                
                if(nx>=0 and ny>=0 and nx<n and ny<m and cd+grid[nx][ny] < dist[nx][ny]){
                    int nd = grid[nx][ny]+cd;
                    dist[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
        
        return dist[n-1][m-1];
        
    }