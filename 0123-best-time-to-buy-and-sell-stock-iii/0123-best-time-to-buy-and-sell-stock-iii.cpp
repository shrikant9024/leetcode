class Solution {
public:
    int f(int i, int trans,vector<int>&prices,vector<vector<int>>&dp){
        int n = prices.size();
        if(i==n || trans==4) return 0;
        
        if(dp[i][trans]!=-1) return dp[i][trans];
        int profit = 0;
        if(trans%2==0){
            profit = max(-prices[i]+f(i+1,trans+1,prices,dp),f(i+1,trans,prices,dp));
        }
        else {
            profit = max(prices[i]+f(i+1,trans+1,prices,dp),f(i+1,trans,prices,dp));
            
        }
        dp[i][trans] = profit;
        return dp[i][trans];
        
    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(0,0,prices,dp);
    }
};