class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> res;
        
        int sumEven = 0;
        for(auto it : nums){
            if(it%2==0) sumEven +=it;
        }
        
        for(auto it : queries){
            int val = it[0];
            int idx = it[1];
            
            if(nums[idx]%2==0){
                sumEven -=nums[idx];
            }
            nums[idx] +=val;
            if(nums[idx]%2==0){
                sumEven +=nums[idx];
            }
            
            res.push_back(sumEven);
        }
        return res;
        
    }
};