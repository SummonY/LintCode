class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > vvec;
        vector<int> cur;
        combineHelper(vvec, n, k, 1, cur);
        return vvec;
    }
    void combineHelper(vector<vector<int> > &vvec, int n, int k, int start, vector<int> &cur) {
        if (cur.size() == k) {
            vector<int> ivec(cur);
            vvec.push_back(ivec);
        }
        for (int i = start; i <= n; ++i) {
            cur.push_back(i);
            combineHelper(vvec, n, k, i + 1, cur);
            cur.pop_back();
        }
    }
};
