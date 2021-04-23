/*
    Washief Hossain Mugdho
    23 April 2021
    Codeforces 1510 1510G
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
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
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

inline void _()
{
    int n, k;
    cin >> n >> k;
    vvi children(n, vi());
    vi height(n);
    vi nodes(n);
    repe(i, n - 1)
    {
        int x;
        cin >> x;
        children[x - 1].pb(i);
    }

    function<int(int)> dfs = [&](int node) {
        nodes[node] = 1;
        int m = 0;
        for (auto child : children[node])
        {
            m = max(m, dfs(child));
            nodes[node] += nodes[child];
        }
        height[node] = m + 1;
        return height[node];
    };

    dfs(0);
    vi res;

    function<void(int, int)> getBackPath = [&](int node, int take) -> void {
        if (take == 0)
            return;
        take--;
        res.pb(node);
        for (auto child : children[node])
        {
            if (!take)
                return;
            int now = min(take, nodes[child]);
            take -= now;
            getBackPath(child, now);
            res.pb(node);
        }
    };
    function<void(int, int)> getPath = [&](int node, int take) -> void {
        if (take == 0)
            return;
        take--;
        res.pb(node);
        int h = 0;
        int d = -1;
        for (auto child : children[node])
            if (height[child] > h)
            {
                h = height[child];
                d = child;
            }
        int nodeInChain = min(take, nodes[d]);
        take -= nodeInChain;
        for (auto child : children[node])
            if (child != d)
            {
                if (!take)
                    break;
                int now = min(take, nodes[child]);
                take -= now;
                getBackPath(child, now);
                res.pb(node);
            }
        getPath(d, nodeInChain);
    };
    getPath(0, k);
    cout << gsz(res) - 1 << endl;
    for (auto a : res)
        cout << a + 1 << " ";
    cout << endl;
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
    int __;
    cin >> __;
    while (__--)
        _();
}
