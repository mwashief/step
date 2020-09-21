/*
    Washief Hossain Mugdho
    21 September 2020
    Educational DP Permutation
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
#define mod 1000000007
using namespace std;

inline int sub(int a, int b)
{
    int c = a - b;
    return c < 0 ? (c + mod) : c;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    string s;
    cin >> n >> s;
    int prefix[n][n + 1];

    for (int i = 1; i <= n; i++)
        prefix[0][i] = 1;
    for (int i = 0; i < n; i++)
        prefix[i][0] = 0;

    for (int i = 1; i < n; i++)
    {
        bool x = (s[i - 1] == '<');
        for (int j = 1; j <= i + 1; j++)
        {
            if (x)
                prefix[i][j] = (prefix[i][j - 1] + prefix[i - 1][j - 1]) % mod;
            else
                prefix[i][j] = (prefix[i][j - 1] + sub(prefix[i - 1][n], prefix[i - 1][j - 1])) % mod;
        }
        for (int j = i + 2; j <= n; j++)
            prefix[i][j] = prefix[i][i + 1];
    }
    cout << prefix[n - 1][n] << endl;
}
