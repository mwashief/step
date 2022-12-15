/*
    15 December 2022
    Codeforces 1751-2000 1762 1762D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#endif

#define __INTERACTIVE__

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

int query(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    int k;
    cin >> k;
    return k;
}

inline void __run_test()
{
    int n;
    cin >> n;
    vi candidates(n);
    iota(a2z(candidates), 1);
    while (gsz(candidates) > 3)
    {
        int a = query(candidates[0], candidates[gsz(candidates) - 1]);
        int b = query(candidates[1], candidates[gsz(candidates) - 1]);

        if (a == 1 && b == 1)
        {
            candidates.pop_back();
            if (gsz(candidates) <= 3)
                break;
            a = query(candidates[0], candidates[gsz(candidates) - 1]);
            b = query(candidates[1], candidates[gsz(candidates) - 1]);

            if (a == 1 && b == 1)
            {
                candidates.pop_back();
                swap(candidates[0], candidates[gsz(candidates) - 1]);
                candidates.pop_back();
                swap(candidates[1], candidates[gsz(candidates) - 1]);
                candidates.pop_back();
            }
            else
            {
                if (b > a)
                    swap(candidates[0], candidates[1]);
                break;
            }
        }
        else
        {
            if (b > a)
                swap(candidates[0], candidates[1]);
            break;
        }
    }

    while (gsz(candidates) > 2)
    {
        vi res = {0};
        repe(i, gsz(candidates) - 1)
            res.pb(query(candidates[0], candidates[i]));

        int maximum = *max_element(a2z(res));
        if (maximum == 1)
        {
            swap(candidates[0], candidates[gsz(candidates) - 1]);
            candidates.pop_back();
        }
        else
        {
            int current = 1;
            repe(i, gsz(candidates) - 1) if (res[i] == maximum)
            {
                swap(candidates[i], candidates[current]);
                current++;
            }
            while (gsz(candidates) > current)
                candidates.pop_back();
            swap(candidates[0], candidates[gsz(candidates) - 1]);
        }
    }

    cout << "! " << candidates[0] << " " << candidates[1] << endl;
    int verdict;
    cin >> verdict;
    if (verdict != 1)
        exit(0);
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