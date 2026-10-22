class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();

        int count = 0;

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '0')
                {
                    visited[i][j] = true;
                }
                else if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    count = count + 1;
                    matrix_DFS(i, j, grid, visited);
                }
            }
        }   

        return count;
    }

private:
    void matrix_DFS(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        int max_rows = grid.size();
        int max_cols = grid[0].size();

        if (visited[r][c] == true)
        {
            return;
        }
        else
        {
            visited[r][c] = true;
            if (r > 0)
            {
                if (grid[r - 1][c] == '1')
                {
                    matrix_DFS(r - 1, c, grid, visited);
                }
            }
            if (c > 0)
            {
                if (grid[r][c - 1] == '1')
                {
                    matrix_DFS(r, c - 1, grid, visited);
                }
            }
            if (r < max_rows - 1)
            {
                if (grid[r + 1][c] == '1')
                {
                    matrix_DFS(r + 1, c, grid, visited);
                }
            }
            if (c < max_cols - 1)
            {
                if (grid[r][c + 1] == '1')
                {
                    matrix_DFS(r, c + 1, grid, visited);
                }
            }
        }
    }
};