/*
    Washief Hossain Mugdho
    04 October 2020
    Educational DP Grid2
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
    int h, w, n;
    cin >> h >> w >> n;

    int N = 2 * max(h, w);
    int fact[N + 1];
    fact[0] = 1;
    int invFact[N + 1];
    for (int i = 1; i <= N; i++)
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    invFact[N] = 1;
    int power = 1000000005;
    int base = fact[N];
    for (; power; power >>= 1, base = (1LL * base * base) % mod)
        if (power & 1)
            invFact[N] = (1LL * invFact[N] * base) % mod;
    for (int i = N; i > 0; i--)
        invFact[i - 1] = (1LL * invFact[i] * i) % mod;

    pair<int, int> arr[n + 1];
    arr[n].fr = h;
    arr[n].sc = w;
    for (int i = 0; i < n; i++)
        cin >> arr[i].fr >> arr[i].sc;
    sort(arr, arr + n);

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (1LL * fact[arr[i].fr + arr[i].sc - 2] * invFact[arr[i].fr - 1]) % mod;
        dp[i] = (1LL * dp[i] * invFact[arr[i].sc - 1]) % mod;
        for (int j = 0; j < i; j++)
            if (arr[i].sc >= arr[j].sc)
            {
                int x = arr[i].fr - arr[j].fr;
                int y = arr[i].sc - arr[j].sc;
                int zz = (1LL * fact[x + y] * invFact[x]) % mod;
                int z = (1LL * zz * invFact[y]) % mod;
                dp[i] -= (1LL * dp[j] * z) % mod;
                if (dp[i] < 0)
                    dp[i] += mod;
            }
    }
    cout << dp[n] << endl;
}
