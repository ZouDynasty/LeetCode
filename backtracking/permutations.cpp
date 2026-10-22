class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> cur_subset;
        vector<bool> visited(n, false);
        vector<vector<int>> soln;

        backtrack(nums, soln, cur_subset, visited);

        return soln;

    }

    void backtrack(vector<int>& nums, vector<vector<int>>& soln, vector<int>& cur_subset, vector<bool>& visited)
    {
        if (cur_subset.size() == nums.size())
        {
            soln.push_back(cur_subset);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == false)
            {
                cur_subset.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, soln, cur_subset, visited);
                cur_subset.pop_back();
                visited[i] = false;
            }
        }
    }


};