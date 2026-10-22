class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> soln;

        for (int i = 0; i < n; i++)
        {
            vector<string> cur_soln(n, string(n, '.'));
            vector<vector<int>> covered(n, vector<int>(n, 0));
            backtrack(1, n, 0, i, covered, cur_soln, soln);
        }
    
        return soln;
    }
    void backtrack(int num_queens, int n, int x, int y, vector<vector<int>>& covered, vector<string>& cur_soln, vector<vector<string>>& soln)
    {
        // editing current soln
        cur_soln[x][y] = 'Q';

        // returning if valid orientation found
        if (num_queens == n)
        {
            soln.push_back(cur_soln);
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
                backtrack(num_queens + 1, n, x + 1, i, covered, cur_soln, soln);
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
        cur_soln[x][y] = '.';

        return;
    }
};