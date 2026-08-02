/*
    05 March 2024
    Codeforces 1751-2000 1935 1935C
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

template <class T>
class Max
{
public:
    static const T initVal = numeric_limits<T>::min();
    T operator()(T x, T y)
    {
        return max(x, y);
    }
};

template <class T>
class Min
{
public:
    static const T initVal = numeric_limits<T>::max();
    T operator()(T x, T y)
    {
        return min(x, y);
    }
};

template <class T>
class Add
{
public:
    static const T initVal = T(0);
    T operator()(T x, T y)
    {
        return x + y;
    }
};

inline void __run_test()
{
    int n;
    ll time;
    cin >> n >> time;
    map<int, vi> ac;
    vi as, bs;

    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        as.pb(a);
        bs.pb(b);
        ac[b].pb(a);
    }

    auto getAIndex = [&](int a) -> int
    {
        return lower_bound(a2z(as), a) - as.begin();
    };

    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    sort(bs.begin(), bs.end());
    bs.erase(unique(bs.begin(), bs.end()), bs.end());

    SegmentTree<int, Add<int>> cnt(gsz(as));
    SegmentTree<ll, Add<ll>> prefixSum(gsz(as));

    int res = 0;

    rep(i, gsz(bs))
    {
        for (int j = i; j < gsz(bs); j++)
        {
            for (auto d : ac[bs[j]])
            {
                int ind = getAIndex(d);
                cnt.update(ind, cnt.query(ind, ind) + 1);
                prefixSum.update(ind, prefixSum.query(ind, ind) + d);
            }

            ll diff = bs[j] - bs[i];
            ll extra = time - diff;

            if (extra <= 0)
                continue;

            int l = 0, r = gsz(as);
            while (l < r)
            {
                int mid = (l + r) >> 1;
                ll val = prefixSum.query(0, mid);
                if (val > extra)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l == gsz(as))
            {
                res = max(res, cnt.query(0, gsz(as) - 1));
                continue;
            }
            int taken = cnt.query(0, l);
            ll cost = prefixSum.query(0, l);
            ll extraUsage = cost - extra;

            int haveToGetRidOf = min<int>(cnt.query(l, l), (extraUsage + as[l] - 1) / as[l]);
            taken -= haveToGetRidOf;
            res = max(res, taken);
        }

        for (int j = i; j < gsz(bs); j++)
        {
            for (auto d : ac[bs[j]])
            {
                int ind = getAIndex(d);
                cnt.update(ind, 0);
                prefixSum.update(ind, 0);
            }
        }
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