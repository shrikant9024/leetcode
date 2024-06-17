class Solution {
public:
    void bfs(int node, vector<int> &vis,unordered_map<int,vector<int>> adj){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adj list
        int V = isConnected.size();
        unordered_map<int,vector<int>> adj;
            for(int i =0;i<V;i++){
                for(int j =0;j<V;j++){
                    if(isConnected[i][j]==1){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        
        vector<int> vis(V,0);
        int count = 0;
        for(int i =0;i<V;i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                count++;
            }
        }
        return count;
    }
};