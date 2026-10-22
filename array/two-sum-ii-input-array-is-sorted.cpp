class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int start = 0;
        int end = numbers.size() - 1;
        
        int sum = numbers[start] + numbers[end];
        while (sum != target)
        {
            if (sum < target)
            {
                start++;
            }

            if (sum > target)
            {
                end--;
            }
            sum = numbers[start] + numbers[end];
        }
        return {start + 1, end + 1};

    }
};