/*
    04 March 2024
    Codeforces 1751-2000 1924 1924A
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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
#define MOD 1000000007 // 998244353
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
    int n, k, m;
    string s;
    cin >> n >> k >> m >> s;

    vvi memo(m + 1, vi(n + 1, -1));
    vvi charPos(26);

    rep(i, m) charPos[s[i] - 'a'].pb(i);

    rrep(i, m + 1) rep(j, n + 1)
    {
        if (j == 0)
            memo[i][j] = true;
        else if (m - i < j)
            memo[i][j] = false;
        else
        {
            bool possible = true;

            for (int p = 0; p < k && possible; p++)
            {
                auto it = lower_bound(a2z(charPos[p]), i);
                if (it == charPos[p].end())
                {
                    possible = false;
                    break;
                }

                possible = possible & memo[*it + 1][j - 1];
            }

            memo[i][j] = static_cast<int>(possible);
        }
    }

    if (memo[0][n])
    {
        pyes << endl;
        return;
    }
    pno << endl;

    string res = "";
    int j = 0;
    rrepe(i, n)
    {
        for (int p = 0; p < k; p++)
        {
            auto it = lower_bound(a2z(charPos[p]), j);
            if (it == charPos[p].end())
            {
                res.pb('a' + p);
                while (gsz(res) != n)
                    res.pb('a');
                cout << res << endl;
                return;
            }

            if (!memo[*it + 1][i - 1])
            {
                res.pb('a' + p);
                j = *it + 1;
                break;
            }
        }
    }

    cout << res << endl;
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

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/