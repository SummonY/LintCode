class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](const int &i, const int j) {
            return to_string(i) + to_string(j) > to_string(j) + to_string(i);
        });
        string result("");
        for (int n : num) {
            result += to_string(n);
        }
        if (result[0] == '0') {
            return "0";
        }
        return result;
    }
};
