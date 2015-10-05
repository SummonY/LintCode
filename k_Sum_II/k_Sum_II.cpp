class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        vector<vector<int> > vvec;
        vector<int> curr;
        kSumHelper(vvec, A, k, target, 0, curr);
        return vvec;
    }
    void kSumHelper(vector<vector<int> > &vvec, vector<int> A, int k, int target, int start, vector<int> &curr) {
        if (k < 0 || target < 0) {
            return ;
        }
        if (k == 0 && target == 0) {
            vvec.push_back(curr);
            return ;
        }
        for (int i = start; i <= A.size() - k; ++i) {
            curr.push_back(A[i]);
            kSumHelper(vvec, A, k - 1, target - A[i], i + 1, curr);
            curr.pop_back();
        }
    }
};
