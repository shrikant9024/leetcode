class Solution {
public:
    int f(int i,vector<int> &dp){
        if(i==0) return 1;
        if(i<1) return 1;
        if(dp[i]!=-1) return dp[i];
        
        int step1 = f(i-1,dp);
        int step2 = f(i-2,dp);
        
        dp[i] =  step1+step2;
        
        return dp[i];
    }
    int climbStairs(int n) {
    vector<int> dp(n,-1);
        return f(n-1,dp);
    }
};