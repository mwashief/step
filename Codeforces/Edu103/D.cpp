/*
    Washief Hossain Mugdho
    29 January 2021
    Edu103 D
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
vvi dan;
vvi bam;
int n;
vb dir;

int dandp(int pos, int inv)
{
    if (pos == n - 1)
        return 0;
    if (dan[pos][inv] != -1)
        return dan[pos][inv];
    if (inv == 0)
    {
        if (!dir[pos])
            return dan[pos][inv] = 1 + dandp(pos + 1, 1 - inv);
        return dan[pos][inv] = 0;
    }
    if (dir[pos])
        return dan[pos][inv] = 1 + dandp(pos + 1, 1 - inv);
    return dan[pos][inv] = 0;
}

int bamdp(int pos, int inv)
{
    if (pos == 0)
        return 0;
    if (bam[pos][inv] != -1)
        return bam[pos][inv];
    if (inv == 0)
    {
        if (dir[pos - 1])
            return bam[pos][inv] = 1 + bamdp(pos - 1, 1 - inv);
        return bam[pos][inv] = 0;
    }
    if (!dir[pos - 1])
        return bam[pos][inv] = 1 + bamdp(pos - 1, 1 - inv);
    return bam[pos][inv] = 0;
}

inline void _()
{
    cin >> n;
    n++;
    dan = vvi(n, vi(2, -1));
    bam = vvi(n, vi(2, -1));
    dir = vb(n - 1, 0);
    rep(i, n - 1)
    {
        char c;
        cin >> c;
        if (c == 'L')
            dir[i] = 1;
    }
    for (int i = 0; i < n; i++)
        cout << bamdp(i, 0) + dandp(i, 0) + 1 << " ";
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
