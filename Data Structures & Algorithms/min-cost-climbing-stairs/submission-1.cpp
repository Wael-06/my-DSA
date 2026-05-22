class Solution {
public:
    vector<int> cache;
    int minCostClimbingStairs(vector<int>& cost) {
        cache.assign(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int idx) {
        if(idx >= cost.size()) {
            return 0;
        }
        if(cache[idx] != -1)   return cache[idx];
        return cache[idx] = cost[idx] + min(dfs(cost, idx+1), dfs(cost, idx+2));
    }
};
