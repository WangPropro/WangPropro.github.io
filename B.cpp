/*                 typo
We can check if S and T are the same without performing any operation,
or if S and T coincides when the i-th and (i+1)-th characters are swapped for each i=1,2,бн,(length of S)?1.
The time complexity is O(N2), where N=(length of S).
*/
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