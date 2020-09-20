/*
    Washief Hossain Mugdho
    20 September 2020
    Educational DP Flowers
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
#define N 200005
using namespace std;
int n, h[N], a[N];

ull t[2 * N];

void modify(int p, ull value)
{
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = max(t[p], t[p ^ 1]);
}

ull query(int l, int r)
{
    ull res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, t[l++]);
        if (r & 1)
            res = max(res, t[--r]);
    }
    return res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        ull prev = query(1, h[i]);
        ull cur = query(h[i], h[i] + 1);
        if (cur < prev + a[i])
            modify(h[i], prev + a[i]);
    }
    cout << query(0, N + 1) << endl;
}
