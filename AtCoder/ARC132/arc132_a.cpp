/*
    Washief Hossain Mugdho
    26 December 2021
    AtCoder ARC132 arc132_a
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
    int n, q;
    cin >> n;
    vpii rows, cols;
    repe(i, n)
    {
        int x;
        cin >> x;
        rows.pb({x, i});
    }
    repe(i, n)
    {
        int x;
        cin >> x;
        cols.pb({x, i});
    }
    sort(a2z(rows));
    sort(a2z(cols));
    cin >> q;
    vi res(q, -1);
    map<int, vi> rq, cq;
    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        rq[x].pb(i);
        cq[y].pb(i);
    }
    rep(i, n / 2)
    {
        int blacks = rows[n - 1 - i].sc;
        for (auto d : rq[blacks])
            if (res[d] == -1)
                res[d] = 1;
        rq[blacks].clear();
        blacks = cols[n - 1 - i].sc;
        for (auto d : cq[blacks])
            if (res[d] == -1)
                res[d] = 1;
        cq[blacks].clear();

        blacks = rows[i].sc;
        for (auto d : rq[blacks])
            if (res[d] == -1)
                res[d] = 0;
        rq[blacks].clear();
        blacks = cols[i].sc;
        for (auto d : cq[blacks])
            if (res[d] == -1)
                res[d] = 0;
        cq[blacks].clear();
    }

    rep(i, q) if (res[i]) cout << '#';
    else cout << '.';
    cout << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
*/