/*
    Washief Hossain Mugdho
    12 October 2020
    Others 1430D
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

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n, T;
    cin >> T;
    while (T--)
    {
        char prev, now;
        int current = 1;
        cin >> n;
        cin >> prev;
        vector<int> all;
        for (int i = 1; i < n; i++)
        {
            cin >> now;
            if (now != prev)
            {
                all.pb(current);
                current = 1;
            }
            else
                current++;
            prev = now;
        }
        all.pb(current);
        int alone = 0;
        int ans = 0;
        for (auto i : all)
        {
            if (i == 1)
                alone++;
            else if (i != 2)
            {
                int extra = i - 2;
                alone = max(0, alone - extra);
            }
            ans++;
        }
        cout << ans - alone / 2 << endl;
    }
}
