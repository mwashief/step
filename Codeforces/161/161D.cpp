/*
    Washief Hossain Mugdho
    01 January 2021
    Codeforces 161D
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
void input(ArgTypes &... args);
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
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}
int n, k;
ll ans = 0;
vvi adj;
vvl downDis;

void dfs(int node, int parent)
{
    downDis[node][0] = 1;
    for (auto x : adj[node])
        if (x != parent)
        {
            dfs(x, node);
            for (int i = 0; i <= k - 1; i++)
                downDis[node][i + 1] += downDis[x][i];
        }
}

void dfsCalc(int node, int parent)
{
    for (auto x : adj[node])
        if (x != parent)
        {
            for (int i = 1; i < k; i++)
            {
                ans += downDis[x][i - 1] * (downDis[node][k - i] - downDis[x][k - i - 1]);
                downDis[node][k - i] -= downDis[x][k - i - 1];
            }
            ans += downDis[x][k - 1];
            dfsCalc(x, node);
        }
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
    cin >> n >> k;
    adj = vvi(n, vi());
    downDis = vvl(n, vl(k + 1, 0));
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    dfs(0, -1);
    dfsCalc(0, -1);
    cout << ans << endl;
}