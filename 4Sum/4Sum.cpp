class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int> > vvec;
        int size = nums.size();
        int value, start, end;
        int i, j;
        sort(nums.begin(), nums.end());
        for (i = 0; i < size - 3; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                value = target - nums[i] - nums[j];
                start = j + 1;
                end = size - 1;
                while (start < end) {
                    if (start > j + 1 && nums[start] == nums[start - 1]) {
                        ++start;
                        continue;
                    }
                    if (nums[start] + nums[end] > value) {
                        --end;
                    } else if (nums[start] + nums[end] < value) {
                        ++start;
                    } else {
                        vector<int> ivec;
                        ivec.push_back(nums[i]);
                        ivec.push_back(nums[j]);
                        ivec.push_back(nums[start]);
                        ivec.push_back(nums[end]);
                        vvec.push_back(ivec);
                        ++start;
                        --end;
                        while (start < end && nums[start] == nums[start - 1]) {
                            ++start;
                        }
                        while (start < end && nums[end] == nums[end + 1]) {
                            --end;
                        }
                    }
                }
            }
        }
        return vvec;
    }
};
