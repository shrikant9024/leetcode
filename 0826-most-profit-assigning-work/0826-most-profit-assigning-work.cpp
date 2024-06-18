class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>>pq;
        int n = difficulty.size();
        
        for(int i =0;i<n;i++){
            pq.push({profit[i],difficulty[i]});
        }
        
        sort(worker.begin(),worker.end(),greater<int>());
        int maxprofit = 0;
        int m = worker.size();
        int i = 0;
        while(i<m && !pq.empty()){
            if(pq.top().second> worker[i]){
                pq.pop();
            }
            else{
                maxprofit += pq.top().first;
                i++;
        }   
            } 
        return maxprofit;
    }
};