class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int index = 0;
        int max_reach = nums[index];

        if (nums.size() <= 1)
        {
            return true;
        }


        while(index <= max_reach)
        {
            if (index != 0)
            {
                max_reach = max(max_reach, index + nums[index]);
            }
            if (max_reach >= nums.size() - 1)
            {
                return true;
            }
            index++;
        } 

        return false;


    }
};