class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum +=it;
        }
        int cs = 0;
        for(int i=0;i<n;i++){
            int ls = cs;
            int rs = sum - ls -nums[i];
            if(ls==rs) return i;
            cs+=nums[i];
        }
        return -1;
    }
};