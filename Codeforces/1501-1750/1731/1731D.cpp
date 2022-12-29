/*
    27 December 2022
    Codeforces 1501-1750 1731 1731D
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

template <typename T, typename F>
struct SegmentTree2D
{
private:
    int id(int h, int w) { return h * 2 * W + w; }

public:
    int H, W;
    vector<T> seg;
    const F f;
    const T I;

    SegmentTree2D(int h, int w, F _f, const T &i) : f(_f), I(i) { init(h, w); }

    void init(int h, int w)
    {
        H = W = 1;
        while (H < h)
            H <<= 1;
        while (W < w)
            W <<= 1;
        seg.assign(4 * H * W, I);
    }

    // build にのみ呼ぶ
    void set(int h, int w, const T &x) { seg[id(h + H, w + W)] = x; }

    void build()
    {
        // w in [W, 2W)
        for (int w = W; w < 2 * W; w++)
        {
            for (int h = H - 1; h; h--)
            {
                seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
            }
        }
        // h in [0, 2H)
        for (int h = 0; h < 2 * H; h++)
        {
            for (int w = W - 1; w; w--)
            {
                seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
            }
        }
    }

    T get(int h, int w) const { return seg[id(h + H, w + W)]; }
    T operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

    void update(int h, int w, const T &x)
    {
        h += H, w += W;
        seg[id(h, w)] = x;
        for (int i = h >> 1; i; i >>= 1)
        {
            seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
        }
        for (; h; h >>= 1)
        {
            for (int j = w >> 1; j; j >>= 1)
            {
                seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
            }
        }
    }

    T _inner_query(int h, int w1, int w2)
    {
        T res = I;
        for (; w1 < w2; w1 >>= 1, w2 >>= 1)
        {
            if (w1 & 1)
                res = f(res, seg[id(h, w1)]), w1++;
            if (w2 & 1)
                --w2, res = f(res, seg[id(h, w2)]);
        }
        return res;
    }

    // [ (h1,w1), (h2,w2) ) 半開
    T query(int h1, int w1, int h2, int w2)
    {
        if (h1 >= h2 || w1 >= w2)
            return I;
        T res = I;
        h1 += H, h2 += H, w1 += W, w2 += W;
        for (; h1 < h2; h1 >>= 1, h2 >>= 1)
        {
            if (h1 & 1)
                res = f(res, _inner_query(h1, w1, w2)), h1++;
            if (h2 & 1)
                --h2, res = f(res, _inner_query(h2, w1, w2));
        }
        return res;
    }
};

/**
 * @brief 二次元セグメント木
 * @docs docs/data-structure-2d/2d-segment-tree.md
 */
int mini(int a, int b)
{
    return min(a, b);
}

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    int d = INT32_MAX;
    auto test = [&](int a, int b) -> int
    {
        return min(a, b);
    };
    SegmentTree2D<int, decltype(test)> seg(n, m, test, d);
    rep(i, n) rep(j, m)
    {
        int x;
        cin >> x;
        seg.set(i, j, x);
    }
    seg.build();
    int l = 1, r = min(n, m);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        bool found = false;
        rep(i, n - mid + 1) rep(j, m - mid + 1) if (seg.query(i, j, i + mid, j + mid) >= mid)
        {
            l = mid;
            found = true;
            break;
        }

        if (found)
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
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