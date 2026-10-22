class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> soln;
        vector<int> cur_subset;

        backtrack(1, soln, cur_subset, k, n);

        return soln;
    }
    void backtrack(int start, vector<vector<int>>& soln, vector<int>& cur_subset, int remaining_nums, int target)
    {
        if (remaining_nums == 0)
        {
            if (target == 0)
            {
                soln.push_back(cur_subset);
                return;
            }
            else
            {
                return;
            }
        }
        if (start > 9)
        {
            return;
        }
        cur_subset.push_back(start);
        backtrack(start + 1, soln, cur_subset, remaining_nums - 1, target - start);
        cur_subset.pop_back();
        backtrack(start + 1, soln, cur_subset, remaining_nums, target);
    }
};