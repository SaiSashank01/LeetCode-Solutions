
class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (n == 1) {
                count++;
                continue;
            }
            if (i == 0) {
                if (nums[0] >= nums[1]) {
                    count++;
                }
            } else if (i == n - 1) {
                if (nums[n - 1] >= nums[n - 2]) {
                    count++;
                }
            } else {
                if (2 * nums[i] >= nums[i - 1] + nums[i + 1]) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna