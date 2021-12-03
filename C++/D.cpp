#include <bits/stdc++.h>
using namespace std;

int isprime(int x)
{
    if(x == 1)
        return 0;
    if(x == 2)
        return 1;
    for (int i = 2; i <= sqrt(x);i++)
    {
        if(x % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    cout << n << "=";
    int flag = 0;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        int t = 0;
        if(isprime(i))
        {
            while(n % i == 0)
            {
                t++;
                n /= i;
            }
            if(flag)
                cout << "*" << i;
            else
            {
                cout << i;
                flag++;
            }
        }
        if(t > 1)
            cout << "^" << t;
    }
        return 0;
}