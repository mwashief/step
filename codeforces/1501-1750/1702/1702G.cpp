/*
    Washief Hossain Mugdho
    10 July 2022
    Codeforces 1501-1750 1702 1702G
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

    template <class T>
    T &unmove(T &&t) { return t; }

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
class Max
{
public:
    static const T initVal = numeric_limits<T>::min();
    T operator()(T x, T y)
    {
        return max(x, y);
    }
};

template <class T>
class Min
{
public:
    static const T initVal = numeric_limits<T>::max();
    T operator()(T x, T y)
    {
        return min(x, y);
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
    vvi adj(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vpii time(n);
    int current = 0;
    y_combinator([&](auto self, int node, int parent) -> void
                 {
        time[node].fr = current++;
        for(auto child: adj[node])
            if(child != parent) 
                self(child, node);
        time[node].sc = current++; })(0, -1);

    vpii temp = time;
    sort(a2z(temp));
    vi fir, seco;
    rep(i, n)
    {
        fir.pb(temp[i].fr);
        seco.pb(temp[i].sc);
    }
    SegmentTree<int, Max<int>> st(seco);

    auto query = [&]() -> bool
    {
        int k;
        cin >> k;
        vpii all;
        rep(i, k)
        {
            int x;
            cin >> x;
            all.pb(time[x - 1]);
        }
        if (k <= 2)
            return true;

        sort(a2z(all), [&](pii a, pii b) -> bool
             { return a.sc - a.fr < b.sc - b.fr; });

        auto biggest = all.back();
        bool taken = true;
        rep(i, k - 1) if (!(biggest.fr < all[i].fr && biggest.sc > all[i].sc))
        {
            taken = false;
            break;
        }

        if (taken)
            all.pop_back();

        sort(a2z(all), [&](pii a, pii b) -> bool
             { return a.sc > b.sc; });

        int mini = INT32_MAX;
        int maxi = INT32_MIN;

        int right = -1;

        int child = 0;
        rep(i, 2)
        {
            while (all.size())
            {
                child |= (1 << i);
                auto last = all.back();
                all.pop_back();
                mini = min(mini, last.fr);
                maxi = max(maxi, last.sc);
                if (last.fr <= right)
                    return false;
                if (size(all) == 0)
                    break;
                if (!(all.back().fr < last.fr && all.back().sc > last.sc))
                    break;
            }
            right = maxi;
        }

        if (gsz(all))
            return false;
        if (taken && !(biggest.fr < mini && biggest.sc > maxi))
            return false;
        if (taken && child == 3)
        {
            int r = lower_bound(a2z(fir), mini) - fir.begin();
            int l = upper_bound(a2z(fir), biggest.fr) - fir.begin();
            if (l < r)
            {
                int what = st.query(l, r - 1);
                if (what > maxi)
                    return false;
            }
        }
        return true;
    };

    int q;
    cin >> q;
    while (q--)
        if (query())
            pyes << endl;
        else
            pno << endl;
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