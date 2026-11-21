class Solution {
public:
    int minRange(int a, int b, int c) {
        int arr[] = {a, b, c};
        for (int i = 0; i < 2; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        int beforeRange = arr[2] - arr[0];
        int afterRange = arr[1];
        if (beforeRange < afterRange) {
            return beforeRange;
        } else {
            return afterRange;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna