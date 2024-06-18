class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //adj list
        unordered_map<int,vector<int>> adj;
        int V= prerequisites.size();
        int count = 0;
        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites){
            int a =it[0] ;
            int b = it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        queue<int> q;
        vector<int> res;
        
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            } 
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    count++;
                }
            }
        }
        
        if(count == numCourses) return res;
        else return {};
        
        
        
    }
};