class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if (A.size() == 0 || B.size() == 0) {
            return 0;
        }
        int sa = A.size(), sb = B.size();
        int F[sa + 1][sb + 1];
        int i, j;
        for (i = 0; i <= sa; ++i) {
            F[i][0] = 0;
        }
        for (j = 0; j <= sb; ++j) {
            F[0][j] = 0;
        }
        for (i = 1; i <= sa; ++i) {
            for (j = 1; j <= sb; ++j) {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
                if (A[i - 1] == B[j - 1]) {
                    F[i][j] = F[i - 1][j - 1] + 1;
                }
            }
        }
        return F[sa][sb];
    }
};
