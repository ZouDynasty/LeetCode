class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int col = text1.size();
        int row = text2.size();

        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        for (int j = 1; j < row + 1; j++)
        {
            for (int i = 1; i < col + 1; i++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[j][i] = dp[j - 1][i - 1] + 1;
                }
                else
                {
                    dp[j][i] = max(dp[j][i - 1], dp[j - 1][i]);
                }
            }
        }

        return dp[row][col];
        
    }
};