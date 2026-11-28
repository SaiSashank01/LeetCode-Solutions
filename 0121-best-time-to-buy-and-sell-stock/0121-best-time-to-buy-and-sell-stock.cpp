class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices)
        {
            if(price < minPrice)
            {
                minPrice = price;
            }else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }
        return maxProfit;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna