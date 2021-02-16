/*
    Washief Hossain Mugdho
    15 December 2020
    690Div3 1462C
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
using namespace std;

void solve()
{
    int x;
    cin >> x;
    set<int> nums;
    for (int i = 9; i > 0; i--)
    {
        if (x - i < 0)
            continue;
        x -= i;
        nums.insert(i);
    }
    if (x != 0)
        cout << -1 << endl;
    else
    {
        for (auto a : nums)
            cout << a;
        cout << endl;
    }
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
