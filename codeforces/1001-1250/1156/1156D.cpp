/*
    Washief Hossain Mugdho
    20 November 2021
    Codeforces 1001-1250 1156 1156D
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
    int n;
    cin >> n;
    vector<vvi> adj(2, vvi(n));
    rep(i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[w][u].pb(v);
        adj[w][v].pb(u);
    }

    vvi comp(2, vi(n));
    ll res = 0LL;
    rep(col, 2)
    {
        vb visited(n);
        rep(i, n) if (!visited[i])
        {
            vi now;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (q.size())
            {
                auto u = q.front();
                q.pop();
                now.pb(u);
                for (auto a : adj[col][u])
                    if (!visited[a])
                    {
                        visited[a] = true;
                        q.push(a);
                    }
            }
            ll sz = gsz(now);
            res += sz * (sz - 1LL);
            for (auto a : now)
                comp[col][a] = sz;
        }
    }

    rep(i, n) res += 1LL * (comp[0][i] - 1) * (comp[1][i] - 1);
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