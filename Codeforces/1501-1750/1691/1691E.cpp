/*
    Washief Hossain Mugdho
    05 June 2022
    Codeforces 1501-1750 1691 1691E
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

class DSU
{
public:
    int n;
    std::vector<int> parent, subsetSize;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        subsetSize = std::vector<int>(numberOfElements, 1);
        std::iota(parent.begin(), parent.end(), 0);
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

    bool join(int subset1, int subset2)
    {
        if (isConnected(subset1, subset2))
            return false;
        subset1 = getRepresentative(subset1);
        subset2 = getRepresentative(subset2);
        if (subsetSize[subset1] < subsetSize[subset2])
            swap(subset1, subset2);
        subsetSize[subset1] += subsetSize[subset2];
        parent[subset2] = subset1;
        return true;
    }
};

class SegmentTree
{
private:
    void updateUtil(int node, int l, int r, int ql, int qr, int segNo, int color)
    {
        if (ql > r || qr < l)
            return;
        if (l >= ql && r <= qr)
        {
            tree[color][node].push_back(segNo);
            return;
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        updateUtil(leftNode, l, mid, ql, qr, segNo, color);
        updateUtil(rightNode, mid + 1, r, ql, qr, segNo, color);
    }

public:
    void merge(int node, int l, int r, DSU &dsu)
    {
        if (tree[0][node].size() && tree[1][node].size())
        {
            dsu.join(*tree[0][node].begin(), *tree[1][node].begin());
            for (auto d : tree[0][node])
                dsu.join(*tree[0][node].begin(), d);
            for (auto d : tree[1][node])
                dsu.join(*tree[1][node].begin(), d);
            while (tree[0][node].size() > 1)
                tree[0][node].pop_back();
            while (tree[1][node].size() > 1)
                tree[1][node].pop_back();
        }
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        merge(leftNode, l, mid, dsu);
        merge(rightNode, mid + 1, r, dsu);
        vi childNode = {leftNode, rightNode};
        rep(i, 2) if (tree[1 - i][node].size()) for (auto cNode : childNode) if (tree[i][cNode].size())
        {
            for (auto d : tree[i][cNode])
                dsu.join(d, *tree[i][cNode].begin());
            dsu.join(*tree[i][cNode].begin(), *tree[1 - i][node].begin());
            for (auto d : tree[1 - i][node])
                dsu.join(d, *tree[1 - i][node].begin());
            while (tree[1 - i][node].size() > 1)
                tree[1 - i][node].pop_back();
            while (tree[i][cNode].size() > 1)
                tree[i][cNode].pop_back();
        }
        rep(i, 2) for (auto child : childNode)
        {
            tree[i][node].splice(tree[i][node].end(), tree[i][child]);
        }
    }

    void print(int node, int l, int r)
    {
        for (auto d : tree[0][node])
            cout << "(" << l << ", " << r << ") - " << node << " " << d << " 0" << endl;
        for (auto d : tree[1][node])
            cout << "(" << l << ", " << r << ") - " << node << " " << d << " 1" << endl;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        /*
        cout << "(" << l << "," << r << ") "
             << "(" << l << "," << mid << ")" << endl;
        cout << "(" << l << "," << r << ") "
             << "(" << mid + 1 << "," << r << ")" << endl;
             */
        print(leftNode, l, mid);
        print(rightNode, mid + 1, r);
    }

    int n;
    vector<list<int>> tree[2];
    SegmentTree(int n)
    {
        this->n = n;
        tree[0] = vector<list<int>>(4 * n);
        tree[1] = vector<list<int>>(4 * n);
    }

    void update(int l, int r, int segNo, int color)
    {
        updateUtil(0, 0, n - 1, l, r, segNo, color);
    }
};

inline void __run_test()
{
    int n;
    cin >> n;
    vector<pair<int, pii>> a(n);
    vi all;
    rep(i, n)
    {
        cin >> a[i].fr >> a[i].sc.fr >> a[i].sc.sc;
        all.pb(a[i].sc.fr);
        all.pb(a[i].sc.sc);
    }
    sort(a2z(all));
    all.erase(unique(all.begin(), all.end()), all.end());
    SegmentTree st(2 * n);
    rep(i, n)
    {
        a[i].sc.fr = lower_bound(a2z(all), a[i].sc.fr) - all.begin();
        a[i].sc.sc = lower_bound(a2z(all), a[i].sc.sc) - all.begin();
        st.update(a[i].sc.fr, a[i].sc.sc, i, a[i].fr);
    }
    DSU dsu(n);
    st.merge(0, 0, 2 * n - 1, dsu);
    // st.print(0, 0, 2 * n - 1);
    seti s;
    rep(i, n) s.insert(dsu.getRepresentative(i));
    cout << gsz(s) << endl;
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