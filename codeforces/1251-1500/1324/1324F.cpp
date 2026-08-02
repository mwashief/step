/*
    Washief Hossain Mugdho
    22 February 2021
    1324 1324F
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}
int n;
vvi adj;
vi down;
vi up;
vi p;

int downdfs(int node, int parent)
{
    p[node] = parent;
    for (auto child : adj[node])
        if (child != parent)
        {
            int val = downdfs(child, node);
            if (val >= 0)
                down[node] += val;
        }
    return down[node];
}

int updfs(int node)
{
    if (up[node] != -1)
        return up[node];
    up[node] = down[p[node]] + updfs(p[node]);
    if (down[node] >= 0)
        up[node] -= down[node];
    if (up[node] < 0)
        up[node] = 0;
    return up[node];
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    adj = vvi(n);
    down = vi(n);
    up = vi(n, -1);
    p = vi(n);
    rep(i, n)
    {
        cin >> down[i];
        if (!down[i])
            down[i] = -1;
    }
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    up[0] = 0;
    downdfs(0, 0);
    rep(i, n) cout << down[i] + updfs(i) << " ";
    cout << endl;
}
