/*
    Washief Hossain Mugdho
    06 May 2021
    Codeforces 1520 1520G
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int dr[] = {0, -1, 0, 1};
    int dc[] = {1, 0, -1, 0};
    int n, m;
    ll w;
    cin >> n >> m >> w;
    vvl s(n, vl(m, INT64_MAX)), t(n, vl(m, INT64_MAX)), mat(n, vl(m, INT64_MAX));
    rep(i, n) rep(j, m) cin >> mat[i][j];

    s[0][0] = 0;
    t[n - 1][m - 1] = 0;

    auto isLegal = [&](int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m && (mat[r][c] != -1);
    };

    ll portal = INT64_MAX;
    auto Sbfs = [&]() {
        queue<pair<pii, ll>> q;
        q.push({{0, 0}, 0});
        while (q.size())
        {
            auto d = q.front();
            int r = d.fr.fr;
            int c = d.fr.sc;
            ll dis = d.sc;
            q.pop();
            if (s[r][c] < dis)
                continue;
            if (mat[r][c] > 0LL && mat[r][c] + dis < portal)
                portal = dis + mat[r][c];

            rep(i, 4)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (!isLegal(rr, cc))
                    continue;
                if (s[rr][cc] > dis + w)
                {
                    s[rr][cc] = dis + w;
                    q.push({{rr, cc}, dis + w});
                }
            }
        }
    };

    Sbfs();
    ll res = s[n - 1][m - 1];

    auto Tbfs = [&]() {
        queue<pair<pii, ll>> q;
        q.push({{n - 1, m - 1}, 0});
        while (q.size())
        {
            auto d = q.front();
            int r = d.fr.fr;
            int c = d.fr.sc;
            ll dis = d.sc;
            q.pop();
            if (t[r][c] < dis)
                continue;
            if (portal != INT64_MAX && mat[r][c] > 0LL)
                res = min(res, portal + dis + mat[r][c]);

            rep(i, 4)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (!isLegal(rr, cc))
                    continue;
                if (t[rr][cc] > dis + w)
                {
                    t[rr][cc] = dis + w;
                    q.push({{rr, cc}, dis + w});
                }
            }
        }
    };
    Tbfs();
    if (res == INT64_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
}
