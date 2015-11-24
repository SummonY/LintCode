class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        int f[n + 1];
        f[1] = 0;
        f[2] = 1;
        
        for (int i = 3; i <= n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};
