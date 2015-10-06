class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > vvec;
        int que[n];
        for (int i = 0; i < n; ++i) {
            que[i] = 0;
        }
        placeQueens(vvec, n, 0, que);
        return vvec;
    }
    void placeQueens(vector<vector<string> > &vvec, int cols, int row, int que[]) {
        if (row == cols) {
            vector<string> svec;
            int i, r;
            for (r = 0; r < cols; ++r) {
                string str("");
                for (i = 0; i < que[r]; ++i) {
                    str += '.';
                }
                str += 'Q';
                for (i = row - 1; i > que[r]; --i) {
                    str += '.';
                }
                svec.push_back(str);
            }
            vvec.push_back(svec);
            return ;
        }
        for (int col = 0; col < cols; ++col) {
            if (isValid(que, row, col)) {
                que[row] = col;
                placeQueens(vvec, cols, row + 1, que);
            }
        }
    }
    bool isValid(int que[], int row, int col) {
        for (int r = 0; r < row; ++r) {
            if (que[r] == col) {
                return false;
            }
            if ((row - r) == abs(que[r] - col)) {
                return false;
            }
        }
        return true;
    }
};
