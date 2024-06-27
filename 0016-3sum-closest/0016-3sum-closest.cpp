class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum  =0;
        int closestSum = 1e9;
        int n = nums.size();
        for(int i =0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<abs(target-closestSum)) closestSum = sum;
                if(sum>target) k--;
                else j++;
            }
        }
        return closestSum;
    }
};