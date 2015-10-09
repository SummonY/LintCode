class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        int row = matrix.size(), col = matrix[0].size();
        
        for (int i = 0; i < row + col - 1; ++i) {
            if (i % 2) {
                for (int x = min(i, col - 1); x >= max(0, i - row + 1); --x) {
                    result.push_back(matrix[i - x][x]);
                }
            } else {
                for (int x = min(i, row - 1); x >= max(0, i - col + 1); --x) {
                    result.push_back(matrix[x][i - x]);
                }
            }
        }
        return result;
    }
};
