/*
    Washief Hossain Mugdho
    22 April 2021
    Codeforces 1404 1404C
*/

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
#define MAX 1000005

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

/***************
 * 
 * For elem
 * 
 ***************/
using TType = int;
using LType = int;
TType sumPushUp(TType a, TType b)
{
    return a + b;
}

LType *sumPushDown(LType *node, LType value)
{
    if (node == 0)
        node = new LType;

    *node += value;
    return node;
}

TType sumTPL(TType nodeVal, LType val, int l, int r)
{
    return nodeVal + (TType)val * (r - l + 1);
}

/***************
 * 
 * For Min Elem
 * 
 ***************/

pair<TType, TType> elemPushUp(pair<TType, TType> a, pair<TType, TType> b)
{
    if (a.first < b.first)
        return a;
    return b;
}

LType *elemLPL(LType *node, LType value)
{
    if (node == 0)
        node = new LType;

    *node += value;
    return node;
}

pair<TType, TType> elemTPL(pair<TType, TType> nodeVal, LType val, int l, int r)
{
    nodeVal.first += (TType)val;
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
        //change here
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
    SegmentTree(int n, T ini)
    {
        this->n = n;
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

    vpii a(20);
    for (int i = 0; i < 20; i++)
    {
        a[i].fr = i;
        a[i].sc = i;
    }
    SegmentTree<pair<int, int>, int, elemPushUp, elemLPL, elemTPL> st(a, mp(INT32_MAX, 0));

    rep(i, 20)
    {
        cout << i << ": ";
        for (int j = i; j < 20; j++)
            cout << "(" << st.query(i, j).first << ", " << st.query(i, j).sc << ") ";
        cout << endl;
    }
    cout << "----------------------" << endl;
    st.update(4, 9, -20);
    rep(i, 20)
    {
        cout << i << ": ";
        for (int j = i; j < 20; j++)
            cout << "(" << st.query(i, j).fr << ", " << st.query(i, j).sc << ") ";
        cout << endl;
    }
}
