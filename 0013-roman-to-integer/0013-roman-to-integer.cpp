class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int res = 0;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(i<n-1 && mpp[s[i]]<mpp[s[i+1]]){
                res -=mpp[s[i]];
            }
            else res+=mpp[s[i]];
        }
        return res;
    }
};