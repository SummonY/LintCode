class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int i = 0, j = letters.size() - 1;
        char ch;
        while (i <= j) {
            if (islower(letters[i])) {
                ++i;
            } else if (isupper(letters[j])) {
                --j;
            } else {
                ch = letters[i];
                letters[i] = letters[j];
                letters[j] = ch;
                ++i;
                --j;
            }
        }
    }
};
