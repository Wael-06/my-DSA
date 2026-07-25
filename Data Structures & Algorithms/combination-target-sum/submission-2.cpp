class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int start, int remaining,vector<int>& nums){
        if (remaining == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > remaining) break;

            path.push_back(nums[i]);
            backtracking(i, remaining - nums[i], nums);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());

        backtracking(0, target, nums);

        return ans;
    }
};