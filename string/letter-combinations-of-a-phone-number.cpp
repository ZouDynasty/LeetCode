class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> combos;
        string current = "";

        backtrack(digits, combos, current, 0);

        return combos;
    }
    void backtrack(string& digits, vector<string>& combos, string& cur, int index)
    {
        if (index == digits.size())
        {
            combos.push_back(cur);
            return;
        }
        if (digits[index] == '2')
        {
            cur.append("a");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("b");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("c");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
        if (digits[index] == '3')
        {
            cur.append("d");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("e");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("f");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
        if (digits[index] == '4')
        {
            cur.append("g");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("h");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("i");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
        if (digits[index] == '5')
        {
            cur.append("j");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("k");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("l");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
        if (digits[index] == '6')
        {
            cur.append("m");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("n");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("o");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
        if (digits[index] == '7')
        {
            cur.append("p");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("q");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("r");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("s");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
        if (digits[index] == '8')
        {
            cur.append("t");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("u");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("v");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
        if (digits[index] == '9')
        {
            cur.append("w");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("x");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("y");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
            cur.append("z");
            backtrack(digits, combos, cur, index + 1);
            cur.pop_back();
        }
    }
};