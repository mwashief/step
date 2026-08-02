/*
    Washief Hossain Mugdho
    04 May 2021
    Codeforces 1278 1278D
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

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

namespace std
{

    template <class Fun>
    class y_combinator_result
    {
        Fun fun_;

    public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

        template <class... Args>
        decltype(auto) operator()(Args &&...args)
        {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun)
    {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

}

template <class T, class OP>
class SegmentTree
{
    vector<T> t;
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = OP()(t[i << 1], t[i << 1 | 1]);
    }

public:
    int n;

    SegmentTree(int nn)
    {
        n = nn;
        t = vector<T>(n << 1);
    }

    SegmentTree(vector<T> v)
    {
        n = v.size();
        t = vector<T>(n << 1);
        for (int i = 0; i < n; ++i)
            t[i + n] = v[i];
        build();
    }

    void update(int p, T value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = OP()(t[p], t[p ^ 1]);
    }

    T query(int l, int r)
    {
        r++;
        T res = OP::initVal;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = OP()(res, t[l++]);
            if (r & 1)
                res = OP()(res, t[--r]);
        }
        return res;
    }
};

template <class T>
class Add
{
public:
    static const T initVal = T(0);
    T operator()(T x, T y)
    {
        return x + y;
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

    int n, ind = 1, edges = 0;
    cin >> n;
    vpii a(n);
    rep(i, n) cin >> a[i].fr >> a[i].sc;
    sort(a2z(a));
    SegmentTree<int, Add<int>> st((n << 1) + 5);
    multiset<int> pre;
    pre.insert(a[0].sc);
    st.update(a[0].sc, 1);
    if (n == 1)
    {
        pyes << endl;
        return 0;
    }
    repe(i, n - 1)
    {
        while (pre.size() && *pre.begin() < a[i].fr)
        {
            st.update(*pre.begin(), st.query(*pre.begin(), *pre.begin()) - 1);
            pre.erase(pre.begin());
        }
        if (!pre.size())
        {
            pno << endl;
            return 0;
        }
        edges += st.query(0, a[i].sc - 1);
        pre.insert(a[i].sc);
        st.update(a[i].sc, st.query(a[i].sc, a[i].sc) + 1);
    }
    if (edges != n - 1)
    {
        pno << endl;
        return 0;
    }
    vi parent(n);
    rep(i, n) parent[i] = i;

    auto getRep = y_combinator([&](auto self, int node) -> int {
        if (parent[node] == node)
            return node;
        return parent[node] = self(parent[node]);
    });

    auto uni = [&](int a, int b) -> bool {
        a = getRep(a);
        b = getRep(b);
        if (a == b)
            return false;
        parent[b] = a;
        return true;
    };

    multiset<pii> construct;
    construct.insert({a[0].sc, 0});
    repe(i, n - 1)
    {
        while (construct.size() && construct.begin()->fr < a[i].fr)
            construct.erase(construct.begin());
        for (auto d : construct)
        {
            if (d.fr >= a[i].sc)
                break;

            if (!uni(d.sc, i))
            {
                pno << endl;
                return 0;
            }
        }
        construct.insert({a[i].sc, i});
    }
    pyes << endl;
}
