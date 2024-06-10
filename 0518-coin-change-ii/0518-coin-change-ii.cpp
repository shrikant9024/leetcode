class Solution {
public:
    int f(int i, int D ,vector<int>&coins,vector<vector<int>>&dp){
        //base 
        if(i==0) {
            if(D%coins[0]==0) return 1;
            return 0;
        }
        
        
        if(dp[i][D]!=-1) return dp[i][D];
        int notpick = f(i-1,D,coins,dp);
        
       int pick  = 0;
        if(D>=coins[i]){
            pick = f(i,D-coins[i],coins,dp);
        }
        dp[i][D] =  pick + notpick;
        
        
        return dp[i][D];
        
        
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0),cur(amount+1,0);
        for(int T=0;T<=amount;T++) {
           prev[T] = (T%coins[0]==0);
        }
        
        for(int i =1;i<n;i++){
            for(int D = 0;D<=amount;D++){
                
                int notpick = prev[D];
        
                int pick  = 0;
                if(D>=coins[i]) pick = cur[D-coins[i]];
                cur[D] = pick+notpick;
        }
            prev = cur;
    }
        return prev[amount];
    }
};