class Solution {
public:
    void comb(int ind, int target, vector<int> &ans,vector<vector<int>>&res,vector<int> &arr){
        
            if(target==0){
                res.push_back(ans);
                return;

            }
        
        
        
       for(int i = ind; i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])continue;
           if(arr[i]>target) break;
           ans.push_back(arr[i]);
           comb(i+1,target-arr[i],ans,res,arr);
           ans.pop_back();
       }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ans;
        
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        comb(0,target, ans, res, candidates);
        return res;
    }
};