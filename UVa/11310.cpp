#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull dp[41] = {1, 1, 5};

int main()
{
    for (int i = 3; i < 41; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] * 4 + dp[i - 3] * 2;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << dp[x] << endl;
    }
}
