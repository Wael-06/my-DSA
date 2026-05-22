class Solution {
public:
    vector<int>memo;

    int fab(int x){
        if(x<=2)return x;

        if(memo[x]!=-1){
            return memo[x];
        }

        memo[x]=fab(x-1)+fab(x-2);
        return memo[x];
    }

    int climbStairs(int n) { 
        memo.resize(n + 1, -1);   
        return fab(n);
    }
};
