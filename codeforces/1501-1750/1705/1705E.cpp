/*
    Washief Hossain Mugdho
    17 July 2022
    Codeforces 1501-1750 1705 1705E
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
#define MAX 200030

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
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) cin >> a[i];
    set<pii> segments;

    auto find = [&](int k)
    {
        auto it = segments.lower_bound({k + 1, 0});
        if (it == segments.begin())
            return segments.end();
        it--;
        if (it->fr <= k && it->sc >= k)
            return it;
        return segments.end();
    };

    auto print = [&]() -> void
    {
        for (auto seg : segments)
            cout << "(" << seg.fr << ", " << seg.sc << ") ";
        cout << endl;
    };

    auto insert = y_combinator([&](auto self, int k) -> void
                               {
                                   auto it = find(k);
                                   if (it != segments.end())
                                   {
                                       auto d = *it;
                                       segments.erase(it);
                                       if (d.fr < k)
                                           segments.insert({d.fr, k - 1});
                                       self(d.sc + 1);
                                       return;
                                   }
                                   auto it1 = find(k - 1);
                                   auto it2 = find(k + 1);
                                   if(it1 != segments.end() && it2 != segments.end())
                                   {
                                        int l= it1->fr;
                                        int r = it2->sc;
                                        segments.erase(it1);
                                        segments.erase(it2);
                                        segments.insert({l, r});
                                   }
                                   else if(it1 != segments.end())
                                   {
                                         int l= it1->fr;
                                        int r = it1->sc + 1;
                                        segments.erase(it1);
                                        segments.insert({l, r});
                                   }
                                   else if(it2 != segments.end())
                                   {
                                         int l= it2->fr-1;
                                        int r = it2->sc;
                                        segments.erase(it2);
                                        segments.insert({l, r});
                                   }
                                   else segments.insert({k, k}); });

    auto erase = [&](int k) -> void
    {
        auto it = find(k);
        if (it != segments.end())
        {
            auto d = *it;
            segments.erase(it);
            if (d.fr < k)
                segments.insert({d.fr, k - 1});
            if (k < d.sc)
                segments.insert({k + 1, d.sc});
        }
        else
        {
            auto it1 = segments.lower_bound({k + 1, 0});
            auto d = *it1;
            segments.erase(it1);
            segments.insert({k, d.fr - 1});
            if (d.fr != d.sc)
                segments.insert({d.fr + 1, d.sc});
        }
    };

    rep(i, n) insert(a[i]);
    while (q--)
    {
        int k, l;
        cin >> k >> l;
        if (a[k - 1] != l)
        {
            erase(a[k - 1]);
            insert(l);
            a[k - 1] = l;
        }
        cout << segments.rbegin()->sc << endl;
        // print();
    }
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