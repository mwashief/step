/*
    Washief Hossain Mugdho
    28 July 2021
    Codeforces 1251-1500 1493 1493C
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

inline void __run_test()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (gsz(s) % k)
    {
        cout << -1 << endl;
        return;
    }
    vector<map<char, int>> state(n + 1);
    repe(i, n)
    {
        for (char j = 'a'; j <= 'z'; j++)
            if (state[i - 1].find(j) != state[i - 1].end())
                state[i][j] = state[i - 1][j];
        state[i][s[i - 1]] = (state[i][s[i - 1]] + 1) % k;
        if (state[i][s[i - 1]] == 0)
            state[i].erase(s[i - 1]);
    }
    if (state[n].size() == 0)
    {
        cout << s << endl;
        return;
    }

    rrep(i, n)
    {
        int extra = 0;
        for (auto d : state[i])
            extra += k - d.sc;
        int slots = n - i - 1;

        for (char c = s[i] + 1; c <= 'z'; c++)
        {
            int x = extra;
            int already = 0;
            if (state[i].find(c) != state[i].end())
                already = state[i][c];
            if (already)
                x -= k - already;
            already = (already + 1) % k;
            x += (k - already) % k;
            if (x <= slots)
            {
                string t;
                rep(j, i) t.pb(s[j]);
                t.pb(c);
                state[i][c] = (state[i][c] + 1) % k;
                if (state[i][c] == 0)
                    state[i].erase(c);
                rep(j, slots - x) t.pb('a');
                for (auto d : state[i])
                    rep(j, k - d.sc) t.pb(d.fr);

                cout << t << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}