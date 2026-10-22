class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> results(temperatures.size());
        stack<int> day_index;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!day_index.empty() && temperatures[i] > temperatures[day_index.top()])
            {
                results[day_index.top()] = i - day_index.top();
                day_index.pop();
            }
            day_index.push(i);
        }
        
        return results;
    }
};