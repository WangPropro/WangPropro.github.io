#include <bits/stdc++.h>
using namespace std;
int T, n;
bool Check(int m)
{
	for (int i = 2; i < m; i++)
		if (m % i == 0)
			return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cin >> n;
		int Sum = 0, Now = 0;
		for (int i = 1, x; i <= n; i++)
		{
			cin >> x;
			Sum += x;
			if (x % 2)
				Now = i;
		}
		if (Check(Sum))
			Now = 0;
		printf("%d\n", n - (Now != 0));
		for (int i = 1; i <= n; i++)
			if (i != Now)
				printf("%d ", i);
		cout << endl;
	}
}