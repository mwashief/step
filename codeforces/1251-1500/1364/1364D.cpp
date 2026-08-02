/*
    Washief Hossain Mugdho
    18 April 2021
    Codeforces 1364 1364D
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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
    cin >> n >> m >> k;
    vvi adj(n);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi visited(n);
    vi parent(n);
    int cycleLen = INT32_MAX;
    int endPoint;

    function<void(int, int)> dfs = [&](int node, int height) {
        visited[node] = -height;
        for (auto child : adj[node])
            if (child != parent[node] && visited[child] <= 0)
            {
                if (visited[child])
                {
                    int len = height + visited[child] + 1;
                    if (len < cycleLen)
                    {
                        cycleLen = len;
                        endPoint = node;
                    }
                }
                else
                {
                    parent[child] = node;
                    dfs(child, height + 1);
                }
            }
        visited[node] = height;
    };

    rep(i, n) if (visited[i] == 0)
    {
        parent[i] = i;
        dfs(i, 1);
    }

    if (cycleLen == INT32_MAX)
    {
        cout << 1 << endl;
        vi iSet;
        vvi memo(n, vi(2, -1));

        function<int(int, int)> dp = [&](int node, int taking) -> int {
            if (memo[node][taking] != -1)
                return memo[node][taking];
            int res = taking;
            for (auto child : adj[node])
                if (child != parent[node])
                    res += dp(child, 1 - taking);
            return memo[node][taking] = res;
        };
        function<void(int, int)> traverse = [&](int node, int taking) -> void {
            if (taking)
                iSet.pb(node);
            for (auto child : adj[node])
                if (child != parent[node])
                {
                    int x = dp(child, 0);
                    int y = -1;
                    if (1 - taking)
                        y = dp(child, 1);
                    if (x > y)
                        traverse(child, 0);
                    else
                        traverse(child, 1);
                }
        };
        rep(i, n) if (parent[i] == i)
        {
            if (dp(i, 0) > dp(i, 1))
                traverse(i, 0);
            else
                traverse(i, 1);
        }
        k = (k + 1) / 2;
        for (int i = 0; i < k; i++)
            cout << iSet[i] + 1 << " ";
        return 0;
    }
    if (cycleLen <= k)
    {
        cout << 2 << endl;
        cout << cycleLen << endl;
        while (cycleLen)
        {
            cout << endPoint + 1 << " ";
            cycleLen--;
            endPoint = parent[endPoint];
        }
        return 0;
    }
    cout << 1 << endl;
    cycleLen = (k + 1) / 2;
    while (cycleLen)
    {
        cout << endPoint + 1 << " ";
        cycleLen--;
        endPoint = parent[parent[endPoint]];
    }
}
