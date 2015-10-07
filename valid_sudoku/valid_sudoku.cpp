class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        bool isVisited[9];
        int i, j, k;
        for (i = 0; i < 9; ++i) {
            for (j = 0; j < 9; ++j) {
                isVisited[j] = false;
            }
            for (j = 0; j < 9; ++j) {
                if (!process(isVisited, board[i][j])) {
                    return false;
                }
            }
        }
        
        for (j = 0; j < 9; ++j) {
            for (i = 0; i < 9; ++i) {
                isVisited[i] = false;
            }
            for (i = 0; i < 9; ++i) {
                if (!process(isVisited, board[i][j])) {
                    return false;
                }
            }
        }
        
        for (i = 0; i < 9; i += 3) {
            for (j = 0; j < 9; j += 3) {
                for (k = 0; k < 9; ++k) {
                    isVisited[k] = false;
                }
                for (k = 0; k < 9; ++k) {
                    if (!process(isVisited, board[i + k / 3][j + k % 3])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool process(bool isVisited[], char digit) {
        if (digit == '.') {
            return true;
        }
        int num = digit - '0';
        if (num < 1 || num > 9 || isVisited[num - 1]) {
            return false;
        }
        isVisited[num - 1] = true;
        return true;
    }
};
