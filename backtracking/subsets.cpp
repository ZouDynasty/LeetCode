class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> soln;
        vector<int> subset;

        backtrack(nums, 0, soln, subset);

        return soln; 
        
    }
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& soln, vector<int>& subset)
    {
        if (index == nums.size())
        {
            soln.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums, index + 1, soln, subset);
        subset.pop_back();

        backtrack(nums, index + 1, soln, subset);

    }
};