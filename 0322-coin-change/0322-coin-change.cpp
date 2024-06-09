class Solution {
    
public:
    int f(int i , int D, vector<int> &arr,vector<vector<int>> &dp){
        //base case
        if(i==0) {
            if(D%arr[0]==0) return D/arr[0];
            return 1e9;
        }
        
        if(dp[i][D]!=-1) return dp[i][D];
        
        
        //not pick
        int notpick = f(i-1,D,arr,dp);
        
        int pick = 1e9;
        
        if(arr[i]<=D) pick =1+ f(i,D-arr[i],arr,dp);
        dp[i][D]= min(pick,notpick);
        return dp[i][D];
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=  f(n-1,amount, coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};