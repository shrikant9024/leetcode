class Solution {
public:
   int bfs(int row, int col, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{row, col}, k});
        vis[row][col][k] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto it = q.front();
                int r = it.first.first;
                int c = it.first.second;
                int Elmn = it.second;
                q.pop();
                
                if (r == m - 1 && c == n - 1) {
                    return steps;
                }
                
                for (int j = 0; j < 4; j++) {
                    int nrow = r + delrow[j];
                    int ncol = c + delcol[j];
                    
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                        int newElmn = Elmn - (grid[nrow][ncol] == 1 ? 1 : 0);
                        if (newElmn >= 0 && !vis[nrow][ncol][newElmn]) {
                            vis[nrow][ncol][newElmn] = 1;
                            q.push({{nrow, ncol}, newElmn});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        return bfs(0, 0, k, grid, vis);
    }
};