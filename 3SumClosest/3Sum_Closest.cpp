class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int result = nums[0] + nums[1] + nums[2];
        int start, end;
        for (int i = 0; i < size; ++i) {
            start = i + 1;
            end = size - 1;
            while (start < end) {
                if (abs(result - target) > abs(nums[i] + nums[start] + nums[end] - target)) {
                    result = nums[i] + nums[start] + nums[end];
                }
                if (nums[i] + nums[start] + nums[end] < target) {
                    ++start;
                } else {
                    --end;
                }
            }
        }
        return result;
    }
};
