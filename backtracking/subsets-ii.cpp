class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> cur_subset;
        vector<vector<int>> soln;

        backtrack(0, nums, cur_subset, soln);

        return soln;    
    }

    void backtrack(int index, vector<int>& nums, vector<int>& cur_subset, vector<vector<int>>& soln)
    {
        if (index == nums.size())
        {
            soln.push_back(cur_subset);
            return;
        }
        cur_subset.push_back(nums[index]);
        backtrack(index + 1, nums, cur_subset, soln);
        cur_subset.pop_back();

        int next = index + 1;

        while (next < nums.size() && nums[next] == nums[index])
        {
            next++;
        }

        backtrack(next, nums, cur_subset, soln);
    }
};