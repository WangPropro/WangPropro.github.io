#include <bits/stdc++.h>
using namespace std;
int main(){
    string s, t;
    string res = "No";
    cin >> s >> t;
    if(s==t)
        res = "Yes";
    int i;
    for (i = 0; i < s.size();i++){
        if(s[i]!=t[i]){
            if(i > 0){
            swap(s[i - 1], s[i]);
            if(s==t)
                res = "Yes";
            swap(s[i - 1], s[i]);
            }
            if(i+1 < s.size()){
               swap(s[i], s[i + 1]);
               if(s==t)
                   res = "Yes";
               swap(s[i], s[i + 1]);
            }
            break;
        }
    }
    cout << res << endl;
    return 0;
}