/*
    Washief Hossain Mugdho
    02 February 2021
    ABC190 E
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
const int MAX = 200000;
int n, m, k;
vvi dist;
vvi adj;
vvi memo;
vi c;
int allMask;

void bfs(int ind)
{
    int start = c[ind];
    queue<pii> Q;
    Q.push({start, 0});
    vb visited(n, 0);
    visited[start] = 1;
    while (!Q.empty())
    {
        int node = Q.front().fr;
        int dd = Q.front().sc;
        dist[ind][node] = dd;
        Q.pop();
        for (auto x : adj[node])
            if (!visited[x])
            {
                visited[x] = 1;
                Q.push({x, dd + 1});
            }
    }
}

int dp(int mask, int now)
{
    if (mask == allMask)
        return 0;
    if (memo[mask][now] != -1)
        return memo[mask][now];
    int res = MAX;
    rep(i, k) if ((mask & (1 << i)) == 0)
        res = min(res, dp(mask | (1 << i), i) + dist[now][c[i]]);
    return memo[mask][now] = res;
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
    cin >> n >> m;
    adj = vvi(n, vi());
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    cin >> k;
    allMask = (1 << k) - 1;
    c = vi(k);
    memo = vvi(1 << k, vi(k, -1));
    dist = vvi(k, vi(n, MAX));
    rep(i, k)
    {
        cin >> c[i];
        c[i]--;
        bfs(i);
    }
    int res = INT32_MAX;
    rep(i, k)
        res = min(res, dp(1 << i, i));
    if (res >= MAX)
        cout << -1 << endl;
    else
        cout << res + 1 << endl;
}
