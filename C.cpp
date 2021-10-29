/*                         Select Mul
There are at most 9!¡Á8=2903040 ways of separations 
(or  22903040=1451520 ways when the order of two separated integers are ignored), 
which is small enough.
Therefore, we can brute force over all possible ways of separations.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin >> n;
    sort(n.begin(), n.end());
    int res = 0;
    int i, j;
    do{
        for (i = 1; i < n.size();i++){
            string l = "", r = "";
            for (j = 0; j < i;j++)
                l += n[j];
            for (j = i; j < n.size();j++)
                r += n[j];
                if(l[0]=='0'||r[0]=='0')
                    continue;
                res = max(res, stoi(l) * stoi(r));
        }
    } while (next_permutation(n.begin(), n.end()));
    cout << res << endl;
}