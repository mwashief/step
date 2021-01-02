/*
    Washief Hossain Mugdho
    17 December 2020
    Edu100 1463B
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

void run_tests()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> commands;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        commands.pb({x, y});
    }
    commands.pb({INT64_MAX / 4, -1});
    ll st = 0;
    ll source = 0;
    ll destination = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        ll ti = commands[i].fr;
        ll xi = commands[i].sc;
        ll v = (destination - source);
        ll endtime = st + abs(v);
        v = v > 0 ? 1 : -1;
        if (ti >= endtime)
        {
            st = ti;
            source = destination;
            destination = xi;
            v = (destination - source);
            v = v > 0 ? 1 : -1;
        }
        if (v > 0)
        {
            ll d1 = source + v * (ti - st);
            ll d2 = min(source + v * (commands[i + 1].fr - st), destination);
            if (xi >= d1 && xi <= d2)
                res++;
        }
        else
        {
            ll d1 = source + v * (ti - st);
            ll d2 = max(source + v * (commands[i + 1].fr - st), destination);
            if (xi <= d1 && xi >= d2)
                res++;
        }
    }
    cout << res << endl;
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
        run_tests();
}
