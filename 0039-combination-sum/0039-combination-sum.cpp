class Solution {
public:
    void comb(int i , int target, vector<int> &ans,vector<int>& arr,  vector<vector<int>> &res){
        if(i==arr.size()){
            if(target == 0 ){
                res.push_back(ans);
            }
            return;
        }
        
        //pick 
        if(arr[i]<=target){
            ans.push_back(arr[i]);
            comb(i,target-arr[i],ans,arr, res);
            ans.pop_back();
        }
        
        
        
        //not pick
        comb(i+1, target, ans,arr,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        comb(0, target, ans, candidates, res);
        return res;
        
    }
};