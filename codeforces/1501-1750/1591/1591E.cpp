/*
    Washief Hossain Mugdho
    13 December 2021
    Codeforces 1501-1750 1591 1591E
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
// https://codeforces.com/problemset/problem/1591/E
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

mii koyta;
vi ran;

void dec(int k)
{
    if (k == 1)
    {
        ran.pop_back();
        return;
    }
    int l = 0, r = gsz(ran) - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (ran[mid] >= k)
            l = mid;
        else
            r = mid - 1;
    }
    ran[r]--;
}

void inc(int k)
{
    if (k == 0)
    {
        ran.pb(1);
        return;
    }
    int l = 0, r = gsz(ran) - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (ran[mid] <= k)
            r = mid;
        else
            l = mid + 1;
    }
    ran[r]++;
}

int getRes(int m, int k)
{
    ran.pb(0);
    int l = -1, r = gsz(ran) - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (ran[mid] >= m)
            l = mid + 1;
        else
            r = mid;
    }
    ran.pop_back();
    l--;
    if (k > l + 1)
        return -1;
    return ran[l - k + 1];
}

inline void __run_test()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi adj(n);
    repe(i, n - 1)
    {
        int x;
        cin >> x;
        x--;
        adj[x].pb(i);
    }
    vi res(q);
    vector<vector<tuple<int, int, int>>> queries(n);
    rep(i, q)
    {
        tuple<int, int, int> d;
        int v;
        cin >> v >> get<0>(d) >> get<1>(d);
        get<2>(d) = i;
        v--;
        queries[v].pb(d);
    }

    vector<seti> ulta(n + 1);
    y_combinator([&](auto self, int node) -> void
                 {
                     int d = 0;
                     int k = a[node];
                     if (koyta.find(k) != koyta.end())
                         d = koyta[k];
                     if (d)
                         ulta[d].erase(k);
                     koyta[k]++;
                     ulta[d + 1].insert(k);
                     inc(d);
                     for (auto c : queries[node])
                     {
                         int l = get<0>(c);
                         int k = get<1>(c);
                         int qq = get<2>(c);
                         int temp = getRes(l, k);
                         if (temp == -1)
                             res[qq] = temp;
                         else
                             res[qq] = *ulta[temp].begin();
                     }
                     for (auto child : adj[node])
                         self(child);

                     koyta[k]--;
                     if (koyta[k] == 0)
                         koyta.erase(k);
                     ulta[d + 1].erase(k);
                     if (d)
                         ulta[d].insert(k);
                     dec(d + 1);
                 })(0);

    rep(i, q) cout << res[i] << " ";
    cout << endl;
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
*/