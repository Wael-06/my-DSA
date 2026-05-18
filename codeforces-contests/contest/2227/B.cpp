#include <iostream>
#include <unordered_map>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        int res=0;
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            if (s[i] == '(') {res++;}
            if (s[i] == ')') {res--;}
        }
        if(res==0) {cout<<"YES"<<endl;}
        else {cout<<"NO"<<endl;}
    }
    return 0;
}
