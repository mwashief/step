/*
    Washief Hossain Mugdho
    04 January 2022
    Codeforces 1501-1750 1621 1621E
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
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a2z(a), greater<int>());
    a.resize(m);
    reverse(a2z(a));
    vl sum(m);
    vi k(m);
    vvi all(m);
    rep(i, m)
    {
        cin >> k[i];
        rep(j, k[i])
        {
            int x;
            cin >> x;
            all[i].pb(x);
            sum[i] += x;
        }
    }
    n = m;
    vi order(m);
    iota(a2z(order), 0);
    sort(a2z(order), [&](int x, int y) -> bool
         { return 1LL * sum[x] * k[y] < sum[y] * k[x]; });
    vi ran(m);
    rep(i, m)
    {
        int l = -1, r = m - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            int group = order[mid];
            if (sum[group] <= 1LL * a[i] * k[group])
                l = mid;
            else
                r = mid - 1;
        }
        ran[i] = l - i;
    }
    SegmentTree<int, Min<int>> st(ran);
    vvi res(m);
    rep(i, m) res[i] = vi(k[i], 0);
    rep(i, m)
    {
        int group = order[i];
        int current = i;
        for (int j = 0; j < gsz(all[group]); j++)
        {
            ll newsum = sum[group] - all[group][j];
            int newk = k[group] - 1;
            if (newk == 0)
                res[group][j] = int(st.query(1, n - 1) >= -1);
            else
            {
                int l = -1, r = n - 1;
                while (l < r)
                {
                    int mid = (l + r + 1) >> 1;
                    int g = order[mid];
                    if (1LL * sum[g] * newk < 1LL * newsum * k[g])
                        l = mid;
                    else
                        r = mid - 1;
                }
                int newi;
                if (l >= i)
                {
                    newi = l;
                    bool d = true;
                    if (i > 0)
                        d = st.query(0, i - 1) >= 0;
                    if (newi < m - 1)
                        d &= (st.query(newi + 1, m - 1) >= 0);
                    res[group][j] = d & (st.query(i, newi - 1) >= 1) & (1LL * newk * a[newi] >= newsum);
                }
                else
                {
                    newi = l + 1;
                    bool d = true;
                    if (newi > 0)
                        d = st.query(0, newi - 1) >= 0;
                    if (i < m - 1)
                        d &= (st.query(i + 1, m - 1) >= 0);
                    res[group][j] = d & (st.query(newi + 1, i) >= -1) & (1LL * newk * a[newi] >= newsum);
                }
            }
        }
    }
    rep(i, m) rep(j, k[i]) cout << res[i][j];
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