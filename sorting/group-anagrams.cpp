class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> hash;
        for (string s: strs)
        {
            string str = s;
            sort(str.begin(), str.end());
            hash[str].push_back(s);
        }
        vector<vector<string>> answer;
        for (const auto& pair : hash)
        {
            answer.push_back(pair.second);
        }
        return answer;
    }
};