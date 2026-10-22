class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int lo = 0, hi = intervals.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (intervals[mid][0] < newInterval[0])
                lo = mid + 1;
            else
                hi = mid;
        }
        intervals.insert(intervals.begin() + lo, newInterval);

        vector<vector<int>> soln;
        soln.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (soln.back()[1] >= intervals[i][0])
                soln.back()[1] = max(soln.back()[1], intervals[i][1]);
            else
                soln.push_back(intervals[i]);
        }
        return soln;
    }
};
