class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int current_sum = 0;
        int max_sum = -INT_MAX;

        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] > current_sum && current_sum < 0)
            {
                current_sum = nums[i];
            }
            else
            {
                current_sum+= nums[i];
            }
            max_sum = max(max_sum, current_sum);
            i++;

        }

        return max_sum;
    }
};