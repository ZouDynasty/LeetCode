class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> visited;

        for(int i = 0; i < nums.size(); i++)
        {
            if (visited[nums[i]] > 0)
            {
                return true;
            }
            visited[nums[i]]++;
        }

        return false;
    }
};