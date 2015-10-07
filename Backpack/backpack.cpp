class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        bool fill[m + 1];
        for (int i = 0; i <= m; ++i) {
            fill[i] = false;
        }
        fill[0] = true;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = m; j >= A[i]; --j) {
                fill[j] = fill[j] || fill[j - A[i]];
            }
        }
        for (int j = m; j >= 0; --j) {
            if (fill[j]) {
                return j;
            }
        }
        return 0;
    }
};
