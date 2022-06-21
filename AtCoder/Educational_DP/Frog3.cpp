/*
    Washief Hossain Mugdho
    04 October 2020
    Educational DP Frog3
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

const int maxn = 1e6 + 4;
int n;
ll c, h;

pair<ll, ll> line[4 * maxn];

inline ll f(pair<ll, ll> a, ll x)
{
    return a.fr * x + a.sc;
}

void add_line(pair<ll, ll> nw, int v = 1, int l = 0, int r = maxn)
{
    int m = (l + r) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if (mid)
        swap(line[v], nw);
    if (r - l == 1)
        return;
    else if (lef != mid)
        add_line(nw, 2 * v, l, m);
    else
        add_line(nw, 2 * v + 1, m, r);
}

ll get(int x, int v = 1, int l = 0, int r = maxn)
{
    int m = (l + r) / 2;
    if (r - l == 1)
        return f(line[v], x);
    else if (x < m)
        return min(f(line[v], x), get(x, 2 * v, l, m));
    else
        return min(f(line[v], x), get(x, 2 * v + 1, m, r));
}

void init()
{
    for (int i = 0; i < 4 * maxn; i++)
        line[i] = {0, INT64_MAX};
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    init();
    cin >> n >> c;
    cin >> h;
    add_line({-2 * h, h * h});
    for (int i = 1; i < n; i++)
    {
        cin >> h;
        ll q = get(h);
        ll dpi = q + 1LL * c + h * h;
        if (i == n - 1)
        {
            cout << dpi << endl;
            return 0;
        }
        add_line({-2 * h, h * h + dpi});
    }
}
