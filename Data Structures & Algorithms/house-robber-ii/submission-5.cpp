class Solution {
public:

    int helper(vector<int>& nums, int l, int r) {

        if (r - l == 0)
            return nums[l];

        int prev2 = nums[l];

        int prev1 = max(nums[l], nums[l + 1]);

        for(int i = l + 2; i <= r; i++) {

            int curr = max(
                prev1,
                nums[i] + prev2
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        int case1 = helper(nums, 0, n - 2);

        int case2 = helper(nums, 1, n - 1);

        return max(case1, case2);
    }
};