/*
    Washief Hossain Mugdho
    01 January 2021
    Codeforces 1468J
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

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

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &... args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}
int n, m, k;
vector<pair<int, pii>> edges;
vi parent;

int findRep(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = findRep(parent[a]);
}
bool uniSet(int a, int b)
{
    int repa = findRep(a);
    int repb = findRep(b);
    if (repa == repb)
        return false;
    if (repa < repb)
        parent[repb] = repa;
    else
        parent[repa] = repb;
    return true;
}

inline void run_tests()
{
    edges.clear();
    parent.clear();
    cin >> n >> m >> k;
    rep(i, n) parent.pb(i);
    ll smallestDiff = INT32_MAX;
    rep(i, m)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.pb({z, {x - 1, y - 1}});
        smallestDiff = min(smallestDiff, (ll)abs(z - k));
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (int i = 0; i < m; i++)
        if (uniSet(edges[i].sc.fr, edges[i].sc.sc))
            ans += max(0, edges[i].fr - k);
    if (ans == 0)
        ans = smallestDiff;
    cout << ans << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
