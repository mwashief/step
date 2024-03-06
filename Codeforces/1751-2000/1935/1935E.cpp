/*
    06 March 2024
    Codeforces 1751-2000 1935 1935E
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

template <class T, class OP>
class SegmentTree
{
    vector<T> t;
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = OP()(t[i << 1], t[i << 1 | 1]);
    }

public:
    int n;

    SegmentTree(int nn)
    {
        n = nn;
        t = vector<T>(n << 1);
    }

    SegmentTree(vector<T> v)
    {
        n = v.size();
        t = vector<T>(n << 1);
        for (int i = 0; i < n; ++i)
            t[i + n] = v[i];
        build();
    }

    void update(int p, T value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = OP()(t[p], t[p ^ 1]);
    }

    T query(int l, int r)
    {
        r++;
        T res = OP::initVal;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = OP()(res, t[l++]);
            if (r & 1)
                res = OP()(res, t[--r]);
        }
        return res;
    }
};

class Chain
{
public:
    static inline const pii initVal = {};
    pii operator()(pii x, pii y)
    {
        int res = 0;
        int intersect = (x.fr) & (y.fr | y.sc);
        if (intersect)
        {
            int bit = 31 - __builtin_clz(intersect);
            int mask = (1 << bit) - 1;
            res = mask;
        }
        intersect = (x.fr | x.sc) & (y.fr);
        if (intersect)
        {
            int bit = 31 - __builtin_clz(intersect);
            int mask = (1 << bit) - 1;
            res = max(res, mask);
        }
        return {x.fr | y.fr | res, x.sc | y.sc};
    }
};

inline void __run_test()
{
    int n;
    cin >> n;
    vpii a(n);
    SegmentTree<pii, Chain> checker(n);

    rep(j, n)
    {
        int x, y;
        cin >> x >> y;
        int c = 0;
        int chain = 0;
        rrep(i, 31)
        {
            int xBit = x & (1 << i);
            int yBit = y & (1 << i);
            if (xBit && yBit)
            {
                c |= xBit;
                x ^= xBit;
                y ^= yBit;
            }
            else if (yBit && !xBit)
            {
                chain = y;
                break;
            }
        }

        checker.update(j, {chain, c});
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        auto res = checker.query(l, r);
        cout << (res.fr | res.sc) << " ";
    }
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
-> Check simple logic errors
-> Read problem statements carefully
*/