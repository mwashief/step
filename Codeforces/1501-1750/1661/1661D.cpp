/*
    Washief Hossain Mugdho
    10 April 2022
    Codeforces 1501-1750 1661 1661D
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
#define MAX 1200100

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

// @Search segment tree, single query, range update

int n, k;

ll tree1[MAX];
ll tree2[MAX];

void push_down(int node, ll val1, ll val2)
{
    tree1[node] += val1;
    tree2[node] += val2;
}

void update(int node, int ql, int qr, int l, int r, ll val)
{
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr)
    {
        tree1[node] += val;
        tree2[node] += val * (l - ql);
        return;
    }
    int mid = (l + r) >> 1;
    int leftNode = node * 2 + 1;
    int rightNode = node * 2 + 2;
    update(leftNode, ql, qr, l, mid, val);
    update(rightNode, ql, qr, mid + 1, r, val);
}

ll query(int node, int ind, int l, int r)
{
    if (l == ind && ind == r)
    {
        return tree1[node] + tree2[node];
    }
    int mid = (l + r) >> 1;
    int leftNode = node * 2 + 1;
    int rightNode = node * 2 + 2;
    push_down(leftNode, tree1[node], tree2[node]);
    push_down(rightNode, tree1[node], tree1[node] * (mid - l + 1) + tree2[node]);
    tree1[node] = 0;
    tree2[node] = 0;
    if (ind <= mid)
        return query(leftNode, ind, l, mid);
    return query(rightNode, ind, mid + 1, r);
}

void print()
{
    return;
    rep(i, n) cout << query(0, i, 0, n - 1) << " ";
    cout << endl;
}

inline void __run_test()
{
    cin >> n >> k;
    vl b(n);
    ll res = 0;

    rep(i, n) cin >> b[i];
    for (int i = n - 1; i >= k - 1; i--)
    {
        ll extra = b[i] - query(0, i, 0, n - 1);
        if (extra > 0)
        {
            ll howMany = (extra + k - 1) / k;
            res += howMany;
            update(0, i - k + 1, i, 0, n - 1, howMany);
        }
        print();
    }
    ll maxi = 0;
    rep(i, k - 1)
    {
        ll extra = b[i] - query(0, i, 0, n - 1);
        if (extra)
        {
            ll howMany = (extra + i) / (i + 1);
            maxi = max(maxi, howMany);
        }
    }
    if (maxi)
    {
        update(0, 0, k - 1, 0, n - 1, maxi);
        print();
    }
    res += maxi;
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