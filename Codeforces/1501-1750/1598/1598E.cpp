/*
    Washief Hossain Mugdho
    21 October 2021
    Codeforces 1501-1750 1598 1598E
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

class Stair
{
public:
    int left = 0, right = 0, len = 1;
    ll internal = 0;
    Stair() {}
    Stair(bool x)
    {
        left = (int)x;
        right = (int)x;
    }
    Stair operator+(Stair y)
    {
        Stair res;
        Stair x = *this;
        res.internal = x.internal + y.internal;
        res.len = x.len + y.len;
        if (x.left == x.len)
            res.left = y.left + x.left;
        else
            res.left = x.left;
        if (y.right == y.len)
            res.right = y.right + x.right;
        else
            res.right = y.right;
        if (x.len != x.left && y.len != y.right)
        {
            ll temp = x.right + y.left;
            res.internal += temp * (temp + 1) / 2LL;
        }
        return res;
    }
};

//change here
template <class T>
T OP(T a, T b)
{
    return a + b;
}

template <class T>
class SegmentTree
{
private:
    //change here

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
        {
            Stair s;
            s.len = 0;
            return s;
        }
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;

        return OP(queryUtil(leftNode, l, mid, ql, qr), queryUtil(rightNode, mid + 1, r, ql, qr));
    }

    T updateUtil(int node, int l, int r, int ql, T val)
    {
        if (ql > r || ql < l)
            return tree[node];
        if (l >= ql && r <= ql)
        {

            tree[node] = val;

            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;

        return tree[node] = OP(updateUtil(leftNode, l, mid, ql, val), updateUtil(rightNode, mid + 1, r, ql, val));
    }

public:
    int n;
    vector<T> tree;

    SegmentTree(int n)
    {
        this->n = n;
        tree = vector<T>(4 * n);

        vector<T> a(n);
        build(a);
    }

    void build(vector<T> &a)
    {
        buildUtil(a, 0, 0, n - 1);
    }

    SegmentTree(vector<T> &a)
    {
        this->n = a.size();
        tree = vector<T>(4 * n);

        build(a);
    }

    T query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    void update(int l, T val)
    {
        updateUtil(0, 0, n - 1, l, val);
    }
};

int dr[] = {1, 0};
int dc[] = {0, 1};

ll getVal(Stair s)
{
    if (s.len == s.left)
        return 1LL * s.left * (s.left + 1) / 2LL;
    ll extra = 1LL * s.left * (s.left + 1) / 2LL + 1LL * s.right * (s.right + 1) / 2LL;
    return s.internal + extra;
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
    int n, m, q;
    cin >> n >> m >> q;
    vvi inStair(n * m);
    vvi stairs;
    int segs = 0;

    auto traverse = [&](int r, int c, int step)
    {
        while (r >= 0 && r < n && c >= 0 && c < m)
        {
            int id = m * r + c;
            stairs.back().pb(id);
            inStair[id].pb(segs);
            r = r + dr[step];
            c = c + dc[step];
            step = 1 - step;
        }
    };
    stairs.pb(vi());
    traverse(0, 0, 0);
    segs++;
    stairs.pb(vi());
    traverse(0, 0, 1);
    segs++;
    repe(i, n - 1)
    {
        stairs.pb(vi());
        traverse(i, 0, 0);
        segs++;
    }
    repe(i, m - 1)
    {
        stairs.pb(vi());
        traverse(0, i, 1);
        segs++;
    }

    ll ans = 0LL;
    ll blacks = 0LL;
    vvb mat(n, vb(m));
    vector<SegmentTree<Stair>> maintain;
    for (auto stair : stairs)
        maintain.pb(SegmentTree<Stair>(gsz(stair)));

    auto update = [&](int r, int c)
    {
        int id = r * m + c;
        for (auto s : inStair[id])
        {
            int index = lower_bound(a2z(stairs[s]), id) - stairs[s].begin();
            ans -= getVal(maintain[s].query(0, gsz(stairs[s]) - 1));
            if (mat[r][c])
                maintain[s].update(index, Stair(false));
            else
                maintain[s].update(index, Stair(true));

            ans += getVal(maintain[s].query(0, gsz(stairs[s]) - 1));
        }
        if (mat[r][c])
        {
            blacks--;
            mat[r][c] = false;
        }
        else
        {
            blacks++;
            mat[r][c] = true;
        }
    };
    rep(i, n) rep(j, m) update(i, j);

    while (q--)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        update(r, c);
        cout << ans - blacks << endl;
    }
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/