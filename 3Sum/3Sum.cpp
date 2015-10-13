class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > vvec;
        sort(nums.begin(), nums.end());
        int start, end, target;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            target = -nums[i];
            start = i + 1;
            end = nums.size() - 1;
            while (start < end) {
                if (start > i + 1 && nums[start] == nums[start - 1]) {
                    start++;
                    continue;
                }
                if (nums[start] + nums[end] > target) {
                    --end;
                } else if (nums[start] + nums[end] < target) {
                    ++start;
                } else {
                    vector<int> ivec;
                    ivec.push_back(nums[i]);
                    ivec.push_back(nums[start]);
                    ivec.push_back(nums[end]);
                    vvec.push_back(ivec);
                    ++start;
                }
            }
        }
        return vvec;
    }
};
