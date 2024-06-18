class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V,0);
        queue<int> q;
        vector<int> res;
        
        for(int i =0;i<V;i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        for (int i =0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};