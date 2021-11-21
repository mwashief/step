/*
    Washief Hossain Mugdho
    21 November 2021
    HackerEarth nov-circuit C
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

class Trie
{
public:
    Trie *child[2];
    int m;
    vector<pii> ranges;
    Trie()
    {
        child[0] = 0;
        child[1] = 0;
        m = 0;
    }

    Trie *go(int k)
    {
        if (child[k] == 0)
            child[k] = new Trie();
        return child[k];
    }

    void push(pii x)
    {
        if (m < x.sc)
            ranges.pb(x);
        m = max(m, x.sc);
    }
};

inline void __run_test()
{
    int n, q;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
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

    int t = 0;
    vi tin(n), tout(n);
    Trie *root = new Trie();
    stack<pii> qq;
    stack<tuple<int, int, int>> qqq;
    auto dfs1 = y_combinator([&](auto self, int node, int parent, int state) -> void
                             {
                                 if (state == 0)
                                 {
                                     tin[node] = t++;
                                     qqq.push({node, parent, 1});
                                     for (auto child : adj[node])
                                         if (child != parent)
                                             qqq.push({child, node, 0});
                                 }
                                 else
                                     tout[node] = t++;
                             });
    auto dfs2 = y_combinator([&](auto self, int node, int parent) -> void
                             {
                                 Trie *now = root;
                                 rrep(i, 30)
                                 {
                                     bool child = a[node] & (1 << i);
                                     now = now->go(child);
                                     now->push({tin[node], tout[node]});
                                 }
                                 for (auto child : adj[node])
                                     if (child != parent)
                                         qq.push({child, node});
                             });
    qqq.push({0, -1, 0});
    while (gsz(qqq))
    {
        auto f = qqq.top();
        qqq.pop();
        dfs1(get<0>(f), get<1>(f), get<2>(f));
    }
    qq.push({0, -1});
    while (gsz(qq))
    {
        auto f = qq.top();
        qq.pop();
        dfs2(f.fr, f.sc);
    }

    y_combinator([&](auto self, Trie *trie) -> void
                 {
                     if (trie == 0)
                         return;
                     repe(i, gsz(trie->ranges) - 1) trie->ranges[i].sc = max(trie->ranges[i].sc, trie->ranges[i - 1].sc);
                     self(trie->child[0]);
                     self(trie->child[1]);
                 })(root);

    cin >> q;
    while (q--)
    {
        int v, x;
        cin >> v >> x;
        x--;
        Trie *now = root;
        int res = 0;
        rrep(i, 30)
        {
            bool child = v & (1 << i);
            now = now->child[child];
            if (now == 0)
                break;
            int l = 0, r = gsz(now->ranges);
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (now->ranges[mid].fr > tin[x])
                    r = mid;
                else
                    l = mid + 1;
            }
            l--;
            if (l >= 0 && now->ranges[l].sc >= tout[x])
                res = 30 - i;
        }
        cout << res + 32 << " ";
    }
    y_combinator([&](auto self, Trie *trie) -> void
                 {
                     if (trie == 0)
                         return;

                     self(trie->child[0]);
                     self(trie->child[1]);
                     delete trie;
                 })(root);
    cout << endl;
}

int main()
{
    fastio;
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/