class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        vector<int> listNum = nums;
        const int M = 2000, INF = 1e9;

        auto f = [&](const vector<int>& a) {
            vector<vector<int>> d(n, vector<int>(M + 1, INF));
            for (int i = 0; i < n; i++) {
                int pm = INF;
                for (int v = 1; v <= M; v++) {
                    if (i == 0) d[i][v] = abs(a[i] - v);
                    else {
                        pm = min(pm, d[i - 1][v - 1]);
                        d[i][v] = pm + abs(a[i] - v);
                    }
                }
            }
            return d;
        };

        auto L = f(listNum);
        reverse(listNum.begin(), listNum.end());
        auto R = f(listNum); 
        reverse(listNum.begin(), listNum.end());

        int best = INT_MAX;
        for (int i = 1; i < n - 1; i++)
            for (int v = 1; v <= M; v++)
                best = min(best, L[i][v] + R[n - 1 - i][v] - abs(listNum[i] - v));

        return best;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna