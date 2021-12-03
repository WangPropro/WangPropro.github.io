#include <bits/stdc++.h>
using namespace std;
string int_to_string(int num)
{
    stringstream ss;
    ss << num;
    string s;
    ss >> s;
    return s;
}
int main()
{
    stack<int> A;
    stack<int> B;
    vector<string> strs;
    int max_A_size, max_B_size;
    cin >> max_A_size >> max_B_size;
    if (max_A_size > max_B_size)
    {
        swap(max_A_size, max_B_size);
    }
    char c;
    while (1)
    {
        cin >> c;
        if (c == 'T')
        {
            break;
        }
        else if (c == 'A')
        {
            int num;
            cin >> num;
            if (A.size() < max_A_size)
            {
                A.push(num);
            }
            else if (A.size() == max_A_size && B.empty())
            {
                for (int i = 0; i < max_A_size; i++)
                {
                    B.push(A.top());
                    A.pop();
                }
                A.push(num);
            }
            else
            {
                strs.push_back("ERROR:Full");
            }
        }
        else
        {
            if (!B.empty())
            {
                strs.push_back(int_to_string(B.top()));
                B.pop();
            }
            else if (B.empty() && A.size() != 0)
            {
                int len = A.size();
                for (int i = 0; i < len; i++)
                {
                    B.push(A.top());
                    A.pop();
                }
                strs.push_back(int_to_string(B.top()));
                B.pop();
            }
            else if (B.empty() && A.size() == 0)
            {
                strs.push_back("ERROR:Empty");
            }
        }
    }
    for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++)
    {
        cout << (*it) << endl;
    }
    return 0;
}