/*
    Washief Hossain Mugdho
    21 May 2021
    Codeforces 1527 1527D
*/

#ifndef DEBUG
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
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005

#ifndef __INTERACTIVE__
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

inline void __run_test()
{
    int n;
    cin >> n;
    vvi adj(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi tin(n), tout(n), subtree(n), start(n);
    vl res(n + 1);
    int t = 0;
    res[0] = 1LL * n * (n - 1) / 2LL - n + 1;
    multiset<int> mlt;
    auto check = [&](pii u, pii v) -> int
    {
        if (u.fr <= v.fr && u.sc >= v.sc)
            return 0;
        if (v.fr <= u.fr && v.sc >= u.sc)
            return 1;
        if (v.sc < u.fr || u.sc < v.fr)
            return 2;
        return 3;
    };
    y_combinator([&](auto self, int node, int parent, int s) -> int
                 {
                     start[node] = s;
                     subtree[node] = 1;
                     tin[node] = t++;
                     for (auto child : adj[node])
                         if (child != parent)
                         {
                             int temp = self(child, node, node == 0 ? child : s);
                             if (node == 0)
                                 mlt.insert(temp);
                             subtree[node] += temp;
                         }
                     tout[node] = t++;
                     return subtree[node];
                 })(0, 0, 0);

    int k = subtree[start[1]];
    mlt.erase(mlt.find(k));
    ll d = 0;
    ll sum = 0;
    for (auto t : mlt)
    {
        d += 1LL * t * sum;
        sum += t;
    }
    res[0] = res[0] - d - 1LL * sum * k;

    res[1] = d + 1LL * sum * (k - subtree[1]) + (n - 1 - subtree[1]);

    pii a[] = {mp(tin[0], tout[0]),
               mp(tin[1], tout[1])};
    int b[] = {0, 1};

    int now = 2;
    bool flag = false;

    while (now < n)
    {
        auto temp = mp(tin[now], tout[now]);
        int c = check(temp, a[1]);
        if (c == 0)
        {
            now++;
        }
        else if (c == 1)
        {
            res[now] = 1LL * (n - subtree[start[now]]) * (subtree[b[1]] - subtree[now]);
            b[1] = now;
            a[1] = temp;
            now++;
        }
        else if (c == 2)
        {
            if (start[now] == start[1])
            {
                res[now] = 1LL * (n - subtree[start[now]]) * subtree[b[1]];
                now = n + 1;
                flag = true;
                break;
            }
            else
            {
                b[0] = now;
                a[0] = temp;
                res[now] = 1LL * (n - subtree[start[b[1]]] - subtree[now]) * subtree[b[1]];
                now++;
                break;
            }
        }
        else
            assert(false);
    }
    while (now < n)
    {
        auto temp = mp(tin[now], tout[now]);
        int c0 = check(temp, a[0]);
        int c1 = check(temp, a[1]);
        if (c0 == 0 || c1 == 0)
        {
            now++;
        }
        else if (c0 == 1)
        {
            res[now] = 1LL * subtree[b[1]] * (subtree[b[0]] - subtree[now]);
            b[0] = now;
            a[0] = temp;
            now++;
        }
        else if (c1 == 1)
        {
            res[now] = 1LL * subtree[b[0]] * (subtree[b[1]] - subtree[now]);
            b[1] = now;
            a[1] = temp;
            now++;
        }
        else
        {
            res[now] = 1LL * subtree[b[0]] * subtree[b[1]];
            flag = true;
            break;
        }
    }
    if (!flag)
        res[n] = 1;
    rep(i, n + 1) cout << res[i] << " ";
    cout << endl;
}

int main()
{
    fastio;
#ifndef __INTERACTIVE__
    untie;
#endif
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}