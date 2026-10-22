class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int left = 0;
        int right = 0;
        int max_streak = 0;
        int max_count = 0;
        unordered_map<char, int> counts;

        while (right < s.length())
        {
            counts[s[right]]++;
            max_count = max(max_count, counts[s[right]]);
            right++;
            while (right - left - max_count > k)
            {
                counts[s[left]]--;
                left++;
            }
            max_streak = max(max_streak, right - left);
        }

        return max_streak;
        
    }
};