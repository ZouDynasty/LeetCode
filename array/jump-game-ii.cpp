class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int max_reach = nums[0];
        unordered_map<int, int> min_jumps;

        min_jumps[0] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int jumps_to_current = min_jumps[i];
            if (i + nums[i] < max_reach)
            {
                continue;
            }
            max_reach = i + nums[i];
            for(int j = i + 1; j <= max_reach; j++)
            {
                if (min_jumps.find(j) == min_jumps.end())
                {
                    min_jumps[j] = jumps_to_current + 1;
                }
            }
        }

        return min_jumps[nums.size() - 1];
    }
};