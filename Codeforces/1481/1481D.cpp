/*
    Washief Hossain Mugdho
    15 April 2021
    Codeforces 1481 1481D
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
using vc = vector<char>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
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

inline void _()
{
    int n, m;
    cin >> n >> m;
    vvc mat(n, vc(n));
    rep(i, n) rep(j, n) cin >> mat[i][j];
    if (n == 2)
    {
        if (m % 2 == 0 && mat[0][1] != mat[1][0])
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << 1;
        rep(i, m) cout << " " << (2 - i % 2);
        cout << endl;
        return;
    }
    cout << "YES" << endl;
    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        if (mat[i][j] == mat[j][i])
        {
            cout << i + 1;
            rep(k, m) cout << " " << (k % 2 ? i + 1 : j + 1);
            cout << endl;
            return;
        }
    }
    if (mat[0][1] == mat[1][2] && mat[2][0] == mat[0][1])
    {
        cout << 1;
        rep(i, m) cout << " " << (i + 1) % 3 + 1;
        cout << endl;
        return;
    }
    int x = 0, y = 1, z = 2;
    while (mat[x][y] != mat[y][z])
    {
        swap(x, y);
        swap(y, z);
    }
    int arr[] = {x + 1, y + 1, z + 1};
    if (m % 2 == 0)
    {
        int k = m >> 1;
        rep(i, k) cout << arr[(((k + 1) & 1) + i) % 2] << " ";
        cout << arr[1] << " ";
        rep(i, k) cout << arr[2 - i % 2] << " ";
        cout << endl;
        return;
    }
    swap(arr[0], arr[1]);
    int k = m >> 1;
    rep(i, k) cout << arr[(((k + 1) & 1) + i) % 2] << " ";
    cout << arr[1] << " " << arr[2] << " ";
    swap(arr[0], arr[1]);
    swap(arr[2], arr[1]);
    rep(i, k) cout << arr[2 - i % 2] << " ";
    cout << endl;
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
