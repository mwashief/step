/*
    11 July 2023
    Codeforces 1751-2000 1843 1843F1
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

inline void __run_test()
{
    int n;
    cin >> n;
    vector<pair<pii, pii>> val(n + 1);
    val[0] = {{1, 1}, {0, 1}};
    int stations = 1;
    auto addEdge = [&]() -> void
    {
        int v, k;
        cin >> v >> k;
        v--;
        val[stations].fr.fr = k;
        val[stations].fr.sc = k;

        val[stations].fr.fr = min(val[stations].fr.fr, val[v].fr.fr + k);
        val[stations].fr.sc = max(val[stations].fr.sc, val[v].fr.sc + k);

        val[stations].sc.fr = min(val[stations].fr.fr, val[v].sc.fr);
        val[stations].sc.sc = max(val[stations].fr.sc, val[v].sc.sc);
        stations++;
    };

    auto query = [&]() -> void
    {
        int u, v, k;
        cin >> u >> v >> k;
        u--;
        v--;
        if (val[v].sc.fr <= k && k <= val[v].sc.sc)
            pyes << endl;
        else
            pno << endl;
    };

    rep(_, n)
    {
        char c;
        cin >> c;
        if (c == '+')
            addEdge();
        else
            query();
    }
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