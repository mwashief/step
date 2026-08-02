/*
    Washief Hossain Mugdho
    05 December 2020
    Codeforces 1453D
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
using namespace std;

void solve()
{
    ull k;
    ull n = 0;
    cin >> k;
    if (k == 0 || k % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    k >>= 1;
    vector<pair<int, int>> res;
    for (ull i = 59; k != 0 && i > 0; i--)
    {
        ull d = (1ULL << i) - 1;
        ull c = k / d;

        if (c)
        {
            n += c * i;
            res.pb({i, c});
        }
        if (n > 2000)
        {
            cout << -1 << endl;
            return;
        }
        k %= d;
    }
    cout << n << endl;
    for (auto p : res)
    {
        for (int j = 0; j < p.sc; j++)
        {
            cout << 1 << " ";
            for (int i = 1; i < p.fr; i++)
                cout << 0 << " ";
        }
    }
    cout << endl;
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
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}
