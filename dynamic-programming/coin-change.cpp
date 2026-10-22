#include <climits>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
        }

        for (int c = 0; c < coins.size(); c++)
        {
            for (int i = coins[c]; i <= amount; i++)
            {
                if (dp[i - coins[c]] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coins[c]] + 1);
                }
            }
        }

        if (dp[amount] == INT_MAX)
        {
            return -1;
        }
        return dp[amount];
    }
};