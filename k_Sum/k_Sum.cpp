class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        int n = A.size();
        vector<vector<vector<int>>> table(n + 1, vector<vector<int>>(k + 1, vector<int> (target + 1, 0)));
        for (int i = 0; i < n + 1; ++i) {
            table[i][0][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k && j <= i; ++j) {
                for (int t = 1; t <= target; ++t) {
                    table[i][j][t] = 0;
                    if (t >= A[i - 1]) {
                        table[i][j][t] = table[i - 1][j - 1][t - A[i - 1]];
                    }
                    table[i][j][t] += table[i - 1][j][t];
                }
            }
        }
        return table[n][k][target];
    }
};
