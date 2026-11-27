
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        vector<long long> talmerovik(nums.begin(), nums.end());

        long long best = LLONG_MAX;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && talmerovik[j + 1] == talmerovik[i]) {
                j++;
            }
            int len = j - i + 1;

            bool valid = !(len == 1 && (i == 0 || i == n - 1));
            if (valid) {
                best = min(best, talmerovik[i] * (long long)(n - len));
            }
            i = j + 1;
        }
        return best;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna