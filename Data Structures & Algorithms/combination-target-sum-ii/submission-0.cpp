class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int start,int remaining,vector<int>& candidates){
        if (remaining == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicate choices at the same recursion level.
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Since candidates is sorted, all later values
            // will also be too large.
            if (candidates[i] > remaining) break;

            path.push_back(candidates[i]);

            // i + 1 because each index can only be used once.
            backtrack(i + 1,remaining - candidates[i],candidates);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
        sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates);

        return ans;
    }
};