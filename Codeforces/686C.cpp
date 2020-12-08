/*
    Washief Hossain Mugdho
    08 December 2020
    Codeforces 686C
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
    int n, x;
    cin >> n;
    vector<int> a(n);
    vector<int> last(n, -1);
    vector<int> segs(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        x--;
        a[i] = x;
        if (i - last[x] > 1)
            segs[x]++;
        last[x] = i;
    }
    cin >> x;
    x--;
    a[n - 1] = x;
    if (n - 1 - last[x] > 1)
        segs[x]++;
    segs[x]--;
    int res = n + 1;
    for (int i = 0; i < n; i++)
        res = min(res, segs[a[i]]);
    cout << res << endl;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
