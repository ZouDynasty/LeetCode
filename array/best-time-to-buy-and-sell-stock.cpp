class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int left = 0;
        int right = 1;

        int max_profit = 0;

        while (right < prices.size())
        {
            int profit = prices[right] - prices[left];

            if (profit > max_profit)
            {
                max_profit = profit;
            }

            if (prices[right] < prices[left])
            {
                left = right;
            }
            right++;
        }

        return max_profit;
    }
};