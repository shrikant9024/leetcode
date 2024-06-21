class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
       queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}}); // {stops,{src, wt}}
        
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int wt = it.second.second;
            
            if(stops > k ) continue;
            for(auto i : adj[node]){
                int adjnode = i.first;
                int adjW = i.second;
                
                if(wt + adjW < dist[adjnode] && stops<=k){
                    dist[adjnode] = wt+adjW;
                    q.push({1+stops,{adjnode,wt+adjW}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
 
    }
};