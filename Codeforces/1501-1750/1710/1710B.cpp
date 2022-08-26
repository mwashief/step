/*
    Washief Hossain Mugdho
    26 August 2022
    Codeforces 1501-1750 1710 1710B
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
    static const T initVal = numeric_limits<T>::min() / 2;
    ;
    T operator()(T x, T y)
    {
        return max(x, y);
    }
};

inline void __run_test()
{
    int n;
    ll m;
    cin >> n >> m;

    vector<pair<pii, int>> a(n);
    string result(n, '1');

    rep(i, n)
    {
        cin >> a[i].fr.fr >> a[i].fr.sc;
        a[i].sc = i;
    }

    sort(a2z(a));

    auto getRight = [&](int index) -> int
    {
        int l = index, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid].fr.fr <= a[index].fr.fr + a[index].fr.sc)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    };

    auto getLeft = [&](int index) -> int
    {
        int l = -1, r = index;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid].fr.fr <= a[index].fr.fr - a[index].fr.sc)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    };

    vl normal(n);
    ll sum = 0;
    ll contributing = 0;
    int last = 0;
    mii ends;

    rep(i, n)
    {
        int x = a[i].fr.fr;
        int p = a[i].fr.sc;

        while (ends.size() && ends.begin()->fr <= x)
        {
            sum -= 1LL * (ends.begin()->fr - last) * ends.begin()->sc;
            contributing -= ends.begin()->sc;
            ends.erase(ends.begin());
        }

        normal[i] = p + sum - (x - last) * contributing;
        sum -= (x - last) * contributing;
        contributing++;
        sum += p;
        last = x;
        ends[x + p]++;
    }

    sum = 0;
    contributing = 0;
    last = 0;
    map<int, int, greater<int>> starts;

    rrep(i, n)
    {
        int x = a[i].fr.fr;
        int p = a[i].fr.sc;

        while (starts.size() && starts.begin()->fr >= x)
        {
            sum -= 1LL * (-starts.begin()->fr + last) * starts.begin()->sc;
            contributing -= starts.begin()->sc;
            starts.erase(starts.begin());
        }

        normal[i] += sum - 1LL * (last - x) * contributing;
        sum -= 1LL * (last - x) * contributing;
        contributing++;
        sum += p;
        last = x;
        starts[x - p]++;
    }

    vl toRight = normal;
    vl toLeft = normal;

    rep(i, n)
    {
        toRight[i] += a[i].fr.fr;
        toLeft[i] -= a[i].fr.fr;
    }

    SegmentTree<ll, Max<ll>> N(normal), R(toRight), L(toLeft);

    rep(i, n)
    {
        int x = a[i].fr.fr;
        int p = a[i].fr.sc;
        int ind = a[i].sc;
        int l = getLeft(i);
        int r = getRight(i);
        ll res = max({0LL, N.query(r, n - 1), N.query(0, l), R.query(i, r - 1) - x - p, L.query(l + 1, i) - p + x});

        if (res > m)
            result[ind] = '0';
    }

    cout << result << endl;
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