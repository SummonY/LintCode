class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int max_inc = 0, cur_inc = 0;
        int max_dec = 0, cur_dec = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i == 0 || A[i] == A[i - 1]) {
                max_inc = max(max_inc, ++cur_inc);
                max_dec = max(max_dec, ++cur_dec);
            } else if (A[i] > A[i - 1]) {
                max_inc = max(max_inc, ++cur_inc);
                cur_dec = 1;
            } else if (A[i] < A[i - 1]) {
                max_dec = max(max_dec, ++cur_dec);
                cur_inc = 1;
            }
        }
        return max(max_inc, max_dec);
    }
};
