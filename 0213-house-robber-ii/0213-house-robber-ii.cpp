class Solution {
public:
     int rob1(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
     vector<int> temp1,temp2;
        if(n==1) return nums[0];
        for(int i =0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
            
        }
        
        return max(rob1(temp1),rob1(temp2));        
        
        
    }
};