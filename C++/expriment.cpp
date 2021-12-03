/* -------- PTA -----------
   银行窗口排队问题，数组方法
   ------------------------
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int *a = new int[n + 1];
    queue<int> q1, q2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            q1.push(a[i]);
        if (a[i] % 2 == 0)
            q2.push(a[i]);
    }
    // while(!q1.empty())
    // {
    //     cout << q1.front() << " ";
    //     q1.pop();
    // }
    // cout << endl;
    // while(!q2.empty())
    // {
    //     cout << q2.front() << " ";
    //     q2.pop();
    // }
    int cnt = n;
    while (!cnt)
    {
        if (cnt % 3 != 0)
        {
            cout << q1.front() << " ";
            q1.pop();
            cnt--;
        }
        if (cnt % 3 == 0)
        {
            cout << q2.front() << " ";
            q2.pop();
            cnt--;
        }
    }
    delete (a);
    return 0;
}