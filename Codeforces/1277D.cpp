/*
    Washief Hossain Mugdho
    06 February 2021
    Codeforces 1277D
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
    int n;
    cin >> n;
    map<string, int> pos;
    vector<set<string>> a(4);
    repe(i, n)
    {
        string s;
        cin >> s;
        int d = 0;
        if (s[s.size() - 1] == '1')
            d |= 1;
        if (s[0] == '1')
            d |= 2;
        a[d].insert(s);
        pos[s] = i;
    }
    if (a[3].size() && a[0].size() && !a[1].size() && !a[2].size())
    {
        cout << -1 << endl;
        return;
    }
    if (abs((int)a[1].size() - (int)a[2].size()) <= 1)
    {
        cout << 0 << endl;
        return;
    }
    int give = 1;
    if (a[2].size() > a[1].size())
        give = 2;
    int take = 3 - give;
    int k = (a[1].size() + a[2].size()) / 2;
    if ((a[2].size() + a[1].size()) & 1)
        k++;
    int havetoGive = a[give].size() - k;
    vi res;
    for (auto x : a[give])
    {
        if (res.size() >= havetoGive)
            break;
        string temp = x;
        reverse(temp.begin(), temp.end());
        if (a[take].find(temp) == a[take].end())
            res.pb(pos[x]);
    }
    if (res.size() != havetoGive)
    {
        cout << -1 << endl;
        return;
    }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << " ";
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
