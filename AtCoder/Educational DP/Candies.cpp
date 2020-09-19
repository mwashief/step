/*
    Washief Hossain Mugdho
    19 September 2020
    Educational DP Candies
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

int prefix[103][100005];
int a[103], n, k;

inline int sub(int a, int b)
{
    int ans = a - b;
    return ans < 0 ? ans + mod : ans;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    fastio;
    untie;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i][1] = 1;
    }

    for (int i = 1; i <= k + 1; i++)
        prefix[0][i] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            int start = max(0, j - a[i]);
            int x = sub(prefix[i - 1][j + 1], prefix[i - 1][start]);
            prefix[i][j + 1] = (prefix[i][j] + x) % mod;
        }

    cout << sub(prefix[n][k + 1], prefix[n][k]) << endl;
}
