class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int r = board.size();
        int c = board[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for (int i = 0; i < c; i++)
        {
            if (board[0][i] == 'O' && visited[0][i] == false)
            {
                dfs(board, visited, 0, i);
            }
            if (board[r - 1][i] == 'O' && visited[r - 1][i] == false)
            {
                dfs(board, visited, r - 1, i);
            }
        }

        for (int i = 0; i < r; i++)
        {
            if (board[i][0] == 'O' && visited[i][0] == false)
            {
                dfs(board, visited, i, 0);
            }
            if (board[i][c - 1] == 'O' && visited[i][c - 1] == false)
            {
                dfs(board, visited, i, c - 1);
            }
        }

        for (int i = 1; i < r - 1; i++)
        {
            for (int j = 1; j < c - 1; j++)
            {
                if (board[i][j] == 'O' && visited[i][j] == false)
                {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col)
    {
        if (visited[row][col] == true)
        {
            return;
        }
        visited[row][col] = true;
        if (row > 0 && board[row - 1][col] == 'O' && visited[row - 1][col] == false)
        {
            dfs(board, visited, row - 1, col);
        }
        if (col > 0 && board[row][col - 1] == 'O' && visited[row][col - 1] == false)
        {
            dfs(board, visited, row, col - 1);
        }
        if (row < board.size() - 1 && board[row + 1][col] == 'O' && visited[row + 1][col] == false)
        {
            dfs(board, visited, row + 1, col);
        }
        if (col < board[0].size() - 1 && board[row][col + 1] == 'O' && visited[row][col + 1] == false)
        {
            dfs(board, visited, row, col + 1);
        }

    }
};