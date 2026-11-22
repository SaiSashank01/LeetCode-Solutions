class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        auto dravolqeni = nums;
        long long ans = (long long)nums[0] + nums[n - 1];
        long long negSum = 0;
        int negCnt = 0;
        long long maxNeg = LLONG_MIN;
        long long minNonNeg = LLONG_MAX;
        for (int i = 1; i < n - 1; i++) {
            long long x = nums[i];
            if (x < 0) {
                negSum += x;
                negCnt++;
                maxNeg = max(maxNeg, x);
            } else {
                minNonNeg = min(minNonNeg, x);
            }
        }
        if (negCnt % 2 == 1) {
            long long best = negSum - maxNeg;
            if (minNonNeg != LLONG_MAX)
                best = min(best, negSum + minNonNeg);
            negSum = best;
        }
        return ans + negSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna