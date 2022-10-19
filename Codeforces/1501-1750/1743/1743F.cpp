/*
    Washief Hossain Mugdho
    18 October 2022
    Codeforces 1501-1750 1743 1743F
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
#define MOD 998244353
#define MAX 300001

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

template <int mod>
struct Mod
{
    long long x;
    Mod() : x(0) {}
    Mod(long long xx) : x(xx)
    {
        if (abs(x) >= mod)
            x %= mod;
        if (x < 0)
            x += mod;
    }
    operator int() const { return x; }
    operator long long() const { return x; }
    Mod operator+(const Mod &a) const
    {
        Mod n;
        n.x = x + a.x;
        if (n.x >= mod)
            n.x -= mod;
        return n;
    }
    Mod operator-(const Mod &a) const
    {
        Mod n;
        n.x = x - a.x;
        if (n.x < 0)
            n.x += mod;
        return n;
    }
    Mod operator*(const Mod &a) const
    {
        return x * a.x;
    }
    Mod operator+=(const Mod &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    Mod operator-=(const Mod &a)
    {
        x -= a.x;
        if (x < 0)
            x += mod;
        return *this;
    }
    Mod operator++()
    {
        *this += 1;
        return *this;
    }
    Mod operator++(int) // postfix
    {
        Mod temp = *this;
        *this += 1;
        return temp;
    }
    Mod operator--()
    {
        *this -= 1;
        return *this;
    }
    Mod operator--(int) // postfix
    {
        Mod temp = *this;
        *this -= 1;
        return temp;
    }
    Mod operator*=(const Mod &a)
    {
        x = (x * a.x) % mod;
        return *this;
    }
    Mod pow(long long b) const
    {
        Mod ans = 1;
        Mod a = *this;
        while (b > 0)
        {
            if (b & 1)
                ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    Mod inv() const
    {
        return pow(mod - 2);
    }
    Mod operator/(const Mod &a) const
    {
        return (*this) * a.inv();
    }
    Mod operator/=(const Mod &a)
    {
        return (*this) *= a.inv();
    }
    bool operator==(const Mod &o) const
    {
        return x == o.x;
    }
    bool operator!=(const Mod &o) const
    {
        return x != o.x;
    }
    long long operator()() const
    {
        return x;
    }
    template <int _mod>
    friend ostream &operator<<(ostream &os, const Mod<_mod> &num)
    {
        os << num.x;
        return os;
    }
    template <int _mod>
    friend istream &operator>>(istream &is, Mod<_mod> &num)
    {
        is >> num.x;
        if (abs(num.x) >= mod)
            num.x %= mod;
        if (num.x < 0)
            num.x += mod;
        return is;
    }
};
using base = Mod<MOD>;
using vbase = vector<base>;
using vvbase = vector<vector<base>>;
base two = 2;
base three = 3;

template <class T>
T OP(T a, T b)
{
    return max(a, b);
}

template <class T>
class SegmentTree
{
private:
    // change here
    void propagate(int node, T val, int nodes)
    {
        tree[node] = max(tree[node], val);
        lazy[node] = max(lazy[node], val);
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
        // change here
        if (ql > r || qr < l)
            return (T)0;
        if (l >= ql && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node]) // change here
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = (T)0; // change here
        }
        return OP(queryUtil(leftNode, l, mid, ql, qr), queryUtil(rightNode, mid + 1, r, ql, qr));
    }

    T updateUtil(int node, int l, int r, int ql, int qr, T val)
    {
        if (ql > r || qr < l)
            return tree[node];
        if (l >= ql && r <= qr)
        {
            // change here
            tree[node] = OP(tree[node], val);
            lazy[node] = OP(lazy[node], val);
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int leftNode = (node << 1) + 1;
        int rightNode = leftNode + 1;
        if (lazy[node]) // change here
        {
            propagate(leftNode, lazy[node], mid - l + 1);
            propagate(rightNode, lazy[node], r - mid);
            lazy[node] = 0; // change here
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
        // change here
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
    int n;
    cin >> n;
    vi fir(MAX);

    SegmentTree<int> st(MAX);
    repe(i, n)
    {
        int l, r;
        cin >> l >> r;
        st.update(l, r, i);
        if (i == 1)
        {
            fir[r] = 1;
            if (l > 0)
                fir[l - 1] = -1;
        }
    }

    rrep(i, MAX - 1) fir[i] += fir[i + 1];
    vbase prefixSum(n + 1);
    for (int i = 2; i <= n; i++)
        prefixSum[i] = three.pow(i - 2) * two.pow(n - i - 1);
    for (int i = 3; i <= n; i++)
        prefixSum[i] += prefixSum[i - 1];

    base res = 0;

    rep(i, MAX)
    {
        int last = st.query(i, i);
        if (last > 1)
        {
            res += prefixSum[last - 1];
            res += three.pow(last - 2) * two.pow(n - last);
            res += two.pow(n - 2);
        }
        else if (last == 1)
            res += two.pow(n - 1);
    }

    cout << res.x << endl;
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