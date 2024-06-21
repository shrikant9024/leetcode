class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        if(n==1 && grid[0][0]==0) return 1;
       
        
        queue<pair<int,pair<int,int>>>q;
      vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int wt = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    int nrow = r + delrow;
                    int ncol = c + delcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && 1+wt<dist[nrow][ncol]){
                        dist[nrow][ncol] = 1+wt;
                        if(nrow==(n-1) && ncol == (n-1)) return 1+wt;
                        q.push({1+wt,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};