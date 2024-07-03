class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        dist[0][0] = 1;
        
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            for(int dr =-1;dr<=1;dr++){
                for(int dc = -1;dc<=1;dc++){
                    int nrow = row + dr;
                    int ncol = col + dc;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && 1 + dis < dist[nrow][ncol]){
                        dist[nrow][ncol] = 1 + dis;
                        if(nrow==(n-1) && ncol==(n-1) ) return 1 + dis;
                        q.push({1+dis,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};