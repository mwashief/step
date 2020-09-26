/*
    Washief Hossain Mugdho
    26 September 2020
    Educational DP Intervals
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
const int MAX = 2e5 + 5;
int n, m, l, r, a;

ll tree[4 * MAX];
ll lazy[4 * MAX];

void update(int node, int ql, int qr, int nl, int nr, ll val)
{
    if (qr < nl || ql > nr || nl > nr)
        return;
    if (ql <= nl && nr <= qr)
    {
        lazy[node] += val;
        if (nl == nr)
        {
            tree[node] += lazy[node];
            lazy[node] = 0;
        }
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (nl + nr) >> 1;
    lazy[left] += lazy[node];
    lazy[right] += lazy[node];
    lazy[node] = 0;
    update(left, ql, qr, nl, mid, val);
    update(right, ql, qr, mid + 1, nr, val);
    tree[node] = max(tree[left] + lazy[left], tree[right] + lazy[right]);
}

ll query(int node, int ql, int qr, int nl, int nr)
{
    if (qr < nl || ql > nr || nl > nr)
        return INT64_MIN;
    if (ql <= nl && nr <= qr)
    {
        if (nl == nr)
        {
            tree[node] += lazy[node];
            lazy[node] = 0;
        }
        return tree[node] + lazy[node];
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (nl + nr) >> 1;
    lazy[left] += lazy[node];
    lazy[right] += lazy[node];
    lazy[node] = 0;
    ll a = query(left, ql, qr, nl, mid);
    ll b = query(right, ql, qr, mid + 1, nr);
    tree[node] = max(tree[left] + lazy[left], tree[right] + lazy[right]);
    return max(a, b);
}

int main()
{

#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> m;
    vector<pair<int, int>> rules[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> a;
        rules[r].pb(mp(l, a));
    }
    for (int i = 1; i <= n; i++)
    {
        ll mx = query(1, 0, i - 1, 0, n);
        for (auto p : rules[i])
        {
            l = p.fr;
            a = p.sc;
            update(1, l, i, 0, n, (ll)a);
        }
        update(1, i, i, 0, n, (ll)mx);
    }
    cout << query(1, 0, n, 0, n) << endl;
}
