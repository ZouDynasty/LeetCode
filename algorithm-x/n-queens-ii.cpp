class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> covered(n, vector<int>(n, 0));
            backtrack(1, n, 0, i, covered, sum);
        }
    
        return sum;
    }
    void backtrack(int num_queens, int n, int x, int y, vector<vector<int>>& covered, int& sum)
    {

        // returning if valid orientation found
        if (num_queens == n)
        {
            sum++;
            return;
        }

        for(int i = 0; i < n; i++)
        {
            // marking row/column as visited
            covered[x][i]++;
            covered[i][y]++;

            // marking diagonals as visited
            if (x + i < n)
            {
                if (y + i < n)
                {
                    covered[x + i][y + i]++;
                }
                if (y - i >= 0)
                {
                    covered[x + i][y - i]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (x < n - 1 && covered[x + 1][i] == 0)
            {
                backtrack(num_queens + 1, n, x + 1, i, covered, sum);
            }
        }

        for(int i = 0; i < n; i++)
        {
            // marking row/column as visited
            covered[x][i]--;
            covered[i][y]--;

            // marking diagonals as visited
            if (x + i < n)
            {
                if (y + i < n)
                {
                    covered[x + i][y + i]--;
                }
                if (y - i >= 0)
                {
                    covered[x + i][y - i]--;
                }
            }
        }

        return;
    }
};