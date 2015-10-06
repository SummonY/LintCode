class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int sum;
    int totalNQueens(int n) {
        sum = 0;
        int ques[n];
        placeQueens(ques, n, 0);
        return sum;
    }
    void placeQueens(int ques[], int cols, int row) {
        if (row == cols) {
            ++sum;
            return ;
        }
        for (int col = 0; col < cols; ++col) {
            if (isValid(ques, row, col)) {
                ques[row] = col;
                placeQueens(ques, cols, row + 1);
            }
        }
    }
    bool isValid(int ques[], int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (ques[i] == col) {
                return false;
            }
            if ((row - i) == abs(col - ques[i])) {
                return false;
            }
        }
        return true;
    }
};
