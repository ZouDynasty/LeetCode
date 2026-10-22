#include <unordered_map>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        unordered_map<int, bool> hash;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(nums[i]) == hash.end())
            {
                nums[count] = nums[i];
                hash[nums[i]] = true;
                count++;
            }
        }
        return count;
    }
};