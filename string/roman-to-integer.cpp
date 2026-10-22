#include <unordered_map>
class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> romanTable;
        romanTable['I'] = 1;
        romanTable['V'] = 5;
        romanTable['X'] = 10;
        romanTable['L'] = 50;
        romanTable['C'] = 100;
        romanTable['D'] = 500;
        romanTable['M'] = 1000;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i < s.length() - 1 && (romanTable[s[i]] < romanTable[s[i + 1]]))
            {
                sum = sum + (romanTable[s[i + 1]] - romanTable[s[i]]);
                i++;
            }
            else
            {
                sum = sum + romanTable[s[i]];
            }
        }
        return sum;
    }
};