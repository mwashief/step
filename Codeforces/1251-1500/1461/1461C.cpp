/*
    Washief Hossain Mugdho
    14 December 2020
    Codeforces 1461C
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
    int n, m, x;
    cin >> n >> m;
    int sortedStart = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x != i)
            sortedStart = i + 1;
    }
    sortedStart--;
    double p, currentState[2] = {1.0, 0.0};
    for (int i = 0; i < m; i++)
    {
        cin >> x >> p;

        /**
         * transition matrix:
         * | 1-p   p|
         * | 0     1|
         */

        if (x >= sortedStart)
        {
            currentState[1] += currentState[0] * p;
            currentState[0] = currentState[0] * (1.0 - p);
        }
    }
    if (sortedStart == 0)
    {
        cout << 1.0 << endl;
        return;
    }
    cout << fixed << setprecision(15) << currentState[1] << endl;
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
