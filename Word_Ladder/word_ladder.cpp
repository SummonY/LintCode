class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return 1;
        }
        int n = start.size();
        if (n < 0 || start.size() != end.size()) {
            return 0;
        }
        queue<string> Q;
        Q.push(start);
        dict.erase(start);
        int length = 2, i, j;
        char last, ch;
        while (!Q.empty()) {
            int size = Q.size();
            for (i = 0; i < size; ++i) {
                string word = Q.front();
                Q.pop();
                for (j = 0; j < n; ++j) {
                    last = word[j];
                    for (ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == last) {
                            continue;
                        }
                        word[j] = ch;
                        if (word == end) {
                            return length;
                        }
                        if (dict.find(word) != dict.end()) {
                            Q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = last; 
                }
            }
            ++length;
        }
        return 0;
    }
};
