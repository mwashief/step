/*
    Washief Hossain Mugdho
    26 May 2021
    Codeforces 1527 1527E
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#define __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 10000005

#undef __INTERACTIVE__

#ifdef __INTERACTIVE__
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
            return (T)MAX;
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node])
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = 0;
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
            tree[node] += val;
            lazy[node] += val;
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node])
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = 0;
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

int main()
{
    fastio;
#ifndef __INTERACTIVE__
    untie;
#endif
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vi a(n), last(n);
    rep(i, n) cin >> a[i];
    vvi memo(k + 1, vi(n));
    umii track;
    track[a[0]] = 0;
    repe(i, n - 1)
    {
        memo[1][i] = memo[1][i - 1];
        if (track.find(a[i]) != track.end())
        {
            last[i] = track[a[i]];
            memo[1][i] += i - last[i];
        }
        else
            last[i] = i;
        track[a[i]] = i;
    }

    for (int i = 2; i <= k; i++)
    {
        SegmentTree<int> st(memo[i - 1]);
        for (int j = 0; j < n; j++)
        {
            if (j < i - 1)
                memo[i][j] = MAX;
            else
            {
                int extra = j - last[j];
                st.update(0, last[j] - 1, j - last[j]);
                memo[i][j] = st.query(0, j - 1);
            }
        }
    }
    cout << memo[k][n - 1] << endl;
}