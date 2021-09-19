/*
    Washief Hossain Mugdho
    17 September 2021
    Codeforces 1501-1750 1566 1566F
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
#define MAX 5000000005LL

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
class Min
{
public:
    static const T initVal = MAX;
    T operator()(T x, T y)
    {
        return min<ll>(x, y);
    }
};

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a2z(a));
    vpii temp;
    vpii segs;

    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(a2z(a), l) - a.begin();
        int right = upper_bound(a2z(a), r) - a.begin() - 1;
        if (left <= right)
            continue;
        temp.pb({l, r});
    }

    sort(a2z(temp), [&](pii a, pii b)
         {
             if (a.fr == b.fr)
                 a.sc > b.sc;
             return a.fr < b.fr;
         });

    for (auto p : temp) // eliminate super segments
    {
        while (gsz(segs) && segs.back().sc >= p.sc)
            segs.pop_back();
        segs.pb(p);
    }

    m = gsz(segs);
    if (m == 0)
    {
        cout << 0 << endl;
        return;
    }
    //immediate point left to a segment
    auto getLeft = [&](int ind) -> int
    {
        return upper_bound(a2z(a), segs[ind].fr) - a.begin() - 1;
    };

    //immediate point right to a segment
    auto getRight = [&](int ind) -> int
    {
        auto d = lower_bound(a2z(a), segs[ind].sc);
        if (d == a.end())
            return -1;
        return d - a.begin();
    };

    //immediate left segment of a point
    auto segmentAfterPoint = [&](int point)
    {
        int l = 0, r = m;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (segs[mid].fr > point)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    };

    vvl memo(m, vl(2, -1));
    SegmentTree<ll, Min<ll>> st1(m);
    SegmentTree<ll, Min<ll>> st2(m);
    auto dp = y_combinator([&](auto self, int ind, int left) -> ll
                           {
                               if (memo[ind][left] != -1)
                                   return memo[ind][left];
                               ll res = MAX;
                               if (left)
                               {
                                   int i = getLeft(ind);
                                   if (i == -1)
                                       return memo[ind][left] = MAX;
                                   int leftmost = segmentAfterPoint(a[i]);
                                   if (leftmost == 0) // point is at the beginning
                                       res = min<ll>(res, segs[ind].fr - a[i]);
                                   else
                                   {
                                       int point = getRight(leftmost - 1);

                                       int p = 0;
                                       if (point != 0)
                                           p = segmentAfterPoint(a[point - 1]);
                                       if (point == i) //shares same point
                                       {
                                           res = min<ll>(res, st1.query(p, leftmost - 1) + segs[ind].fr - a[i]);
                                           res = min<ll>(res, st2.query(p, leftmost - 1) + 2LL * (segs[ind].fr - a[i]));
                                       }
                                       else //does not share same point
                                           res = min<ll>(res, st2.query(p, leftmost - 1) + segs[ind].fr - a[i]);

                                       res = min<ll>(res, self(leftmost - 1, 1) + segs[ind].fr - a[i]);
                                   }
                               }
                               else
                               {
                                   int i = getRight(ind);
                                   if (i == -1)
                                       return memo[ind][left] = MAX;

                                   if (ind == 0)
                                       res = min<ll>(res, a[i] - segs[ind].sc);
                                   else
                                   {
                                       res = min<ll>(res, self(ind - 1, 1) + a[i] - segs[ind].sc);
                                       int point = getRight(ind - 1);
                                       if (point != i) // has a point between them
                                       {
                                           int p = 0;
                                           if (point != 0)
                                               p = segmentAfterPoint(a[point - 1]);
                                           res = min<ll>(res, st2.query(p, ind - 1) + a[i] - segs[ind].sc);
                                       }
                                   }

                                   st1.update(ind, res + a[i] - segs[ind].sc);
                                   st2.update(ind, res);
                               }
                               return memo[ind][left] = res;
                           });
    rep(i, m) dp(i, 0);
    ll res = dp(m - 1, 1);
    rrep(i, m)
    {
        if (getRight(i) == -1 || a[getRight(i)] < segs[m - 1].sc)
            break;
        res = min<ll>(res, dp(i, 0));
    }
    cout << res << endl;
}

int main()
{
    fastio;
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#endif
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}