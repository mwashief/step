/*
    Washief Hossain Mugdho
    25 May 2021
    Codeforces 1528 1528C
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
    vvi a(n), b(n);
    repe(i, n - 1)
    {
        int x;
        cin >> x;
        a[x - 1].pb(i);
    }
    repe(i, n - 1)
    {
        int x;
        cin >> x;
        b[x - 1].pb(i);
    }
    vi tin(n), tout(n);
    int t = 0;
    y_combinator([&](auto self, int node, int parent) -> void
                 {
                     tin[node] = t++;
                     for (auto child : b[node])
                         if (child != parent)
                             self(child, node);
                     tout[node] = t++;
                 })(0, 0);
    int res = 0;
    set<pii> track;
    y_combinator([&](auto self, int node, int parent) -> void
                 {
                     pii inserted(-1, -1), deleted(-1, -1);
                     if (track.size() == 0)
                     {
                         inserted = {tin[node], node};
                         track.insert(inserted);
                     }
                     else
                     {
                         auto d = track.lower_bound(mp(tin[node], node));
                         if (d == track.begin())
                         {
                             if (tout[node] < d->fr)
                             {
                                 inserted = {tin[node], node};
                                 track.insert(inserted);
                             }
                         }
                         else if (d == track.end() || d->fr > tout[node])
                         {
                             d--;
                             inserted = {tin[node], node};
                             track.insert(inserted);
                             if (tout[d->sc] > tout[node])
                             {
                                 deleted = *d;
                                 track.erase(d);
                             }
                         }
                     }
                     if (a[node].size() == 0)
                         res = max(res, gsz(track));
                     for (auto child : a[node])
                         if (child != parent)
                             self(child, node);

                     if (deleted.fr != -1)
                         track.insert(deleted);
                     if (inserted.fr != -1)
                         track.erase(inserted);
                 })(0, 0);
    cout << res << endl;
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