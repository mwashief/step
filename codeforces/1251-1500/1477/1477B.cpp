/*
    Washief Hossain Mugdho
    07 September 2021
    Codeforces 1251-1500 1477 1477B
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
    return a + b;
}

template <class T>
class SegmentTree
{
private:
    //change here
    void propagate(int node, T val, int nodes)
    {
        tree[node] = val * (T)nodes;
        lazy[node] = val;
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
            return (T)0;
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node] != -1) //change here
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = (T)-1; // change here
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
            tree[node] = val * (r - l + 1);
            lazy[node] = val;
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node] != -1) //change here
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = -1; //change here
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
        lazy = vector<T>(4 * n, -1);
        //change here
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

inline void __run_test()
{
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    SegmentTree<int> st(n);
    rep(i, n) st.update(i, i, t[i] - '0');
    vpii queries;
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        queries.pb({l - 1, r - 1});
    }
    reverse(a2z(queries));
    for (auto query : queries)
    {
        int ones = st.query(query.fr, query.sc);
        int zeros = query.sc - query.fr - ones + 1;
        if (ones == zeros)
        {
            pno << endl;
            return;
        }
        if (ones > zeros)
            st.update(query.fr, query.sc, 1);
        else
            st.update(query.fr, query.sc, 0);
    }
    rep(i, n) if (st.query(i, i) != s[i] - '0')
    {
        pno << endl;
        return;
    }
    pyes << endl;
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