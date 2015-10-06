class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i, index = -1;
        int sum = 0, total = 0;
        for (i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                index = i;
                sum = 0;
            }
        }
        return total >= 0 ? index + 1 : -1;
    }
};
