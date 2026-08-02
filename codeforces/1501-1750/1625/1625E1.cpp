/*
    Washief Hossain Mugdho
    14 January 2022
    Codeforces 1501-1750 1625 1625E1
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
ll memo[300005];

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0;
    map<pii, int> node;
    mii level;
    vector<pair<char, int>> stk;
    vector<vpii> forests;
    vi rbsl;
    vi rbsr;
    rep(i, n)
    {
        if (s[i] == '(')
            stk.pb({'(', i});
        else if (gsz(stk) && stk.back().fr == '(')
        {
            auto last = stk.back();
            stk.pop_back();
            int l = 0, r = gsz(rbsl);
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (rbsl[mid] >= last.sc)
                    r = mid;
                else
                    l = mid + 1;
            }
            ll total = gsz(rbsl) - l;
            ll val = 0;
            if (total)
                forests.pb(vpii());
            while (gsz(rbsl) > l)
            {
                val += memo[node[{rbsl.back(), rbsr.back()}]];
                forests.back().pb({rbsl.back(), rbsr.back()});
                level[rbsl.back()] = gsz(forests) - 1;
                rbsl.pop_back();
                rbsr.pop_back();
            }
            val += total * (total - 1) / 2LL;
            val++;
            memo[cnt] = val;
            node[{last.sc, i}] = cnt;
            cnt++;
            rbsl.pb(last.sc);
            rbsr.pb(i);
        }
        else
            stk.pb({')', i});
    }
    if (gsz(rbsl) > 1)
    {
        forests.pb(vpii());
        rrep(i, gsz(rbsl))
        {
            forests.back().pb({rbsl[i], rbsr[i]});
            level[rbsl[i]] = gsz(forests) - 1;
        }
    }

    vvl prefix;
    rep(i, gsz(forests))
    {
        reverse(a2z(forests[i]));
        prefix.pb(vl(gsz(forests[i]) + 1));
        repe(j, gsz(forests[i])) prefix.back()[j] = prefix.back()[j - 1] + memo[node[forests[i][j - 1]]];
    }

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (node.find({l, r}) != node.end())
            cout << memo[node[{l, r}]] << endl;
        else
        {
            int f = level[l];
            vpii &rf = forests[f];
            int left = 0, right = gsz(rf) - 1;
            while (left < right)
            {
                int mid = (left + right) >> 1;
                if (rf[mid].fr >= l)
                    right = mid;
                else
                    left = mid + 1;
            }
            int lb = left;
            left = 0;
            right = gsz(rf) - 1;
            while (left < right)
            {
                int mid = (left + right) >> 1;
                if (rf[mid].sc >= r)
                    right = mid;
                else
                    left = mid + 1;
            }
            int rb = left;
            ll total = rb - lb + 1;
            ll val = prefix[f][rb + 1] - prefix[f][lb];
            val += total * (total - 1) / 2LL;
            cout << val << endl;
        }
    }
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