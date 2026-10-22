class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> mySet;
        for (int num: nums)
        {
            mySet.insert(num);
        }
        int curstreak = 1;
        int maxstreak = 0;
        for (const auto& element : mySet) 
        {
            if (mySet.find(element + 1) != mySet.end())
            {
                curstreak++;
            }
            else
            {
                maxstreak = max(curstreak, maxstreak);
                curstreak = 1;
            }
        }
        return maxstreak;
    }
};