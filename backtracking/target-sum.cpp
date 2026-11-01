class Solution {
public:
    vector<unordered_map<int, int>> memo;

    int findTargetSumWays(vector<int>& nums, int target) {
        memo.resize(nums.size());
        return recurse(0, nums, 0, target);
    }

    int recurse(int current, vector<int>& nums, int sum, int target) {
        if (current == nums.size()) {
            return sum == target ? 1 : 0;
        }

        if (memo[current].count(sum)) {
            return memo[current][sum];
        }

        int add = recurse(current + 1, nums, sum + nums[current], target);
        int subtract = recurse(current + 1, nums, sum - nums[current], target);

        return memo[current][sum] = add + subtract;
    }
};