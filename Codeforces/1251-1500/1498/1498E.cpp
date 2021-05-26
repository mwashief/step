/*
    Washief Hossain Mugdho
    09 April 2021
    Codeforces 1498 1498E
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

bool query(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    string s;
    cin >> s;
    if (s[0] == 'Y')
        return 1;
    return 0;
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
    int n;
    cin >> n;
    vi k(n);
    rep(i, n) cin >> k[i];
    vector<pair<int, pii>> all;
    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        int val = abs(k[i] - k[j]);
        all.pb({val, {i, j}});
    }
    sort(all.begin(), all.end());
    for (int i = all.size() - 1; i >= 0; i--)
    {
        int x = all[i].sc.fr;
        int y = all[i].sc.sc;
        if (k[x] <= k[y] - 1)
            swap(x, y);
        x++;
        y++;
        if (query(x, y))
        {
            cout << "! " << x << " " << y << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
}
