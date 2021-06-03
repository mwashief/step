/*
    Washief Hossain Mugdho
    03 June 2021
    Codeforces 1001-1250 1213 1213F
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
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
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
#endif
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n, k, now = -1;
    cin >> n >> k;
    vi a(n), b(n), res(n, -1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int i = 0;
    while (i < n)
    {
        now = min(25, now + 1);
        res[a[i] - 1] = now;
        res[b[i] - 1] = now;
        i++;
        useti unseena, unseenb;
        if (a[i - 1] == b[i - 1])
            continue;
        else
        {
            unseena.insert(b[i - 1]);
            unseenb.insert(a[i - 1]);
        }
        while (unseena.size())
        {
            if (unseena.find(a[i]) != unseena.end())
                unseena.erase(a[i]);
            else
                unseenb.insert(a[i]);

            if (unseenb.find(b[i]) != unseena.end())
                unseenb.erase(b[i]);
            else
                unseena.insert(b[i]);
            res[a[i] - 1] = now;
            res[b[i] - 1] = now;
            i++;
        }
    }

    if (now < k - 1)
    {
        pno << endl;
        return 0;
    }
    pyes << endl;
    rep(i, n) cout << char(res[i] + 'a');
    cout << endl;
}