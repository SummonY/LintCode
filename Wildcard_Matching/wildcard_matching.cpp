class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int spos = 0, ppos = 0;
        int slast = -1, plast = -1;
        int lens = strlen(s);
        int lenp = strlen(p);
        while (spos < lens) {
            if (ppos < lenp && (p[ppos] == s[spos] || p[ppos] == '?')) {
                ++spos;
                ++ppos;
            } else if (ppos < lenp && p[ppos] == '*') {
                ++ppos;
                slast = spos;
                plast = ppos;
            } else if (plast != -1) {
                ++slast;
                spos = slast;
                ppos = plast;
            } else {
                return false;
            }
        }
        while (ppos < lenp && p[ppos] == '*') {
            ++ppos;
        }
        return ppos == lenp;
    }
};
