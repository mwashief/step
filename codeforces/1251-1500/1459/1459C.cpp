/*
    Washief Hossain Mugdho
    20 December 2020
    Codeforces 1459C
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

ull gcd(ull a, ull b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
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

    int n, m;
    cin >> n >> m;
    vector<ull> a(n);
    vector<ull> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
        cin >> b[i];
    ull g = 0;
    for (int i = 1; i < n; i++)
        g = gcd(g, a[i] - a[0]);
    for (int i = 0; i < m; i++)
        cout << gcd(g, a[0] + b[i]) << " ";
    cout << endl;
}
