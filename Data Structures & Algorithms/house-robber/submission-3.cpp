class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        vector<int>m(n,0);
        m[0]=nums[0];
        m[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            m[i]=max(m[i-1],m[i-2]+nums[i]);
        }

        return max(m[n-1],m[n-2]);
    }
};
//start from 0 or 1 
//steal this or the next wrong the 