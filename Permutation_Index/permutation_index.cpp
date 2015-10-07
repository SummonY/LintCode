class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        long long index = 1;
        int position = 2;
        long long factor = 1, successor = 0;
        for (int i = A.size() - 2; i >= 0; --i) {
            successor = 0;
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++successor;
                }
            }
            index += successor * factor;
            factor *= position;
            ++position;
        }
        return index;
    }
};
