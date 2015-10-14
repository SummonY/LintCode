class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        vector<string> result;
        if (words.size() == 0 || board.size() == 0) {
            return result;
        }
        int w, i, j;
        bool istrue = false, cont = true;
        for (w = 0; w < words.size(); ++w) {
            cont = true;
            for (i = 0; i < board.size(); ++i) {
                if (cont) {
                    for (j = 0; j < board[0].size(); ++j) {
                        if (board[i][j] == words[w][0]) {
                            istrue = find(board, words[w], i, j, 0);
                            if (istrue) {
                                result.push_back(words[w]);
                                cont = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
    bool find(vector<vector<char>> board, string word, int r, int c, int start) {
        if (start == word.size()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[start]) {
            return false;
        }
        board[r][c] = '#';
        bool rst = find(board, word, r - 1, c, start + 1) || find(board, word, r + 1, c, start + 1) || find(board, word, r, c - 1, start + 1) || find(board, word, r, c + 1, start + 1);
        board[r][c] = word[start];
        return rst;
    }
};

