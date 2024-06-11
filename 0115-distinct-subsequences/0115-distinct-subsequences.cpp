class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<double> prev(n + 1, 0);
        
        prev[0] = 1;  // When t is an empty string, there's exactly one subsequence in any prefix of s that matches it: the empty subsequence
        
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] = prev[j - 1] + prev[j];
                } 
            }
        }
        
        return (int)prev[n];
    }
};
