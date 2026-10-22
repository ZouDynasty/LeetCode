class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        // dfs to find reachable nodes from each coast. Then take union of the sets. 
        // manual union
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>> soln;

        if (r < 2 or c < 2)
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    soln.push_back({i, j});
                }
            }
            return soln;
        }

        vector<vector<bool>> pacific_reachable(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic_reachable(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++)
        {
            if (pacific_reachable[i][0] == false)
            {
                dfs(i, 0, heights, pacific_reachable);
            }
            if (atlantic_reachable[i][c - 1] == false)
            {
                dfs(i, c - 1, heights, atlantic_reachable);
            }
        }

        for (int i = 0; i < c; i++)
        {
            if (pacific_reachable[0][i] == false)
            {
                dfs(0, i, heights, pacific_reachable);
            }
            if (atlantic_reachable[r - 1][i] == false)
            {
                dfs(r - 1, i, heights, atlantic_reachable);
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (pacific_reachable[i][j] == true && atlantic_reachable[i][j] == true)
                {
                    soln.push_back({i, j});
                }
            }
        }   
        return soln;
    }
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& reachable)
    {
        int r = heights.size();
        int c = heights[0].size();

        int cur_height = heights[i][j];

        if (reachable[i][j] == true)
        {
            return;
        }
        else
        {
            reachable[i][j] = true;

            if (i > 0 && heights[i - 1][j] >= cur_height)
            {
                dfs(i - 1, j, heights, reachable);
            }
            if (j > 0 && heights[i][j - 1] >= cur_height)
            {
                dfs(i, j - 1, heights, reachable);
            }
            if (i < r - 1 && heights[i + 1][j] >= cur_height)
            {
                dfs(i + 1, j, heights, reachable);
            }
            if (j < c - 1 && heights[i][j + 1] >= cur_height)
            {
                dfs(i, j + 1, heights, reachable);
            }
        }
    }
};