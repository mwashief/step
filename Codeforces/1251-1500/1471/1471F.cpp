/*
    Washief Hossain Mugdho
    05 January 2021
    694Div2 F
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
int n, m;
vi visited;
vvi adj;

void dfs(int now)
{
    if (visited[now] == 1)
    {
        vi unv;
        for (auto x : adj[now])
            if (visited[x] == -1)
            {
                visited[x] = 0;
                unv.pb(x);
            }
        for (auto un : unv)
            dfs(un);
        return;
    }
    for (auto x : adj[now])
        if (visited[x] == -1)
        {
            visited[x] = 1;
            dfs(x);
        }
}

inline void run_tests()
{
    cin >> n >> m;
    adj = vvi(n, vi());
    visited = vi(n, -1);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    visited[0] = 1;
    dfs(0);
    vi ans;
    rep(i, n)
    {
        if (visited[i] == 1)
            ans.pb(i + 1);
        else if (visited[i] == -1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
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
