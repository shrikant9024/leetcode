class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          vector<pair<int, int>> adj[n + 1];  
        
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});  // u --> v, wt
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);  
        
        pq.push({0, k});
        dist[k] = 0;
        
        while (!pq.empty()) {
            int wt = pq.top().first;   
            int node = pq.top().second; 
            pq.pop();
            
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int edW = it.second;
                if (wt + edW < dist[adjnode]) {
                    dist[adjnode] = wt + edW;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};