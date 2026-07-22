class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int start, vector<int>& nums) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);

            backtracking(i + 1, nums);

            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(0, nums);
        return ans;
    }
};