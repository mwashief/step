#include <bits/stdc++.h>
using namespace std;

int main()
{
    string broken;
    string s;
    while (1)
    {
        s = "";
        broken = "";
        while (getline(cin, broken) && broken[broken.size() - 1] != '#')
            s += broken;
        s += broken;
        if (s == "")
            break;
        int pow = 1;
        int ans = 0;
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                ans = (ans + pow) % 131071;
            }
            pow = (pow * 2) % 131071;
        }
        if (ans == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}