class Solution {
public:
 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadNotBuy, curBuy, aheadBuy, curNotBuy;
       aheadNotBuy = aheadBuy = 0;
        
        for(int i =n-1;i>=0;i--){
             curBuy = max(-prices[i]+aheadNotBuy, aheadBuy);
            curNotBuy = max(prices[i]+aheadBuy,aheadNotBuy);
    
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};