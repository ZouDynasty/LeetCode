#include <vector> 
#include <unordered_map>
#include <algorithm>
#include <queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }
        vector<pair<int, int>> storage;
        for (const auto& pair: hash)
        {
            storage.push_back(pair);
        }
        sort(storage.begin(), storage.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;});
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(storage[i].first);
        }
        return ans;
    }
};
