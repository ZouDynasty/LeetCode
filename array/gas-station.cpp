class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int sum = 0;
        int start = 0;
        int tank = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            int net = gas[i] - cost[i];
            sum = sum + net;

            tank = tank + net;

            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }

        if (sum < 0)
        {
            return -1;
        }
        return start;
    }

};