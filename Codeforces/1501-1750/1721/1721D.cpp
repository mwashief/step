/*
    Washief Hossain Mugdho
    06 September 2022
    Codeforces 1501-1750 1721 1721D
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

int res, n;
array<int, 100005> a, b;
vector<vector<pii>> segments;

void calc(int start, int finish, int bit)
{
    if (start > finish || bit < 0)
        return;

    int mask = 1 << bit;
    int invMask = ~mask;

    sort(a.begin() + start, a.begin() + finish + 1);
    sort(b.begin() + start, b.begin() + finish + 1, greater<int>());

    int countA = 0;
    int countB = 0;

    for (int i = start; i <= finish; i++)
    {
        bool bitA = a[i] & mask;
        bool bitB = b[i] & mask;
        countA += bitA;
        countB += bitB;

        a[i] &= invMask;
        b[i] &= invMask;
    }

    if (countA + countB == finish - start + 1)
    {
        if (bit == 0)
            return;
        segments[bit - 1].pb({start, start + countB - 1});
        segments[bit - 1].pb({start + countB, finish});
        return;
    }

    res &= invMask;
    if (bit == 0)
        return;
    segments[bit - 1].pb({start, finish});
}

inline void __run_test()
{
    cin >> n;

    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    res = (1 << 30) - 1;
    segments = vector<vector<pii>>(31);
    segments[30].pb({0, n - 1});

    rrep(i, 31)
    {
        for (auto range : segments[i])
            calc(range.fr, range.sc, i);

        if (i != 0 && (res & (1 << i)) == 0)
            segments[i - 1] = segments[i];
    }
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