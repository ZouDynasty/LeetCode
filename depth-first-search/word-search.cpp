class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>> visited(r, vector<bool>(c, false));
                    bool valid = dfs(0, i, j, board, visited, word);
                    if (valid)
                    {
                        return valid;
                    }
                }
            }
        }

        return false;
    }
    bool dfs(int index, int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited, string& word)
    {
        if (index == word.size() - 1)
        {
            return true;
        }
        visited[x][y] = true;
        if (x > 0 && visited[x - 1][y] == false && board[x - 1][y] == word[index + 1])
        {   
            if (dfs(index + 1, x - 1, y, board, visited, word))
            {
                return true;
            }
        }  
        if (y > 0 && visited[x][y - 1] == false && board[x][y - 1] == word[index + 1])
        {
            if (dfs(index + 1, x, y - 1, board, visited, word))
            {
                return true;
            }
        }
        if (x < board.size() - 1 && visited[x + 1][y] == false && board[x + 1][y] == word[index + 1])
        {
            if (dfs(index + 1, x + 1, y, board, visited, word))
            {
                return true;
            }
        }
        if (y < board[0].size() - 1 && visited[x][y + 1] == false && board[x][y + 1] == word[index + 1])
        {
            if (dfs(index + 1, x, y + 1, board, visited, word))
            {
                return true;
            }
        }

        visited[x][y] = false;
        return false;
    }
};