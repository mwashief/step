/*
    Washief Hossain Mugdho
    24 December 2021
    Codeforces 1501-1750 1516 1516E
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

vi all, h;
vvi adj;

int dfs1(int node, int parent)
{
    if (node != 0 && gsz(adj[node]) == 1)
    {
        h[node] = 1;
        return 1;
    }
    for (auto child : adj[node])
        if (child != parent)
            h[node] = max(h[node], dfs1(child, node) + 1);
    return h[node];
};

void dfs2(int node, int parent, int hei)
{
    if (node != 0 && gsz(adj[node]) == 1)
    {
        all.pb(hei);
        return;
    }
    vpii children;
    for (auto child : adj[node])
        if (child != parent)
            children.pb({h[child], child});
    sort(a2z(children));
    dfs2(children.back().sc, node, hei + 1);
    rep(i, gsz(children) - 1) dfs2(children[i].sc, node, 1);
}

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    int n, k;
    cin >> n >> k;
    adj = vvi(n);
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    h = vi(n);
    dfs1(0, -1);
    dfs2(0, -1, 1);

    ll w = 0;
    ll r = 0;
    ll b = 0;
    if (gsz(all) <= k)
    {
        r = gsz(all);
        w = n - r;
        ll res = w * r;
        int extra = min<int>(w, k - gsz(all));
        repe(i, extra)
        {
            ll temp = 1LL * (w - i) * (r + i);
            res = max(res, temp);
        }
        cout << res << endl;
        return 0;
    }
    sort(a2z(all));
    reverse(a2z(all));
    rep(i, k)
    {
        r++;
        w += all[i] - 1;
    }
    b = n - w - r;
    ll res = 1LL * w * (r - b);
    int extra = b;
    repe(i, extra)
    {
        ll temp = 1LL * (w + i) * (r - b + i);
        res = min(res, temp);
    }

    cout << res << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/