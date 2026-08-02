/*
    18 December 2022
    Codeforces 1751-2000 1772 1772F
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
    int n, m, k;
    cin >> n >> m >> k;
    k++;

    vector<vvi> pictures(k, vvi(n, vi(m)));
    vector<vector<vpii>> comp(k, vector<vpii>(k));

    rep(kk, k) rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, m) pictures[kk][i][j] = s[j] - '0';
    }

    repe(i, n - 2) repe(j, m - 2)
    {
        vvi track(2);
        rep(kk, k) track[pictures[kk][i][j]].pb(kk);
        if (gsz(track[0]) == k || gsz(track[0]) == 0)
            continue;

        int parent = 1;
        int child = 0;
        if (pictures[0][i][j - 1])
            swap(parent, child);
        for (auto par : track[parent])
            for (auto chi : track[child])
                comp[par][chi].pb({i, j});
    }

    vi order(k);
    iota(a2z(order), 0);
    sort(a2z(order), [&](int x, int y) -> bool
         { return gsz(comp[x][y]); });

    cout << order[0] + 1 << endl;
    vector<pair<int, pii>> ans;
    rep(i, k - 1)
    {
        for (auto change : comp[order[i]][order[i + 1]])
        {
            int x = change.fr;
            int y = change.sc;
            if (pictures[order[i]][x][y] != pictures[order[i + 1]][x][y])
                ans.pb({1, {x + 1, y + 1}});
        }

        ans.pb({2, {order[i + 1] + 1, 0}});
    }

    cout << gsz(ans) << endl;
    for (auto an : ans)
    {
        int t = an.fr;
        cout << t << " " << an.sc.fr;
        if (t == 1)
            cout << " " << an.sc.sc;
        cout << endl;
    }
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