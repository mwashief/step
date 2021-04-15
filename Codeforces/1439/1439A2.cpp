/*
    Washief Hossain Mugdho
    15 April 2021
    Codeforces 1439 1439A2
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
vector<tuple<pii, pii, pii>> res;
vvb mat;

void in(pii a, pii b, pii c)
{
    res.pb({a, b, c});
    mat[a.fr][a.sc] = mat[a.fr][a.sc] ^ 1;
    mat[b.fr][b.sc] = mat[b.fr][b.sc] ^ 1;
    mat[c.fr][c.sc] = mat[c.fr][c.sc] ^ 1;
}

void fix(int r, int c)
{
    vpii all;
    rep(i, 2) rep(j, 2) if (mat[r + i][c + j]) all.pb({r + i, c + j});
    while (all.size())
    {
        if (all.size() == 3)
        {
            in(all[0], all[1], all[2]);
            all.clear();
        }
        else if (all.size() == 2)
        {
            vpii temp;
            rep(i, 2) rep(j, 2) if (all[1].fr != r + i || all[1].sc != c + j) temp.pb({r + i, c + j});
            in(temp[0], temp[1], temp[2]);
            temp.clear();
            rep(i, 2) rep(j, 2) if (all[0].fr != r + i || all[0].sc != c + j) temp.pb({r + i, c + j});
            in(temp[0], temp[1], temp[2]);
            all.clear();
        }
        else if (all.size() == 1)
        {
            vpii temp;
            rep(i, 2) rep(j, 2) if (all[0].fr != r + i || all[0].sc != c + j) temp.pb({r + i, c + j});
            pii a = temp.back();
            temp.pop_back();
            temp.pb(all[0]);
            in(temp[0], temp[1], temp[2]);
            all.clear();
            temp.pop_back();
            all = temp;
        }
        else
        {
            pii a = all.back();
            all.pop_back();
            in(all[0], all[1], all[2]);
            all.clear();
            all.pb(a);
        }
    }
}

inline void _()
{
    int n, m;
    cin >> n >> m;
    int tn = n, tm = m;
    mat = vvb(n, vb(m));
    res.clear();
    rep(i, n) rep(j, m)
    {
        char c;
        cin >> c;
        mat[i][j] = c - '0';
    }
    if (n & 1)
    {
        for (int i = 0; i < m - 1; i += 2)
        {
            int cnt = 0;
            cnt = mat[n - 1][i] + mat[n - 1][i + 1];
            if (cnt == 0)
                continue;
            if (cnt == 2)
                in({n - 1, i}, {n - 1, i + 1}, {n - 2, i});
            else if (mat[n - 1][i])
                in({n - 2, i}, {n - 2, i + 1}, {n - 1, i});
            else
                in({n - 2, i}, {n - 2, i + 1}, {n - 1, i + 1});
        }
        n--;
    }
    if (m & 1)
    {
        for (int i = 0; i < n - 1; i += 2)
        {
            int cnt = 0;
            cnt = mat[i][m - 1] + mat[i + 1][m - 1];
            if (cnt == 0)
                continue;
            if (cnt == 2)
                in({i, m - 1}, {i + 1, m - 1}, {i, m - 2});
            else if (mat[i][m - 1])
                in({i, m - 1}, {i, m - 2}, {i + 1, m - 2});
            else
                in({i + 1, m - 1}, {i, m - 2}, {i + 1, m - 2});
        }
        m--;
    }

    for (int i = 0; i < n - 1; i += 2)
        for (int j = 0; j < m - 1; j += 2)
            fix(i, j);
    if (tn % 2 && tm % 2)
        fix(n - 1, m - 1);
    cout << res.size() << endl;
    for (auto d : res)
    {
        cout << get<0>(d).fr + 1 << " " << get<0>(d).sc + 1 << " ";
        cout << get<1>(d).fr + 1 << " " << get<1>(d).sc + 1 << " ";
        cout << get<2>(d).fr + 1 << " " << get<2>(d).sc + 1 << endl;
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
    int __;
    cin >> __;
    while (__--)
        _();
}
