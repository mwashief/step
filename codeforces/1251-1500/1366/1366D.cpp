/*
    Washief Hossain Mugdho
    02 May 2021
    Codeforces 1366 1366D
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
#define MAX 10000001

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

vi spf(MAX);

auto precalc()
{
    rep(i, MAX) spf[i] = (i % 2 ? i : 2);
    for (int i = 3; i * i < MAX; i += 2)
        if (spf[i] == i)
            for (int j = i * i; j < MAX; j += (i << 1))
                spf[j] = min(spf[j], i);
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
    precalc();
    int n;
    cin >> n;
    vpii res;
    rep(i, n)
    {
        int x;
        cin >> x;
        useti track;

        while (x != 1)
        {
            track.insert(spf[x]);
            x /= spf[x];
        }
        if (track.size() < 2)
            res.pb({-1, -1});
        else
        {
            int a = *track.begin();
            track.erase(track.begin());
            int b = 1;
            for (const int &d : track)
                b *= d;
            res.pb({a, b});
        }
    }
    rep(i, n) cout << res[i].fr << " ";
    cout << endl;
    rep(i, n) cout << res[i].sc << " ";
    cout << endl;
}
