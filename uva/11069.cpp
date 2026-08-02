#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dp[77] = {0, 1, 2, 2};
    for (int i = 4; i <= 76; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    int n;
    while (cin >> n)
        cout << dp[n] << endl;
}
