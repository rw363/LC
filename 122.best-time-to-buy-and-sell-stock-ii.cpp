/*

 * [122] Best Time to Buy and Sell Stock II

 *

 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

 *

 * algorithms

 * Easy (47.77%)

 * Total Accepted:    185.8K

 * Total Submissions: 389.1K

 * Testcase Example:  '[]'

 *

 * Say you have an array for which the ith element is the price of a given

 * stock on day i.

 * 

 * Design an algorithm to find the maximum profit. You may complete as many

 * transactions as you like (ie, buy one and sell one share of the stock

 * multiple times). However, you may not engage in multiple transactions at the

 * same time (ie, you must sell the stock before you buy again).

 */
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int buy = INT_MIN;
         int sell = 0;
         for (auto p:prices)
         {
              buy = max(buy, sell - p);
              sell = max(sell, buy + p);
         }
         return sell;
    }
};

