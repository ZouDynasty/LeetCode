class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();
        if (n % groupSize != 0)
        {
            return false;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++)
        {
            if (hand[i] >= 0)
            {
                if (!validStreak(hand, groupSize, i, n))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool validStreak(vector<int>& hand, int groupSize, int start, int n)
    {
        int next = hand[start] + 1;
        hand[start] = -1;
        int count = 1;
        start += 1;

        while (start < n && count < groupSize)
        {
            if (hand[start] == next)
            {
                next = hand[start] + 1;
                hand[start] = -1;
                count++;
            }
            start++;
        }
        return count == groupSize;
    }
};