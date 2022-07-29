/*
    Washief Hossain Mugdho
    29 July 2022
    Codeforces 1501-1750 1706 1706E
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
    static const T initVal = 0;
    T operator()(T x, T y)
    {
        return max(x, y);
    }
};

class SegSet
{
public:
    map<int, int> forward, backward;

    SegSet() {}

    SegSet(int point)
    {
        insert(point, point);
    };

    void insert(int l, int r)
    {
        forward[l] = r;
        backward[r] = l;
    }

    void erase(int l, int r)
    {
        forward.erase(l);
        backward.erase(r);
    }

    void erase(pair<int, int> seg)
    {
        erase(seg.first, seg.second);
    }

    int size()
    {
        return (int)forward.size();
    }

    void merge(SegSet &rhs, SegmentTree<int, Max<int>> &st, int val)
    {
        while (rhs.size())
        {
            auto [l, r] = *rhs.forward.begin();
            rhs.erase(l, r);
            if (backward.count(l - 1))
            {
                int left = backward[l - 1];
                erase(left, l - 1);
                rhs.insert(left, r);
                st.update(l - 1, val);
            }
            else if (forward.count(r + 1))
            {
                int right = forward[r + 1];
                erase(r + 1, right);
                insert(l, right);
                st.update(r, val);
            }
            else
                insert(l, r);
        }
    }
};

class DSU
{
public:
    int n;
    std::vector<int> parent;
    std::vector<SegSet> segsets;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        std::iota(parent.begin(), parent.end(), 0);
        rep(i, n) segsets.pb(SegSet(i));
    }

    int getRepresentative(int subset)
    {
        if (parent[subset] == subset)
            return subset;
        return parent[subset] = getRepresentative(parent[subset]);
    }

    bool isConnected(int subset1, int subset2)
    {
        return getRepresentative(subset1) == getRepresentative(subset2);
    }

    bool join(int subset1, int subset2, SegmentTree<int, Max<int>> &st, int val)
    {
        if (isConnected(subset1, subset2))
            return false;
        subset1 = getRepresentative(subset1);
        subset2 = getRepresentative(subset2);
        if (segsets[subset1].size() < segsets[subset2].size())
            swap(subset1, subset2);
        segsets[subset1].merge(segsets[subset2], st, val);
        parent[subset2] = subset1;
        return true;
    }
};

inline void __run_test()
{
    int n, m, q;
    cin >> n >> m >> q;

    SegmentTree<int, Max<int>> st(n);
    DSU dsu(n);

    repe(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dsu.join(u, v, st, i);
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << st.query(u, v - 1) << " ";
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