/*
    Washief Hossain Mugdho
    25 October 2021
    Codeforces 1501-1750 1602 1602D
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

//change here
template <class T>
T OP(T a, T b)
{
    return min(a, b);
}

template <class T>
class SegmentTree
{
private:
    //change here
    void propagate(int node, T val, int nodes, int parent)
    {
        if (val < tree[node])
        {
            tree[node] = val;
            lazy[node] = parent;
        }
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
            return (T)INT32_MAX;
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;

        propagate(leftNode, tree[node], mid - l + 1, lazy[node]);
        propagate(rightNode, tree[node], r - mid, lazy[node]);

        return OP(queryUtil(leftNode, l, mid, ql, qr), queryUtil(rightNode, mid + 1, r, ql, qr));
    }

    T parent(int node, int l, int r, int ql, int qr)
    {
        //change here
        if (ql > r || qr < l)
            return (T)-1;
        if (l >= ql && r <= qr)
            return lazy[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;

        propagate(leftNode, tree[node], mid - l + 1, lazy[node]);
        propagate(rightNode, tree[node], r - mid, lazy[node]);
        return max(parent(leftNode, l, mid, ql, qr), parent(rightNode, mid + 1, r, ql, qr));
    }

    void updateUtil(int node, int l, int r, int ql, int qr, T val, int parent)
    {
        if (ql > r || qr < l)
            return;
        if (l >= ql && r <= qr)
        {
            //change here
            if (val < tree[node])
            {
                tree[node] = val;
                lazy[node] = parent;
            }
            return;
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;

        propagate(leftNode, tree[node], mid - l + 1, lazy[node]);
        propagate(rightNode, tree[node], r - mid, lazy[node]);

        updateUtil(leftNode, l, mid, ql, qr, val, parent);
        updateUtil(rightNode, mid + 1, r, ql, qr, val, parent);
    }

public:
    int n;
    vector<T> tree;
    vector<T> lazy;
    SegmentTree(int n)
    {
        this->n = n;
        tree = vector<T>(4 * n, INT32_MAX);
        lazy = vector<T>(4 * n, INT32_MAX);
        //change here
        vector<T> a(n, INT32_MAX);
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
        lazy = vector<T>(4 * n);
        build(a);
    }

    T query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    void update(int l, int r, T val, T parent)
    {
        updateUtil(0, 0, n - 1, l, r, val, parent);
    }
    T getParent(T x)
    {
        return parent(0, 0, n - 1, x, x);
    }
};

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
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1);
    repe(i, n) cin >> a[i];
    repe(i, n) cin >> b[i];

    SegmentTree<int> st(n + 1);
    st.update(n, n, 0, n);
    rrepe(i, n)
    {
        int val = st.query(i, i) + 1;
        int current = i + b[i];
        st.update(current - a[current], current, val, i);
    }
    if (st.getParent(0) == INT32_MAX)
    {
        cout << -1 << endl;
        return 0;
    }

    vi res;
    int now = 0;
    while (now != n)
    {
        res.pb(now);
        now = st.getParent(now);
    }
    cout << gsz(res) << endl;
    rrep(i, gsz(res)) cout << res[i] << " ";
    cout << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/