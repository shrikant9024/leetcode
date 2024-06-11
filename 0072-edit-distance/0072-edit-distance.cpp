class Solution {
public:
    int f(int i, int j , string s, string t,vector<vector<int>>&dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        //match
        if(s[i]==t[j]) return dp[i][j]= f(i-1,j-1,s,t,dp);
        
        //not match
         //case1-insert f(i,j-1,s,t)
        //case 2 replace - f(i-1,j-1,s,t)
        //case 3 delete - f(i-1,j,s,t)
        
       return  dp[i][j] =  1 + min(f(i,j-1,s,t,dp),min(f(i-1,j-1,s,t,dp),f(i-1,j,s,t,dp)));
        

    }
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m-1,n-1,word1,word2,dp);
    }
};