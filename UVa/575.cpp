#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (1)
    {
        cin >> s;
        if (s == "0")
            return 0;
        int pow = 2;
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            result += (s[i] - '0') * (pow - 1);
            pow *= 2;
        }
        cout << result << endl;
    }
}