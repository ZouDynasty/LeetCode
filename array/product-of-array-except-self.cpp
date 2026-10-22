class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
       vector<int> left;
       int leftP = 1;
       for (int i = 0; i < nums.size(); i++)
       {
        left.push_back(leftP);
        leftP = leftP * nums[i];
       }
       int rightP = 1;
       for (int i = nums.size() - 1; i >= 0; i--)
       {
        left[i] = left[i] * rightP;
        rightP = rightP * nums[i];
       }
       return left;

    }
};