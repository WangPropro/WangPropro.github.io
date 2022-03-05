#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    for (int i = 0; i < 10;i++)
    {
        arr[i] = i;
    }
    for(auto & a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}