//       B - String Shifting
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 10000
using namespace std;
int main()
{
    char s[maxn];
    char c1[maxn];
    char c2[maxn];
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    cin >> s;
    long long len = strlen(s);
    if (strlen(s) < 3)
        cout << s << endl;
    else
    {
        c1[0] = s[len - 1];
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 1; j < len; j++)
            {
                c1[j] = s[i];
            }
        }
        cout << c1 << endl;
        c2[0] = s[len - 2];
        c2[1] = s[len - 1];
        for (int i = 0; i < len - 2; i++)
        {
            for (int j = 2; j < len; j++)
            {
                c2[j] = s[i];
            }
        }
        cout << c2 << endl;
    }
    return 0;
}