class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        if (n == 3)
        {
            return max(nums[0], max(nums[1], nums[2]));
        }

        vector<int> dp1(n);

        // starting at index 0
        dp1[0] = nums[0];
        dp1[1] = 0;
        dp1[2] = nums[2] + nums[0];

        for(int i = 3; i < n - 1; i++)
        {
            dp1[i] = nums[i] + max(dp1[i - 2], dp1[i - 3]);
        }

        int max_1 = max(dp1[n - 2], dp1[n - 3]);

        vector<int> dp2(n);

        // starting at index 1
        dp2[0] = 0;
        dp2[1] = nums[1];
        dp2[2] = 0;
        dp2[3] = nums[3] + nums[1];

        for(int i = 4; i < n; i++)
        {
            dp2[i] = nums[i] + max(dp2[i - 2], dp2[i - 3]);
        }

        int max_2 = max(dp2[n - 1], dp2[n - 2]);

        vector<int> dp3(n);

        // starting at index 1
        dp3[0] = 0;
        dp3[1] = 0;
        dp3[2] = nums[2];
        dp3[3] = 0;

        for(int i = 4; i < n; i++)
        {
            dp3[i] = nums[i] + max(dp3[i - 2], dp3[i - 3]);
        }

        int max_3 = dp3[n - 1];

        return max(max_1, max(max_2, max_3));
    }
};