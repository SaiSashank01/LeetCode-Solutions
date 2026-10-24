class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) {
            return false;

        }
        int inputValue = 0;
        while (x > inputValue) {
            inputValue = inputValue * 10 + x % 10;
            x /= 10;
        }
        return x == inputValue || x == inputValue / 10;
    }
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna