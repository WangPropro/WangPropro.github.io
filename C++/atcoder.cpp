#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    cin >> n;
    int a[n+1] = {0};
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        a[x]++;
        a[y]++;
    }
    x = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] > 1)
            x++;
    if(x == 1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}