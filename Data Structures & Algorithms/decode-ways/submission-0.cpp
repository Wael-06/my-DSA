class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        dp[n] = 1; 

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                dp[i] += dp[i + 1];
            }
            
            // Check if two-digit combination is valid (10-26)
            if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                dp[i] += dp[i + 2];
            }
        }
        
        return dp[0];
    }
};

/*class Solution {
public:
    bool dfs(int x){
        if(x>=1&&x<=26)return true;
        return false;
    }

    int numDecodings(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            if(dfs(stoi(s[i])))res++;
            if(dfs(stoi(s.substr(i, 2))))res++;
        }
        return res;
    }
};
*///c-'a'+1;