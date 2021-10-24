/*
    Washief Hossain Mugdho
    24 October 2021
    Codeforces 1582D
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
#define MAX 10000

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
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    if (n & 1)
    {
        if (n > MAX)
        {
            umii m;
            int x, y;
            rep(i, n)
            {
                if (m[abs(a[i])])
                {
                    x = m[abs(a[i])] - 1;
                    y = i;
                    break;
                }
                m[abs(a[i])] = i + 1;
            }
            useti ss;
            rep(i, n) ss.insert(i);
            ss.erase(x);
            vi b(n);
            while (gsz(ss))
            {
                int p = *ss.begin();
                ss.erase(ss.begin());
                int q = *ss.begin();
                ss.erase(ss.begin());
                b[p] = a[q];
                b[q] = -a[p];
            }
            b[x] = 1;
            if (a[x] == a[y])
            {
                b[y]--;
                if (b[y] == 0)
                {
                    b[y]--;
                    b[x]++;
                }
            }
            else
            {
                b[y]++;
                if (b[y] == 0)
                {
                    b[y]++;
                    b[x]++;
                }
            }
            rep(i, n) cout << b[i] << " ";
            cout << endl;
        }
        else
        {
            if (a[0] + a[1] != 0)
                cout << a[2] << " " << a[2] << " " << -a[0] - a[1] << " ";
            else if (a[1] + a[2] != 0)
                cout << -a[1] - a[2] << " " << a[0] << " " << a[0] << " ";
            else
                cout << a[1] << " " << -a[0] - a[2] << " " << a[1] << " ";
            for (int i = 3; i < n; i += 2)
            {
                a[i] = -a[i];
                swap(a[i], a[i + 1]);
                cout << a[i] << " " << a[i + 1] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            a[i] = -a[i];
            swap(a[i], a[i + 1]);
        }
        rep(i, n) cout << a[i] << " ";
        cout << endl;
    }
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
*/
