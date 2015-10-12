class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) {
            return true;
        }
        if (board.size() == 0) {
            return false;
        }
        bool istrue;
        int w, i, j;
        int rows = board.size(), cols = board[0].size();
        for (i = 0; i < rows; ++i) {
            for (j = 0; j < cols; ++j) {
                if (word[0] == board[i][j]) {
                    istrue = find(word, i, j, board, 0);
                    if (istrue) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool find(string word, int r, int c, vector<vector<char> > board, int start) {
        if (start == word.size()) {
            return true;
        }
        int rows = board.size(), cols = board[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[start]) {
            return false;
        }
        board[r][c] = '#';
        bool result = find(word, r - 1, c, board, start + 1) || find(word, r, c - 1, board, start + 1) || find(word, r + 1, c, board, start + 1) || find(word, r, c + 1, board, start + 1);
        board[r][c] = word[start];
        return result;
    }
};
