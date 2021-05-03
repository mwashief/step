/*
    Washief Hossain Mugdho
    02 May 2021
    Codeforces 1515 1515D
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

inline void _()
{
    int n, l, r;
    cin >> n >> l >> r;
    int t = 0;
    if (l > r)
        t = 1;
    umii track[2];
    rep(i, l)
    {
        int c;
        cin >> c;
        track[t][c]++;
    }
    rep(i, r)
    {
        int c;
        cin >> c;
        track[1 - t][c]++;
    }
    if (t)
        swap(l, r);

    int rem = n / 2;
    int mov = (r - l) >> 1;
    int res = 0;
    multiset<int, greater<int>> h;
    for (auto a : track[1])
    {
        int m = min(a.sc, track[0][a.fr]);
        rem -= m;
        track[1][a.fr] -= m;
        track[0][a.fr] -= m;
        h.insert(track[1][a.fr]);
    }
    for (auto a : h)
    {
        if (!mov)
            break;
        int now = min(mov, a >> 1);
        res += now;
        mov -= now;
        rem -= now;
    }
    cout << res + mov + rem << endl;
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