class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> s;
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!s.empty() && heights[i] < heights[s.top()])
            {
                int element = s.top();
                s.pop();
                int nse = i;
                int pse = -1;
                if (!s.empty())
                {
                    pse = s.top();
                }
                int area = heights[element] * (nse - pse - 1);
                if (area > max_area)
                {
                    max_area = area;
                }
            }
            s.push(i);
        }

        while (!s.empty())
        {
            int element = s.top();
            s.pop();
            int nse = heights.size();
            int pse = -1;
            if (!s.empty())
            {
                pse = s.top();
            }
            int area = heights[element] * (nse - pse - 1);
            if (area > max_area)
            {
                max_area = area;
            }
        }
        return max_area;
    }
};