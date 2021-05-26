/*
    Washief Hossain Mugdho
    22 February 2021
    1320 1320B
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n, m, k;
    vvi adj;
    vi shortest;
    vi path;
    vector<unordered_set<int>> nextNode;
    cin >> n >> m;
    adj = vvi(n);
    shortest = vi(n, INT32_MAX);
    nextNode = vector<unordered_set<int>>(n);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[y].pb(x);
    }
    cin >> k;
    path = vi(k);
    rep(i, k)
    {
        cin >> path[i];
        path[i]--;
    }
    queue<pair<pii, int>> Q;
    Q.push({{path.back(), 0}, -1});
    while (!Q.empty())
    {
        int level = Q.front().fr.sc;
        int node = Q.front().fr.fr;
        int parent = Q.front().sc;
        Q.pop();
        if (shortest[node] > level)
        {
            nextNode[node].clear();
            shortest[node] = level;
            nextNode[node].insert(parent);
            for (auto x : adj[node])
                Q.push({{x, level + 1}, node});
        }
        else if (shortest[node] == level)
            nextNode[node].insert(parent);
    }
    int mini = 0, maxi = 0;
    rep(i, k - 1)
    {
        if (nextNode[path[i]].find(path[i + 1]) != nextNode[path[i]].end())
        {
            if (nextNode[path[i]].size() != 1)
                maxi++;
        }
        else
        {
            mini++;
            maxi++;
        }
    }
    cout << mini << " " << maxi << endl;
}
