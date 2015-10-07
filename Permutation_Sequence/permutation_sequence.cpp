class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        vector<int> nums;
        int total = 1, group, idx;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            total *= i;
        }
        group = total;
        stringstream output;
        while (n > 0) {
            group /= n;
            idx = (k - 1) / group;
            output << nums[idx];
            nums.erase(nums.begin() + idx);
            k = (k - 1) % group + 1;
            --n;
        }
        return output.str();
    }
};
