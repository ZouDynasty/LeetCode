class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right)
        {
            long long hours = 0;
            int bph = (left + right) / 2;
            for (int i = 0; i < piles.size(); i++)
            {
                hours += (piles[i] + bph - 1) / bph;
            }
            
            if (hours <= h)
            {
                right = bph - 1;
            }
            else
            {
                left = bph + 1;
            }
        }
        return left;
        
    }
};