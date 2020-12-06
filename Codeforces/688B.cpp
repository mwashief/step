/*
    Washief Hossain Mugdho
    05 December 2020
    Codeforces 688B
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
    int n;
    cin >> n;
    int a[n];
    ll res = 0;
    ll change = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
            res += abs(a[i] - a[i - 1]);
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    change = max(change, (ll)abs(a[n - 1] - a[n - 2]));
    change = max(change, (ll)abs(a[0] - a[1]));
    for (int i = 1; i < n - 1; i++)
        change = max(change, (ll)abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i - 1] - a[i + 1]));
    cout << res - change << endl;
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
