class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right)
        {
            int middle = (left + right) / 2;
            
            if (target < matrix[middle / cols][middle % cols])
            {
                right = middle - 1;
            }
            else if (target > matrix[middle / cols][middle % cols])
            {
                left = middle + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};