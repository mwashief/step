/*
    Washief Hossain Mugdho
    10 March 2022
    Codeforces 1501-1750 1651 1651D
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

    int dr[] = {0, -1, 0, 1};
    int dc[] = {1, 0, -1, 0};

    int n;
    cin >> n;

    vpii all(n), res(n);
    map<pii, int> points;
    vb visited(n);
    queue<int> q;

    rep(i, n)
    {
        cin >> all[i].fr >> all[i].sc;
        points[all[i]] = i;
    }
    rep(t, n)
    {
        int x = all[t].fr;
        int y = all[t].sc;
        rep(i, 4) if (!points.count({x + dr[i], y + dc[i]}))
        {
            visited[t] = true;
            q.push(t);
            res[t] = {x + dr[i], y + dc[i]};
            break;
        }
    }

    while (gsz(q))
    {
        int u = q.front();
        auto &[x, y] = all[q.front()];
        q.pop();
        rep(i, 4) if (points.count({x + dr[i], y + dc[i]}) && !visited[points[{x + dr[i], y + dc[i]}]])
        {
            int t = points[{x + dr[i], y + dc[i]}];
            visited[t] = true;
            q.push(t);
            res[t] = res[u];
        }
    }

    rep(i, n) cout << res[i].fr << " " << res[i].sc << endl;
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