class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int mini = INT_MAX;
        
        for(auto it : prices){
            mini = min(it,mini);
            maxprofit = max(maxprofit,it-mini);
        }
        
        return maxprofit;
    }
};