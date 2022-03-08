/*
    Washief Hossain Mugdho
    08 March 2022
    Codeforces 1501-1750 1650 1650E
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
    int n, d;
    cin >> n >> d;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    int spare = d - a.back();

    auto gap = [&](int x, int y) -> int
    {
        if (x < 0)
            return a[y] - 1;
        return a[y] - a[x] - 1;
    };
    multiset<int> gaps;
    rep(i, n) gaps.insert(gap(i - 1, i));

    int res = 0;

    auto fix = [&]()
    {
        // majhe vora
        int k = *gaps.rbegin();
        gaps.erase(gaps.find(k));
        int half = (k - 1) / 2;
        gaps.insert(half);
        res = max(res, *gaps.begin());

        gaps.erase(gaps.find(half));
        gaps.insert(k);

        // laste
        if (spare)
        {
            gaps.insert(spare - 1);
            res = max(res, *gaps.begin());
            gaps.erase(gaps.find(spare - 1));
        }
    };

    rep(i, n - 1)
    {
        int nijer = gap(i - 1, i);
        int porer = gap(i, i + 1);
        int beshi = gap(i - 1, i + 1);

        gaps.erase(gaps.find(nijer));
        gaps.erase(gaps.find(porer));
        gaps.insert(beshi);

        fix();

        gaps.erase(gaps.find(beshi));
        gaps.insert(nijer);
        gaps.insert(porer);
    }

    int nijer = gap(n - 2, n - 1);
    a.pop_back();
    gaps.erase(gaps.find(nijer));
    spare = d - a.back();
    fix();
    cout << res << endl;
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