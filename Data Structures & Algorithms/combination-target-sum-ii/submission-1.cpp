class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;

    void backtrack(int start,int remaining,vector<int>& candidates) {
        if (remaining == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remaining) {
                break;
            }

            // Same value as previous, but previous duplicate
            // was not chosen in the current path.
            // Therefore, this would create a duplicate branch.
            if (
                i > 0 &&
                candidates[i] == candidates[i - 1] &&
                !used[i - 1]
            ) {
                continue;
            }

            if (used[i]) {
                continue;
            }

            used[i] = true;
            path.push_back(candidates[i]);

            backtrack(
                i + 1,
                remaining - candidates[i],
                candidates
            );

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {
        sort(candidates.begin(), candidates.end());

        used.assign(candidates.size(), false);

        backtrack(0, target, candidates);

        return ans;
    }
};