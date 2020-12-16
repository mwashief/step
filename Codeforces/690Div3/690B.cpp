/*
    Washief Hossain Mugdho
    15 December 2020
    690Div3 690B
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
    int n;
    string s;
    cin >> n >> s;
    if (n < 4)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i <= 4; i++)
        if ((s.substr(0, i) + s.substr(n - 4 + i, 4 - i)) == "2020")
        {
            cout << "YES" << endl;
            return;
        }
    cout << "NO" << endl;
    return;
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
