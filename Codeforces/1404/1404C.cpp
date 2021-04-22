/*
    Washief Hossain Mugdho
    22 April 2021
    Codeforces 1404 1404C
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000000005

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

//change here
template <class T>
T OP(T a, T b)
{
    if (a.fr > b.fr)
        return b;
    if (a.fr == b.fr && b.sc > a.sc)
        return b;
    return a;
}

template <class T>
class SegmentTree
{
private:
    //change here
    void propagate(int node, T val, int nodes)
    {
        tree[node].fr += val.fr;
        lazy[node].fr += val.fr;
    }

    T buildUtil(vector<T> &a, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = a[l];
            return tree[node];
        }
        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        return tree[node] = OP(buildUtil(a, leftNode, l, mid), buildUtil(a, rightNode, mid + 1, r));
    }

    T queryUtil(int node, int l, int r, int ql, int qr)
    {
        //change here
        if (ql > r || qr < l)
            return (T)mp(MAX, -1);
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node].fr)
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            //change here
            lazy[node].fr = 0;
        }
        return OP(queryUtil(leftNode, l, mid, ql, qr), queryUtil(rightNode, mid + 1, r, ql, qr));
    }

    T updateUtil(int node, int l, int r, int ql, int qr, T val)
    {
        if (ql > r || qr < l)
            return tree[node];
        if (l >= ql && r <= qr)
        {
            //change here
            tree[node].fr += val.fr;
            lazy[node].fr += val.fr;
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node].fr)
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node].fr = 0;
        }
        return tree[node] = OP(updateUtil(leftNode, l, mid, ql, qr, val), updateUtil(rightNode, mid + 1, r, ql, qr, val));
    }

public:
    int n;
    vector<T> tree;
    vector<T> lazy;
    SegmentTree(int n)
    {
        this->n = n;
        tree = vector<T>(4 * n);
        lazy = vector<T>(4 * n);
    }

    void build(vector<T> &a)
    {
        buildUtil(a, 0, 0, n - 1);
    }

    SegmentTree(vector<T> &a)
    {
        this->n = a.size();
        tree = vector<T>(4 * n);
        lazy = vector<T>(4 * n);
        build(a);
    }

    T query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    void update(int l, int r, T val)
    {
        updateUtil(0, 0, n - 1, l, r, val);
    }
};

template <class T, class OP>
class FST
{
    vector<T> t;
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = OP()(t[i << 1], t[i << 1 | 1]);
    }

public:
    int n;

    FST(int nn)
    {
        n = nn;
        t = vector<T>(n << 1);
    }

    FST(vector<T> v)
    {
        n = v.size();
        t = vector<T>(n << 1);
        for (int i = 0; i < n; ++i)
            t[i + n] = v[i];
        build();
    }

    void update(int p, T value)
    {
        value += query(p, p);
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
class Add
{
public:
    static const T initVal = T(0);
    T operator()(T x, T y)
    {
        return x + y;
    }
};
int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n, q;
    cin >> n >> q;
    vpii a(n);
    rep(i, n)
    {
        cin >> a[i].fr;
        a[i].sc = i + 1;
        a[i].fr = a[i].sc - a[i].fr;
        if (a[i].fr < 0)
            a[i].fr = MAX;
    }
    SegmentTree<pii> st(a);
    vi seq(n, -1);
    vi taken(n);
    int parent = n;
    while (1)
    {
        auto d = st.query(0, n - 1);
        if (d.fr != 0)
            break;
        seq[d.sc - 1] = parent;
        parent = min(parent, d.sc - 1);
        taken[d.sc - 1] = 1;
        st.update(d.sc - 1, n - 1, {-1, 0});
        st.update(d.sc - 1, d.sc - 1, {MAX + 1, 0});
    }
    FST<int, Add<int>> track(n + 3);
    vector<pair<pii, pii>> queries;

    rep(qq, q)
    {
        int x, y;
        cin >> x >> y;
        int l = x;
        int r = n - 1 - y;
        queries.pb({{l, r}, {qq, 0}});
    }
    int sq = (int)sqrt(q);

    sort(a2z(queries), [=](pair<pii, pii> x, pair<pii, pii> y) -> bool {
        int blockX = x.fr.fr / sq;
        int blockY = y.fr.fr / sq;
        if (blockX < blockY)
            return true;
        if (blockX == blockY)
            return (blockX & 1) ^ (x.fr.sc < y.fr.sc);
        return false;
    });
    int l = 0, r = 0;
    if (seq[0] != -1)
        track.update(seq[0], 1);
    for (pair<pii, pii> &qq : queries)
    {
        int x = qq.fr.fr;
        int y = qq.fr.sc;
        while (l < x)
        {
            int d = seq[l];
            l++;
            if (d != -1)
                track.update(d, -1);
        }
        while (l > x)
        {
            int d = seq[l - 1];
            l--;
            if (d != -1)
                track.update(d, 1);
        }
        while (r < y)
        {
            int d = seq[r + 1];
            r++;
            if (d != -1)
                track.update(d, 1);
        }
        while (r > y)
        {
            int d = seq[r];
            r--;
            if (d != -1)
                track.update(d, -1);
        }
        int temp = 0;
        if (x != 0)
            temp = track.query(0, x - 1);
        qq.sc.sc = track.query(0, n + 1) - temp;
    }

    sort(a2z(queries), [=](pair<pii, pii> x, pair<pii, pii> y) -> bool {
        return x.sc.fr < y.sc.fr;
    });
    for (auto qq : queries)
        cout << qq.sc.sc << endl;
}