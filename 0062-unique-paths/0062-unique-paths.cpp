class Solution {
public:

    int uniquePaths(int m, int n) {
    vector<vector<long long>> dp(m,vector<long long>(n,0));
        for(int i =0;i<m;i++) dp[i][0] = 1;
        for(int j =0;j<n;j++) dp[0][j] = 1;
        
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                int up = dp[i-1][j];
                int left = dp[i][j-1];
                
                dp[i][j] = left + up; 
            }
        }
        return dp[m-1][n-1];
    }
};