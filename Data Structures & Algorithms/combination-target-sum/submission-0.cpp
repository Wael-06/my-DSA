class Solution {
public:    
    vector<vector<int>> ans;
    vector<int> path;
    int target;

    void backtrack(int start, int remaining, vector<int>& nums) {
        if(remaining==0){
            ans.push_back(path);
            return;
        }
        if(remaining<0)return;

        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(i,remaining-nums[i],nums);
            path.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        target=tar;
        backtrack(0,tar,nums);
        return ans;
    }
};
/*
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);

            backtracking(i + 1, nums);

            path.pop_back();
        }
*/