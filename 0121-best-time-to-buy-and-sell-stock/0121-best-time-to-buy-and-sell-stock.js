/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    
    let maxprofit = 0;
    let mini = 1e9;
    
    for(let i =0;i<prices.length;i++){
        mini = Math.min(mini,prices[i]);
        maxprofit = Math.max(maxprofit, prices[i]-mini);
    }
    return maxprofit;
};