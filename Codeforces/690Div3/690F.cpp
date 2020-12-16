/*
    Washief Hossain Mugdho
    15 December 2020
    690Div3 690F
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
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
#define MAX 200005
using namespace std;
int n;

void solve()
{
    vector<int> l;
    vector<int> r;
    vector<pair<int, int>> all;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        l.pb(x);
        r.pb(y);
        all.pb({x, y});
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int minimum = n;
    for (auto x : all)
    {
        int leftSegments = lower_bound(r.begin(), r.end(), x.fr) - r.begin();
        int rightSegments = l.end() - upper_bound(l.begin(), l.end(), x.sc);
        minimum = min(minimum, leftSegments + rightSegments);
    }
    cout << minimum << endl;
}

int main()
{
    fastio;
    untie;
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
