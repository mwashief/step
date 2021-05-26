/*
    Washief Hossain Mugdho
    15 April 2021
    Codeforces 1197 1197E
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
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
        T res;
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

class Matryoshkas
{
public:
    int wasted, howMany;
    Matryoshkas(int a, int b)
    {
        wasted = a;
        howMany = b;
    }

    Matryoshkas()
    {
        wasted = 0;
        howMany = 0;
    }
};

class Comp
{
public:
    Matryoshkas operator()(Matryoshkas x, Matryoshkas y)
    {
        Matryoshkas res;
        if (x.wasted == y.wasted)
        {
            res.wasted = x.wasted;
            res.howMany = (x.howMany + y.howMany) % MOD;
            return res;
        }
        if (x.wasted < y.wasted)
            return x;
        return y;
    }
};

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    vpii all;
    seti inset;
    cin >> n;
    all = vpii(n);
    rep(i, n)
    {
        cin >> all[i].fr >> all[i].sc;
        inset.insert(all[i].sc);
    }
    sort(all.begin(), all.end());
    SegmentTree<Matryoshkas, Comp> ss(n);
    ss.update(0, Matryoshkas(all[0].sc - all[0].fr, 1));
    repe(i, n - 1)
    {
        int l = -1;
        int r = i - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (all[mid].fr <= all[i].sc)
                l = mid;
            else
                r = mid - 1;
        }
        if (l == -1)
        {
            ss.update(i, Matryoshkas(all[i].sc - all[i].fr, 1));
            continue;
        }
        Matryoshkas now = ss.query(0, l);
        now.wasted = now.wasted + all[i].sc - all[i].fr;
        ss.update(i, now);
    }
    int wasted = INT32_MAX;
    int res = 0;
    rep(i, n)
    {
        auto f = inset.lower_bound(all[i].fr);
        if (f != inset.end())
            continue;
        Matryoshkas now = ss.query(i, i);
        now.wasted += all[i].fr;
        if (now.wasted < wasted)
        {
            wasted = now.wasted;
            res = now.howMany;
        }
        else if (now.wasted == wasted)
            res = (res + now.howMany) % MOD;
    }
    cout << res << endl;
}
