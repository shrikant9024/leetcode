class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        //base cond- i==n, i>1
        
        dp[0] = nums[0];
        
        for(int i =1;i<n;i++){
            int notpick = dp[i-1];
            int pick = nums[i];
            if(i>1){
                pick+= dp[i-2];
            }
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
        
    }
};