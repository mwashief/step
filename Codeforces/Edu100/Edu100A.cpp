/*
    Washief Hossain Mugdho
    17 December 2020
    Edu100 Edu100A
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
    ll a, b, c, sum;
    cin >> a >> b >> c;
    sum = a + b + c;
    ll x = 7 * sum / 9;
    ll y;
    while (1)
    {
        y = x / 7;
        if (x + 2 * y >= sum)
            break;
        x++;
    }
    if (x + 2 * y > sum)
    {
        cout << "NO" << endl;
        return;
    }
    ll mini = min({a, b, c});
    if (mini >= y && x % 7 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
