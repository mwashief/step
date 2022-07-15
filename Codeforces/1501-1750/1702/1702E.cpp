/*
    Washief Hossain Mugdho
    10 July 2022
    Codeforces 1501-1750 1702 1702E
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

inline void __run_test()
{
    map<int, vi> cnt;
    int n;
    bool flag = false;
    cin >> n;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x == y)
            flag = true;
        cnt[x].pb(i);
        cnt[y].pb(i);
    }

    vvi adj(n);
    for (auto d : cnt)
        if (gsz(d.sc) > 2)
        {
            flag = true;
            break;
        }
        else if (gsz(d.sc) > 1)
        {
            adj[d.sc[0]].pb(d.sc[1]);
            adj[d.sc[1]].pb(d.sc[0]);
            // cout << d.sc[0] << " " << d.sc[1] << endl;
        }

    vi visited(n);
    rep(i, n) if (visited[i] == 0)
    {
        visited[i] = 1;
        y_combinator([&](auto self, int node) -> void
                     {
            vi to_go;
            int expect = 3 - visited[node];
            for(auto nei: adj[node]) 
                if(visited[nei] == 0)
                {
                    visited[nei] = expect;
                    to_go.pb(nei);
                }
                else if(visited[nei] != expect)
                    flag = true; 
            for(auto t: to_go) self(t); })(i);
    }

    if (flag)
        pno << endl;
    else
        pyes << endl;
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
-> Check simple logic errors
-> Read problem statements carefully
*/