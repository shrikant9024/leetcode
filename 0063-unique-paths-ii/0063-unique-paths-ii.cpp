class Solution {
public:
    int f(int i , int j, vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(i==0 && j==0){
            if(arr[i][j]==1) return 0;
            else return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up = 0;
        int left = 0;
        if(arr[i][j]==0){
            up = f(i-1,j,arr,dp);
            left = f(i,j-1,arr,dp);
        }
        dp[i][j] =  up + left;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,obstacleGrid,dp);
    }
};