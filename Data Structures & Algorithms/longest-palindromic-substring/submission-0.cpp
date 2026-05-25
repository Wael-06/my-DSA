class Solution {
public:
    string expand(string s,int l,int r){
        while(l>=0&&r<=s.size()&&s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        string res="";

        for(int i=0;i<s.size();i++){
            string even=expand(s,i,i);
            string odd=expand(s,i,i+1);

            if(even.size()>res.size())res=even;
            if(odd.size()>res.size())res=odd;
            
        }
        return res;
    }
};
