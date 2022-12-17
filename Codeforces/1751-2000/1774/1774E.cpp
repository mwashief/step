/*
    17 December 2022
    Codeforces 1751-2000 1774 1774E
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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
#define MOD 1000000007 // 998244353
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

namespace std
{

    template <class Fun>
    class y_combinator_result
    {
        Fun fun_;

    public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

        template <class... Args>
        decltype(auto) operator()(Args &&...args)
        {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun)
    {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

    template <class T>
    T &unmove(T &&t) { return t; }

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
    int n, d;
    cin >> n >> d;

    vvi adj(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    vvi newNodeToVisit(2, vi(n));
    vvi nicheAche(2, vi(n, -1));
    vector<seti> visit(2);

    rep(i, 2)
    {
        int m;
        cin >> m;
        rep(j, m)
        {
            int x;
            cin >> x;
            visit[i].insert(x - 1);
        }
        visit[i].erase(0);
    }

    rep(piece, 2) y_combinator(
        [&](auto self, int node, int parent, int depth) -> pair<ll, int>
        {
            int newNodes = 0;
            int deep = -1;
            for (auto child : adj[node])
                if (child != parent)
                {
                    auto res = self(child, node, depth + 1);
                    deep = max(deep, res.sc);
                    newNodes += res.fr;
                }

            bool has = visit[piece].count(node);
            if (node != 0 && (newNodes > 0 || has))
                newNodes++;
            newNodeToVisit[piece][node] = newNodes;
            if (deep > -1)
                deep += 1;
            else if (has)
                deep = 0;
            nicheAche[piece][node] = deep;
            return {newNodes, deep};
        })(0, -1, 0);

    ll ans = 2LL * (newNodeToVisit[0][0] + newNodeToVisit[1][0]);

    y_combinator(
        [&](auto self, int node, int parent) -> void
        {
            if (node)
                rep(piece, 2) if (newNodeToVisit[piece][node] == 0 && nicheAche[1 - piece][node] >= d)
                    ans += 2LL;

            for (auto child : adj[node])
                if (child != parent)
                    self(child, node);
        })(0, -1);

    cout << ans << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/