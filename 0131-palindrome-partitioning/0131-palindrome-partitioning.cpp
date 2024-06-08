class Solution {
public:
    
    //pallindrome check func
    bool isPal(string s, int start, int end){
        while(start<=end){
            if(s[start++]!= s[end--]){
                return false;
            }

        }
        return true;
        
    }
    
    //partition func
    
    void partition(int index, string s, vector<vector<string>> & res, vector<string> &ans){
        if(index==s.size()){
            res.push_back(ans);
            return;
        }
        
        
        for(int i =index;i<s.size();i++){
            if(isPal(s,index,i)){
                ans.push_back(s.substr(index, i-index+1));
                partition(i+1,s,res,ans);
                ans.pop_back();
            }
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        partition(0,s,res,ans);
        return res;
    }
};