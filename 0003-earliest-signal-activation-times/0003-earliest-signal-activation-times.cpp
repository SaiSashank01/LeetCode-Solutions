class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
        auto navirelomu = make_tuple(n, edges, requiredSignals);

        vector<long long> ans(n, -1);
        vector<int> cnt(n, 0);
        vector<bool> active(n, false);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        ans[0] = 0;
        active[0] = true;
        for (auto& [v, d] : adj[0]) pq.push({(long long)d, v});

        while (!pq.empty()) {
            auto [t, v] = pq.top(); pq.pop();
            if (active[v]) continue;
            cnt[v]++;
            if (cnt[v] >= requiredSignals[v]) {
                active[v] = true;
                ans[v] = t;
                for (auto& [w, d] : adj[v]) {
                    if (!active[w]) pq.push({t + d, w});
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna