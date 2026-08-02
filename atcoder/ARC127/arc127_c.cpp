/*
    Washief Hossain Mugdho
    27 September 2021
    AtCoder ARC127 arc127_c
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
    int n;
    string x, res = "1";
    cin >> n >> x;
    auto decrement = [&](string &s)
    {
        rrep(i, gsz(s)) if (s[i] == '0') s[i] = '1';
        else
        {
            s[i] = '0';
            return i;
        }
        return -1;
    };

    if (decrement(x) == -1)
    {
        cout << 1 << endl;
        return 0;
    }
    int j = 0;
    while (j < gsz(x) && x[j] == '0')
        j++;
    x = x.substr(j);
    string y;
    while (gsz(x) + gsz(y) < n)
        y.pb('0');
    x = y + x;

    rep(i, n)
    {
        if (x[i] == '1')
        {
            res.pb('1');
            x[i] = '0';
        }
        else
        {
            if (decrement(x) == -1)
                break;
            else
                res.pb('0');
        }
    }
    cout << res << endl;
}