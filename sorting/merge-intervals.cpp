class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> soln;

        sort(intervals.begin(), intervals.end());

        soln.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (soln.back()[1] >= intervals[i][0])
            {
                soln.back()[1] = max(soln.back()[1], intervals[i][1]);
            }
            else
            {
                soln.push_back(intervals[i]);
            }
        }
        return soln;    
    }
};