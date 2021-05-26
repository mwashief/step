/*
    Washief Hossain Mugdho
    24 April 2021
    Codeforces 1370 1370E
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
    string s, t;
    cin >> s >> t;
    int a = 0, b = 0;
    set<int> all[2];
    rep(i, n)
    {
        if (s[i] == '1')
            a++;
        if (t[i] == '1')
            b++;
        if (s[i] != t[i])
            all[s[i] - '0'].insert(i);
    }
    if (a != b)
    {
        cout << -1 << endl;
        return 0;
    }
    assert(all[0].size() == all[1].size());
    int res = 0;
    while (gsz(all[0]))
    {
        int now = *all[0].begin() > *all[1].begin();
        int ind = -1;
        while (1)
        {
            auto it1 = all[now].upper_bound(ind);
            if (it1 == all[now].end())
                break;
            int d1 = *it1;
            auto it2 = all[1 - now].upper_bound(d1);
            if (it2 == all[1 - now].end())
                break;
            ind = *it2;
            all[now].erase(it1);
            all[1 - now].erase(it2);
        }
        res++;
    }
    cout << res << endl;
}
