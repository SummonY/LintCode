class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        long long sum = 0;
        for (auto c : key) {
            sum = sum * 33L % HASH_SIZE;
            sum = (sum + c % HASH_SIZE) % HASH_SIZE;
        }
        return static_cast<int>(sum);
    }
};
