#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
map<string, int> mp;
string s[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    cin >> T;
    while(T--)
    {
        string cur;
        mp.clear();
        queue<string> q;
        while(!q.empty())
        {
            q.pop();
        }
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n;i++)
        {
            cin >> cur;
            cin >> s[i];
            if(cur == "in")
                q.push(s[i]);
            else
            {
                while(mp[q.front()] == 1)
                {
                    q.pop();
                }
                if(s[i] == q.front())
                    ans++;
                mp[s[i]] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}