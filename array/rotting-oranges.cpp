class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();

        int total_oranges = 0;

        vector<pair<int, int>> rotten;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    total_oranges++;
                }
                if (grid[i][j] == 2)
                {
                    total_oranges++;
                    rotten.push_back({i, j});
                }
            }
        }
    
        int days = 0;
        int previous_rotten = rotten.size();

        while (rotten.size() < total_oranges)
        {
            int current_rotten_size = rotten.size();
            for (int i = 0; i < current_rotten_size; i++)
            {
                int rotten_r = rotten[i].first;
                int rotten_c = rotten[i].second;

                if (rotten_r > 0 && grid[rotten_r - 1][rotten_c] == 1)
                {
                    grid[rotten_r - 1][rotten_c] = 2;
                    rotten.push_back({rotten_r - 1, rotten_c});
                }
                if (rotten_r < r - 1 && grid[rotten_r + 1][rotten_c] == 1)
                {
                    grid[rotten_r + 1][rotten_c] = 2;
                    rotten.push_back({rotten_r + 1, rotten_c});
                }
                if (rotten_c > 0 && grid[rotten_r][rotten_c - 1] == 1)
                {
                    grid[rotten_r][rotten_c - 1] = 2;
                    rotten.push_back({rotten_r, rotten_c - 1});
                }
                if (rotten_c < c - 1 && grid[rotten_r][rotten_c + 1] == 1)
                {
                    grid[rotten_r][rotten_c + 1] = 2;
                    rotten.push_back({rotten_r, rotten_c + 1});
                }
            }
            days++;
            if (previous_rotten == rotten.size())
            {
                return -1;
            }
            previous_rotten = rotten.size();
        }

        return days;
    }

};