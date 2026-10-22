class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();

        int max_size = 0;

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 0)
                {
                    visited[i][j] = true;
                }
                else if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    int size = 0;
                    matrix_DFS(i, j, grid, visited, size);
                    
                    max_size = max(max_size, size);
                    
                }
            }
        }

        return max_size;
    }

private:
    void matrix_DFS(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& size)
    {
        int max_rows = grid.size();
        int max_cols = grid[0].size();

        visited[r][c] = true;
        size++;

        if (r > 0)
        {
            if (grid[r - 1][c] == 1 && visited[r - 1][c] == false)
            {
                matrix_DFS(r - 1, c, grid, visited, size);
            }
        }
        if (c > 0)
        {
            if (grid[r][c - 1] == 1 && visited[r][c - 1] == false)
            {
                matrix_DFS(r, c - 1, grid, visited, size);
            }
        }
        if (r < max_rows - 1)
        {
            if (grid[r + 1][c] && visited[r + 1][c] == false)
            {
                matrix_DFS(r + 1, c, grid, visited, size);
            }
        }
        if (c < max_cols - 1)
        {
            if (grid[r][c + 1] && visited[r][c + 1] == false)
            {
                matrix_DFS(r, c + 1, grid, visited, size);
            }
        }

        return;
    }
};