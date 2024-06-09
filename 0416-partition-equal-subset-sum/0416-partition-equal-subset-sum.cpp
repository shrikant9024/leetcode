class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k+1, false), cur(k+1, false);
        prev[0] = true; 
        if (arr[0] <= k) prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            cur[0] = true; 
            for (int T = 1; T <= k; T++) {
                bool notpick = prev[T];
                bool pick = false;
                if (arr[i] <= T) {
                    pick = prev[T - arr[i]];
                }
                cur[T] = pick || notpick;
            }
            prev = cur; 
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        if (sum % 2 != 0) return false; 
        int target = sum / 2;
        return subsetSumToK(n, target, nums);
    }
};
