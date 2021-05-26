/*
    Washief Hossain Mugdho
    29 March 2021
    Codeforces 1486 1486E
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
#define N 50

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
int n, m;

inline int getInter(int node, int pr)
{
    pr--;
    return node * N + n + pr;
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
    vector<vpii> adj(n * (N + 1));
    rep(i, m)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        repe(j, N)
        {
            adj[getInter(x, j)].pb({y, (j + z) * (j + z)});
            adj[getInter(y, j)].pb({x, (j + z) * (j + z)});
        }
        adj[x].pb({getInter(y, z), 0});
        adj[y].pb({getInter(x, z), 0});
    }
    vi distance((N + 1) * n, INT32_MAX);

    distance[0] = 0;
    set<pair<int, int>> Q;
    Q.insert({0, 0});
    while (!Q.empty())
    {
        int v = Q.begin()->second;
        Q.erase(Q.begin());

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (distance[v] + len < distance[to])
            {
                Q.erase({distance[to], to});
                distance[to] = distance[v] + len;
                Q.insert({distance[to], to});
            }
        }
    }

    rep(i, n) if (distance[i] == INT32_MAX) cout << "-1 ";
    else cout << distance[i] << " ";
}
