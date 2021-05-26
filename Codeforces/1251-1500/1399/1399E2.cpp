/*
    Washief Hossain Mugdho
    15 May 2021
    Codeforces 1399 1399E2
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
#define MOD 1000000007 //998244353
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

inline void _()
{
    int n;
    ll s;
    cin >> n >> s;
    vi c(n);
    vi w(n);
    vi cnt(n);
    vector<vpii> adj(n);
    c[n - 1] = 1;
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v >> w[i] >> c[i];
        u--;
        v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    y_combinator([&](auto self, int node, int parent, int id) -> int
                 {
                     int res = 0;
                     for (auto child : adj[node])
                         if (child.fr != parent)
                             res += self(child.fr, node, child.sc);
                     if (res == 0)
                         res = 1;
                     if (id != -1)
                         cnt[id] = res;
                     return res;
                 })(0, 0, -1);

    ll save = 0;
    rep(i, n - 1) save += (ll)cnt[i] * w[i];
    save -= s;
    int money = 0;
    multiset<pair<ll, pii>, greater<pair<ll, pii>>> track[2];
    stack<pii> stk;
    rep(i, n) track[c[i] - 1].insert({1LL * cnt[i] * (w[i] - (w[i] >> 1)), {i, 1}});
    while (save > 0)
    {
        money++;
        auto d = track[0].begin();
        save -= d->fr;
        int name = d->sc.fr;
        int step = d->sc.sc;
        track[0].erase(d);
        track[0].insert({1LL * cnt[name] * ((w[name] >> step) - (w[name] >> (step + 1))), {name, step + 1}});
        stk.push({name, step - 1});
        while (stk.size() >= 2 && track[1].size())
        {
            auto first = stk.top();
            stk.pop();
            auto second = stk.top();
            stk.pop();
            ll costFirst = 1LL * cnt[first.fr] * ((w[first.fr] >> first.sc) - (w[first.fr] >> (first.sc + 1)));
            ll costSecond = 1LL * cnt[second.fr] * ((w[second.fr] >> second.sc) - (w[second.fr] >> (second.sc + 1)));
            if (track[1].begin()->fr > costFirst + costSecond)
            {
                ll costFirst2 = 1LL * cnt[first.fr] * ((w[first.fr] >> (first.sc + 1)) - (w[first.fr] >> (first.sc + 2)));
                ll costSecond2 = 1LL * cnt[second.fr] * ((w[second.fr] >> (second.sc + 1)) - (w[second.fr] >> (second.sc + 2)));

                track[0].erase(track[0].find({costFirst2, {first.fr, first.sc + 2}}));
                track[0].insert({costFirst, {first.fr, first.sc + 1}});
                track[0].erase(track[0].find({costSecond2, {second.fr, second.sc + 2}}));
                track[0].insert({costSecond, {second.fr, second.sc + 1}});

                auto d = track[1].begin();
                save -= d->fr;
                save += costFirst + costSecond;
                int name = d->sc.fr;
                int step = d->sc.sc;
                track[1].erase(d);
                track[1].insert({1LL * cnt[name] * ((w[name] >> step) - (w[name] >> (step + 1))), {name, step + 1}});
            }
            else
            {
                stk.push(second);
                stk.push(first);
                break;
            }
        }
    }
    cout << money << endl;
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
