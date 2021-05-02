/*
    Washief Hossain Mugdho
    02 May 2021
    Codeforces 1493 1493D
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

vi spf(200001);

void precalc()
{
    rep(i, 200001) spf[i] = (i & 1 ? i : 2);
    for (int i = 3; i * i < 200001; i += 2)
        if (spf[i] == i)
        {
            for (int j = i * i; j < 200001; j += (i << 1))
                spf[j] = min(spf[j], i);
        }
}

int modPow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
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
    precalc();
    int n, q;
    cin >> n >> q;
    unordered_map<int, multiset<int>> track;
    int g = 1;
    umii all[n];
    rep(i, n)
    {
        int x;
        cin >> x;
        umii temp;
        while (x != 1)
        {
            temp[spf[x]]++;
            x /= spf[x];
        }
        for (auto a : temp)
        {
            track[a.fr].insert(a.sc);
            if (track[a.fr].size() == n)
                g = 1LL * g * modPow(a.fr, *track[a.fr].begin()) % MOD;
        }
        all[i] = move(temp);
    }

    rep(i, q)
    {
        int x, y;
        cin >> y >> x;
        y--;
        umii temp;
        while (x != 1)
        {
            temp[spf[x]]++;
            x /= spf[x];
        }
        for (auto a : temp)
        {
            int prevPower = 0;
            if (track[a.fr].size() == n)
                prevPower = *track[a.fr].begin();
            int c = all[y][a.fr];
            if (c)
                track[a.fr].erase(track[a.fr].find(c));
            all[y][a.fr] = c + a.sc;
            track[a.fr].insert(c + a.sc);
            if (track[a.fr].size() == n)
                g = 1LL * g * modPow(a.fr, *track[a.fr].begin() - prevPower) % MOD;
        }
        cout << g << endl;
    }
}
