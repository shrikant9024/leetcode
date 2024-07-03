class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto it :flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int wt = it.second.second;
            q.pop();
            
            if(stops>k) continue;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edw = it.second;
                if(wt + edw < dist[adjnode] && stops<=k){
                    dist[adjnode] = wt + edw;
                    q.push({1 + stops, {adjnode, wt+edw}});
                }
            }  
        }
        
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};