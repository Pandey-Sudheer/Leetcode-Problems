class Solution {
    public int maxProfit(int[] prices) {
        int buyPrice = Integer.MAX_VALUE;
        int maxProfit = 0;
        for( int i=0; i<prices.length; i++)
        {
 // lets first check whether the current prices of stock is greater than previously bought stock or not if greater then it is beneficial to sell the stock there is always some profit makes 
            if( buyPrice < prices[i])
            {
                int profit = prices[i] - buyPrice;
                maxProfit = Math.max( maxProfit, profit);
            }else { //if current price is lower than the previously bought stocks then need to more buy stocks 
                buyPrice = prices[i];
            }
        }
        return maxProfit;
    }
}