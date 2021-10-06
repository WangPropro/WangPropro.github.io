#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, k = 1;
    cin >> a >> b;
    int i;
    for (i = b; i < a;i++){
        k *= 32;
    }
    cout << k << endl;
    return 0;
}