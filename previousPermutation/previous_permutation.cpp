class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int k = -1, l;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                k = i;
            }
        }
        if (k >= 0) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] < nums[k]) {
                    l = j;
                }
            }
            swap(nums[k], nums[l]);
        }
        reverse(nums.begin() + k + 1, nums.end());
        return nums;
    }
};

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        prev_permutation(nums.begin(), nums.end());
        return nums;
    }
};
