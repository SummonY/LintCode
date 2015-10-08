class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        int n = A.size();
        const int max_num = 100;
        int upper, lower;
        int i, j, k;
        // costs[i][j] denotes the min cost of the first i elements with target j.
        vector<vector<int>> costs(2, vector<int>(max_num + 1, 0));
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= max_num; ++j) {
                upper = min(max_num, j + target);
                lower = max(1, j - target);
                costs[i % 2][j] = INT_MAX;
                for (k = lower; k <= upper; ++k) {
                    // min_cost[i][j] = abs(A[i - 1] - j) + min(min_cost[i][k]),
                    //                  for each k s.t. | k - j | <= target)
                    costs[i % 2][j] = min(costs[i % 2][j], costs[(i - 1) % 2][k]);
                }
                costs[i % 2][j] += abs(j - A[i - 1]);
            }
        }
        return *min_element(next(costs[n % 2].cbegin()), costs[n % 2].cend());
    }
};
