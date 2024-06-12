class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
        vector<long>cur(2,0),ahead(2,0);

ahead[0] = ahead[1] = 0;
    for(int i =n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){

    long maxprofit = 0;

    if(buy){   
        maxprofit = max(-prices[i]+ahead[0] - fee, cur[1]);

    }
    else {
        maxprofit = max(prices[i]+ ahead[1], ahead[0]);
    }
    cur[buy] =  maxprofit;
        }
        ahead = cur;

    }
    return cur[1];  
    }
};