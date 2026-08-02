/*
    Washief Hossain Mugdho
    01 November 2021
    Codeforces 1501-1750 1555 1555E
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
        tree[node] += val;
        lazy[node] += val;
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
        if (lazy[node]) //change here
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = (T)0; // change here
        }
        return min(queryUtil(leftNode, l, mid, ql, qr), queryUtil(rightNode, mid + 1, r, ql, qr));
    }

    T updateUtil(int node, int l, int r, int ql, int qr, T val)
    {
        if (ql > r || qr < l)
            return tree[node];
        if (l >= ql && r <= qr)
        {
            //change here
            tree[node] = OP(tree[node], val);
            lazy[node] = OP(lazy[node], val);
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node]) //change here
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = 0; //change here
        }
        return tree[node] = min(updateUtil(leftNode, l, mid, ql, qr, val), updateUtil(rightNode, mid + 1, r, ql, qr, val));
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, pii>> segs;
    rep(i, n)
    {
        int l, r, w;
        cin >> l >> r >> w;
        l--;
        r -= 2;
        segs.pb({w, {l, r}});
    }
    sort(a2z(segs));
    vi right(n, -1);
    int l = 0, r = 1;
    SegmentTree<int> st(m - 1);
    st.update(segs[0].sc.fr, segs[0].sc.sc, 1);
    while (l < n)
    {
        if (st.query(0, m - 2) > 0)
        {
            right[l] = r - 1;
            st.update(segs[l].sc.fr, segs[l].sc.sc, -1);
            l++;
        }
        else if (r < n)
        {
            st.update(segs[r].sc.fr, segs[r].sc.sc, 1);
            r++;
        }
        else
            break;
    }
    int res = INT32_MAX;
    rep(i, n) if (right[i] != -1) res = min(res, segs[right[i]].fr - segs[i].fr);
    cout << res << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/