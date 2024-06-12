class Solution {
public:
    int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        // base case
        int n = nums.size();
        if (i == n) return 0;
        
        // Adjust prev to be in the range of [0, n] for dp indexing
        int adjustedPrev = prev + 1;

        if (dp[i][adjustedPrev] != -1) return dp[i][adjustedPrev];

        // not pick
        int len = f(i + 1, prev, nums, dp);

        // pick
        if (prev == -1 || nums[i] > nums[prev]) {
            len = max(len, 1 + f(i + 1, i, nums, dp));
        }

        return dp[i][adjustedPrev] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));  // Adjusted size for dp array
        return f(0, -1, nums, dp);
    }
};
