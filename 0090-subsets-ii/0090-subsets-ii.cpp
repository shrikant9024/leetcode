class Solution {
public:
    void subset(int ind, vector<int> &ans,vector<vector<int>> &res,vector<int>&nums){
        
            res.push_back(ans);
    
        
        
        for(int i = ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1] ) continue;
            ans.push_back(nums[i]);
            subset(i+1,ans,res,nums);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        subset(0,ans,res,nums);
        return res;
    }
};