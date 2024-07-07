class Solution {
public:
 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(2,0),cur(2,0);        
        ahead[0] = ahead[1] = 0;
        
        for(int i =n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
            if(buy){
             profit = max(-prices[i]+ahead[0], ahead[1]);
        }
        else{
            profit = max(prices[i]+ahead[1],ahead[0]);
            
        }
               cur[buy] = profit;
         
            }
            ahead = cur;
        }
        return ahead[1];
    }
};