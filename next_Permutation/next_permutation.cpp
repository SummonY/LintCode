class Solution1 {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int k = -1, l;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                k = i;
            }
        }
        if (k >= 0) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }
        reverse(nums.begin() + k + 1, nums.end());
        return nums;
    }
};
