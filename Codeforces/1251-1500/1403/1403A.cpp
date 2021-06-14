/*
    Washief Hossain Mugdho
    14 June 2021
    Codeforces 1251-1500 1403 1403A
*/

#ifndef __DEBUG__
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

const int blockSize = 50;

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
    int n, d, u, q, res;
    cin >> n >> d >> u >> q;
    vi h(n);
    rep(i, n) cin >> h[i];
    vpii adj[n];
    repe(i, u)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb({i, b});
        adj[b].pb({i, a});
    }

    vector<vector<vi>> block(n);
    rep(i, n)
    {
        useti current;
        rep(j, adj[i].size())
        {
            if (current.find(adj[i][j].sc) == current.end())
                current.insert(adj[i][j].sc);
            else
                current.erase(adj[i][j].sc);
            if ((j + 1) % blockSize == 0 || j == (adj[i].size() - 1))
            {
                block[i].pb(vi());
                for (auto x : current)
                    block[i].back().pb(x);
                sort(a2z(block[i].back()), [&](int a, int b)
                     { return h[a] < h[b]; });
            }
        }
    }

    auto checkBlock = [&](vi &a, vi &b)
    {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            while (i < a.size() && j < b.size() && h[a[i]] <= h[b[j]])
            {
                res = min(res, h[b[j]] - h[a[i]]);
                i++;
            }
            while (j < b.size() && i < a.size() && h[a[i]] >= h[b[j]])
            {
                res = min(res, h[a[i]] - h[b[j]]);
                j++;
            }
        }
    };

    auto get = [&](int node, int day)
    {
        int l = -1;
        int r = adj[node].size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (adj[node][mid].fr <= day)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    };

    rep(qq, q)
    {
        int a, b, c;
        res = 1000000000;
        cin >> a >> b >> c;
        int l1 = get(a, c);
        if (l1 == -1)
        {
            cout << res << endl;
            continue;
        }
        int k1 = l1 / blockSize;
        int l2 = get(b, c);
        if (l2 == -1)
        {
            cout << res << endl;
            continue;
        }
        int k2 = l2 / blockSize;
        useti c1, c2;

        for (int i = k1 * blockSize; i <= l1; i++)
            if (c1.find(adj[a][i].sc) == c1.end())
                c1.insert(adj[a][i].sc);
            else
                c1.erase(adj[a][i].sc);
        for (int i = k2 * blockSize; i <= l2; i++)
            if (c2.find(adj[b][i].sc) == c2.end())
                c2.insert(adj[b][i].sc);
            else
                c2.erase(adj[b][i].sc);

        vi d1, d2, extra1, extra2;
        if (k1 > 0)
        {
            for (auto x : block[a][k1 - 1])
                if (c1.find(x) == c1.end())
                    d1.pb(x);
                else
                    c1.erase(x);
        }
        if (k2 > 0)
        {
            for (auto x : block[b][k2 - 1])
                if (c2.find(x) == c2.end())
                    d2.pb(x);
                else
                    c2.erase(x);
        }
        for (auto x : c1)
            extra1.pb(x);
        for (auto x : c2)
            extra2.pb(x);

        sort(a2z(extra1), [&](int aa, int bb)
             { return h[aa] < h[bb]; });
        sort(a2z(extra2), [&](int aa, int bb)
             { return h[aa] < h[bb]; });

        checkBlock(d1, d2);
        checkBlock(d1, extra2);
        checkBlock(d2, extra1);
        checkBlock(extra1, extra2);

        cout << res << endl;
    }
}