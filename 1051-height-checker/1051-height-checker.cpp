class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int>expected(n);
        
        for(int i =0;i<n;i++){
            expected[i] = heights[i];
        }
        sort(expected.begin(),expected.end());
        int count = 0;
        
        for(int i =0;i<n;i++){
            if(heights[i]!=expected[i]) count++;
            else continue;
        }
        return count;
    }
};