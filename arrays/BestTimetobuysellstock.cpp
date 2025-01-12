//Problem statement
/*You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.

You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.

Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.

Example 1:

Input: prices = [10,1,5,6,7,1]

Output: 6
*/

//Bruteforce approach:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i+1 ; j < prices.size() ; j++){
                int diff = prices[j] - prices[i];
                if(diff > profit){
                    profit = diff;
                }
            }
        }
        return profit;
    }
};


//optimized approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; //10
        int maxPrice = 0;
        for(int i = 1; i < prices.size(); i++){
            minPrice = min(minPrice , prices[i]); //1 ,1, 1, 1, 1
            int netProfit = prices[i] - minPrice; //0, 4, 5, 6, 0
            maxPrice = max(netProfit, maxPrice) ; //1, 4, 5, 6, 6
        }
        //at end of for loop we have maxPrice
        return maxPrice;
    }
};


