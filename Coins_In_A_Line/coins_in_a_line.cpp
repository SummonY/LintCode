class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        if (n % 3 == 0) {
            return false;
        } else {
            return true;
        }
    }
};
