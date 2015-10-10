class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        vector<int> result;
        int maxfirst = 0, maxlast = 0, sum = 0, max = INT_MIN;
        int curfirst = 0, curlast = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum > max) {
                max = sum;
                curlast = i;
                maxfirst = curfirst;
                maxlast = curlast;
            }
            if (sum < 0) {
                sum = 0;
                curfirst = i + 1;
            }
        }
        result.push_back(maxfirst);
        result.push_back(maxlast);
        return result;
    }
};
