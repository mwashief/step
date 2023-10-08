/*
    07 October 2023
    Other Platforms HackerCup 2023_Round_1 D
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

class TreeNode
{
public:
    int largest0, largest1, smallest0, smallest1;
    TreeNode(int l0, int l1, int s0, int s1)
    {
        largest0 = l0;
        largest1 = l1;
        smallest0 = s0;
        smallest1 = s1;
    }
    TreeNode()
    {
        largest0 = 0;
        largest1 = -1;
        smallest0 = 0;
        smallest1 = -1;
    }

    int getVal()
    {
        int k = largest0;
        int kk = -1;
        if (smallest1 != -1)
            kk = MOD - smallest1;
        return max(k, kk);
    }
};

TreeNode tpu(TreeNode a, TreeNode b)
{
    int l0 = max(a.largest0, b.largest0);
    int l1 = max(a.largest1, b.largest1);
    int s0, s1;

    if (a.smallest0 == -1)
        s0 = b.smallest0;
    else if (b.smallest0 == -1)
        s0 = a.smallest0;
    else
        s0 = min(a.smallest0, b.smallest0);

    if (a.smallest1 == -1)
        s1 = b.smallest1;
    else if (b.smallest1 == -1)
        s1 = a.smallest1;
    else
        s1 = min(a.smallest1, b.smallest1);

    return TreeNode(l0, l1, s0, s1);
}

bool *tLPL(bool *node, bool value)
{
    if (node == 0)
    {
        node = new bool;
        *node = false;
    }

    *node = *node ^ value;
    return node;
}

TreeNode tTPL(TreeNode nodeVal, bool val, int l, int r)
{
    if (val)
    {
        int l1 = nodeVal.largest0;
        int l0 = nodeVal.largest1;
        int s0 = nodeVal.smallest1;
        int s1 = nodeVal.smallest0;
        return TreeNode(l0, l1, s0, s1);
    }
    return nodeVal;
}

template <class T, class L, T pushUp(T, T), L *LPL(L *, L), T TPL(T, L, int, int)>
class SegmentTree
{
private:
    void pushDown(int node, L val, int l, int r)
    {
        tree[node] = TPL(tree[node], val, l, r);
        lazy[node] = LPL(lazy[node], val);
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
        return tree[node] = pushUp(buildUtil(a, leftNode, l, mid), buildUtil(a, rightNode, mid + 1, r));
    }

    T queryUtil(int node, int l, int r, int ql, int qr)
    {
        // change here
        if (ql > r || qr < l)
            return INI;
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node])
        {
            pushDown(leftNode, *lazy[node], l, mid);
            pushDown(rightNode, *lazy[node], mid + 1, r);
            delete lazy[node];
            lazy[node] = 0;
        }
        return pushUp(queryUtil(leftNode, l, mid, ql, qr), queryUtil(rightNode, mid + 1, r, ql, qr));
    }

    T updateUtil(int node, int l, int r, int ql, int qr, L val)
    {
        if (ql > r || qr < l)
            return tree[node];
        if (l >= ql && r <= qr)
        {
            tree[node] = TPL(tree[node], val, l, r);
            lazy[node] = LPL(lazy[node], val);
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node])
        {
            pushDown(leftNode, *lazy[node], l, mid);
            pushDown(rightNode, *lazy[node], mid + 1, r);
            delete lazy[node];
            lazy[node] = 0;
        }
        return tree[node] = pushUp(updateUtil(leftNode, l, mid, ql, qr, val), updateUtil(rightNode, mid + 1, r, ql, qr, val));
    }

public:
    int n;
    vector<T> tree;
    vector<L *> lazy;
    T INI;
    SegmentTree(int nn, T ini)
    {
        this->n = nn;
        INI = ini;
        tree = vector<T>(4 * n, INI);
        lazy = vector<L *>(4 * n, (L *)0);
        vector<T> a(n, INI);
        build(a);
    }

    void build(vector<T> &a)
    {
        buildUtil(a, 0, 0, n - 1);
    }

    SegmentTree(vector<T> &a, T ini)
    {
        this->n = int(a.size());
        INI = ini;
        tree = vector<T>(4 * n, INI);
        lazy = vector<L *>(4 * n, (L *)0);
        build(a);
    }

    T query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    void update(int l, int r, L val)
    {
        updateUtil(0, 0, n - 1, l, r, val);
    }

    ~SegmentTree()
    {
        for (int i = 0; i < 4 * n; i++)
            if (lazy[i])
                delete lazy[i];
    }
};

inline void __run_test(int &__test_case)
{
    int n;
    cin >> n;
    vector<TreeNode> a(n);
    TreeNode ini = TreeNode(0, -1, 0, -1);
    rep(i, n)
    {
        int x;
        cin >> x;
        // e(int l0, int l1, int s0, int s1)
        a[i] = TreeNode(x, -1, x, -1);
    }
    SegmentTree<TreeNode, bool, tpu, tLPL, tTPL> st(a, ini);
    int queries;
    cin >> queries;
    ll res = 0;
    rep(_, queries)
    {
        int p, q;
        cin >> p >> q;
        st.update(p - 1, q - 1, true);
        int maxi = st.query(0, n - 1).getVal();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (st.query(0, mid).getVal() == maxi)
                r = mid;
            else
                l = mid + 1;
        }
        res += l + 1;
    }

    cout << res << endl;
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
    for (int __test_case = 1; __test_case <= __tests; __test_case++)
    {
        cout << "Case #" << __test_case << ": ";
        __run_test(__test_case);
    }
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