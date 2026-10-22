class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < sorted.size() - 2; i++)
        {
            if (i > 0 && sorted[i] == sorted[i - 1])
            {
                continue;
            }

            int target = -sorted[i];

            int left_index = i + 1;
            int right_index = sorted.size() - 1;

            while (left_index < right_index)
            {
                int complement = sorted[left_index] + sorted[right_index];
                if (complement < target)
                {
                    left_index++;
                }
                else if (complement > target)
                {
                    right_index--;
                }
                else
                {
                    vector<int> triplet = {sorted[i], sorted[left_index], sorted[right_index]};
                    ans.push_back(triplet);
                    while (left_index < right_index && sorted[left_index] == sorted[left_index + 1])
                    {
                        left_index++;
                    }
                    while (left_index < right_index && sorted[right_index] == sorted[right_index - 1])
                    {
                        right_index--;
                    }
                    left_index++;
                    right_index--;
                }
            }
        }
        return ans;
    }
};