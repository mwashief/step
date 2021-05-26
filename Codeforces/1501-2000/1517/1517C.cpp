/*
    Washief Hossain Mugdho
    23 April 2021
    Codeforces 1517 1517C
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

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
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
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}
int n;
vvi a;
vi taken;
int dr[] = {0, 1, -1, 0};
int dc[] = {-1, 0, 0, 1};
queue<pii> all;

bool isValid(int r, int c)
{
    if (c > r)
        return 0;
    return c >= 1 && c <= n && r >= 1 && r <= n && a[r][c] == 0;
}

void dfs(int r, int c)
{
    vpii possible;
    if (taken[a[r][c]] == 0)
        return;
    rep(i, 4)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (isValid(rr, cc))
            possible.pb({rr, cc});
    }
    if (possible.size() == 1)
    {
        int rr = possible[0].fr;
        int cc = possible[0].sc;
        a[rr][cc] = a[r][c];
        taken[a[r][c]]--;
        dfs(rr, cc);
    }
    if (possible.size() > 1)
        all.push({r, c});
}

void pri()
{
    repe(i, n)
    {
        repe(j, i) cout << a[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    a = vvi(n + 1, vi(n + 1, 0));
    taken = vi(n + 1);
    repe(i, n)
    {
        taken[i] = i - 1;
        cin >> a[i][i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    repe(i, n) all.push({i, i});
    while (gsz(all))
    {
        auto d = all.front();
        int r = d.fr;
        int c = d.sc;
        all.pop();
        vpii possible;
        rep(i, 4)
        {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (isValid(rr, cc))
                possible.pb({rr, cc});
        }
        if (possible.size() == 0)
            continue;
        if (possible.size() == 1)
            dfs(r, c);
        else
            all.push(d);
    }
    pri();
}
