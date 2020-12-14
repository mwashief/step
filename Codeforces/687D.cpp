/*
    Washief Hossain Mugdho
    14 December 2020
    Codeforces 687D
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
    vector<vector<int>> all(32, vector<int>());
    vector<int> data;
    int n, x;
    cin >> n;
    data.pb(0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        all[31 - __builtin_clz(x)].pb(x);
        data.pb(data[data.size() - 1] ^ x);
    }
    for (auto arr : all)
        if (arr.size() > 2)
        {
            cout << 1 << endl;
            return 0;
        }
    int res = INT32_MAX;
    for (int leftStart = 1; leftStart < n; leftStart++)
        for (int leftEnd = leftStart; leftEnd < n; leftEnd++)
            for (int rightStart = leftEnd + 1; rightStart <= n; rightStart++)
                for (int rightEnd = rightStart; rightEnd <= n; rightEnd++)
                    if ((data[leftEnd] ^ data[leftStart - 1]) > (data[rightEnd] ^ data[rightStart - 1]))
                        res = min(res, leftEnd - leftStart + rightEnd - rightStart);

    if (res == INT32_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
}
