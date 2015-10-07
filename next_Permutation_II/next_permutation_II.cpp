class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        int k = -1, l;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                k = i;
            }
        }
        if (k >= 0) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] > nums[k]) {
                    l = j;
                }
            }
            swap(nums[k], nums[l]);
        }
        sort(nums.begin() + k + 1, nums.end());
    }
};
