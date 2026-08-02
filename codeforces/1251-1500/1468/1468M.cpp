/*
    Washief Hossain Mugdho
    21 April 2021
    Codeforces 1468 1468M
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

int read_int()
{
    char r;
    bool start = false, neg = false;
    int ret = 0;
    while (true)
    {
        r = getchar();
        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start)
        {
            continue;
        }
        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start)
        {
            break;
        }
        if (start)
            ret *= 10;
        start = true;
        ret += r - '0';
    }

    return ret;
}

inline void _()
{
    int n = read_int();
    vvi all(n);
    vi compress;
    int total = 0;
    rep(i, n)
    {
        int k = read_int();
        total += k;
        rep(kk, k)
        {
            int x;
            x = read_int();
            all[i].pb(x);
            compress.pb(x);
        }
    }

    int threshold = sqrt(total);

    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    for (auto &a : all)
        for (auto &b : a)
            b = lower_bound(a2z(compress), b) - compress.begin();

    int visited[compress.size()];
    ms(visited, 0);
    rep(i, n) if (gsz(all[i]) >= threshold)
    {
        for (auto a : all[i])
            visited[a] = 1;
        rep(j, i) if (gsz(all[j]) < threshold)
        {
            int cnt = 0;
            for (auto a : all[j])
                if (visited[a])
                    cnt++;
            if (cnt >= 2)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            int cnt = 0;
            for (auto a : all[j])
                if (visited[a])
                    cnt++;
            if (cnt >= 2)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
        for (auto a : all[i])
            visited[a] = 0;
    }

    vvi inv(compress.size());
    compress.clear();
    rep(i, n) if (gsz(all[i]) < threshold) for (auto d : all[i]) inv[d].pb(i);

    for (int i = 0; i < inv.size(); i++)
    {
        for (int sets : inv[i])
            for (auto d : all[sets])
                if (d > i)
                {
                    if (visited[d])
                    {
                        cout << visited[d] << " " << sets + 1 << endl;
                        return;
                    }
                    else
                        visited[d] = sets + 1;
                }
        for (int sets : inv[i])
            for (auto d : all[sets])
                if (d > i)
                    visited[d] = 0;
    }

    cout << -1 << endl;
}

int main()
{

#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int __;
    __ = read_int();
    while (__--)
        _();
}