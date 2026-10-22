class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> soln;
        vector<int> subset;


        backtrack(0, target, candidates, soln, subset);

        return soln;
        
    }

    void backtrack(int index, int target, vector<int>& nums, vector<vector<int>>& soln, vector<int>& subset)
    {
        if (target == 0)
        {
            soln.push_back(subset);
            return;
        }
        if (index == nums.size() || target < 0)
        {
            return;
        }

        subset.push_back(nums[index]);
        backtrack(index, target - nums[index], nums, soln, subset);
        subset.pop_back();

        backtrack(index + 1, target, nums, soln, subset);
    }
};