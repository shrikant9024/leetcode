class Solution {
public:
    string removeStars(string s) {
        string res = "";
        
        for(int i =0;i<s.size();i++){
            if(s[i]=='*'){
                res.pop_back();
            }
            else res.push_back(s[i]);
        }
        return res;
    }
};