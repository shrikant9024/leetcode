class Solution {
    void dfs(int node, vector<int> &vis,unordered_map<int,vector<int>>adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int count = 0;
       unordered_map<int,vector<int>>adj;
        for(int i =0;i<V;i++){
            for(int j =0 ;j<V;j++){
                if(isConnected[i][j]==1){
                     adj[i].push_back(j);
                adj[j].push_back(i);
                    
                }
               
            }
        }
        
        vector<int> vis(V,0);
        
        for(int i =0;i<V;i++){
            if(!vis[i] ){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count;
        
        
    }
};