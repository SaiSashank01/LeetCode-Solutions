#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans(n, "None");
        int aliceCount = 0;
        int bobCount = 0;
        for (int i = 0; i < n; i++) {
            if (rain[i] == 0) {
                continue;
            }
            if (i + 1 < n && rain[i + 1] == 1 && aliceCount <= bobCount) {
                ans[i] = "Alice";
                aliceCount++;
            } else {
                ans[i] = "Bob";
                bobCount++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna