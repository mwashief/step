/*
    Washief Hossain Mugdho
    30 December 2020
    Codeforces 1365D
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
int dc[] = {1, 0, -1, 0};
int dr[] = {0, -1, 0, 1};
int n, m, good;
vector<vector<char>> mat;

bool isValid(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void dfs(int r, int c)
{
    int bad = 0;
    for (int i = 0; i < 4; i++)
    {
        int row = r + dr[i];
        int col = c + dc[i];
        if (isValid(row, col) && mat[row][col] == 'B')
            bad++;
    }
    if (bad)
    {
        mat[r][c] = '#';
        return;
    }
    if (mat[r][c] == 'G')
        good--;
    mat[r][c] = '#';
    for (int i = 0; i < 4; i++)
    {
        int row = r + dr[i];
        int col = c + dc[i];
        if (isValid(row, col) && mat[row][col] != '#')
            dfs(row, col);
    }
}

inline void run_tests()
{
    good = 0;
    cin >> n >> m;
    mat = vector<vector<char>>(n, vector<char>(m));
    rep(i, n) rep(j, m)
    {
        cin >> mat[i][j];
        if (mat[i][j] == 'G')
            good++;
    }
    dfs(n - 1, m - 1);
    if (good)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
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
