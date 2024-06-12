class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<vector<long>>dp(n+1,vector<long>(2,0));

    dp[n][0] = dp[n][1] = 0;
    for(int i =n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){

    long maxprofit = 0;

    if(buy){   
        maxprofit = max(-prices[i]+dp[i+1][0], dp[i+1][1]);

    }
    else {
        maxprofit = max(prices[i]+ dp[i+1][1], dp[i+1][0]);
    }
    dp[i][buy] =  maxprofit;
        }

    }
    return dp[0][1];  
    }
};