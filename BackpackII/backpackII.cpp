class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        int maxv = 0;
        // table[i][j] denotes max_value of using the first elements to fulfill size j.
        vector<vector<int>> table(2, vector<int>(m + 1, INT_MIN));
        table[0][0] = 0;
        for (int i = 1; i <= A.size(); ++i) {
            table[i % 2][0] = 0;
            for (int j = 1; j <= m; ++j) {
                table[i % 2][j] = table[(i - 1) % 2][j];
                if (j >= A[i - 1] && table[(i - 1) % 2][j - A[i - 1]] >= 0) {
                    table[i % 2][j] = max(table[i % 2][j], table[(i - 1) % 2][j - A[i - 1]] + V[i - 1]);
                }
                if (table[i % 2][j] >= 0) {
                    maxv = max(maxv, table[i % 2][j]);
                }
            }
        }
        return maxv;
    }
};
