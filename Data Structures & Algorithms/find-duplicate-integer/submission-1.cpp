class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        slow=nums[0];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
        /*
        sort(nums.begin(),nums.end());
        int prev=0;

        for(int n:nums){
            if(prev==n)return n;
            prev=n;
        }
        return 0;
        */
        /*
        unordered_map<int,int>m;
        int prev=0;
        for(int n:nums){
            if(prev==n)return n;

            m[n]++;
            prev=n;
        }
        for(int n:nums){
            if(m[n]>1)return n;
        }
        return 0;
        */
    }
};
