/*
    Washief Hossain Mugdho
    16 October 2022
    Codeforces 1501-1750 1746 1746E1
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

bool query(vi &a, int l, int r)
{
    cout << "? " << r - l + 1 << " ";
    for (int i = l; i <= r; i++)
        cout << a[i] << " ";
    cout << endl;
    string s;
    cin >> s;
    if (s == "NO")
        return false;
    return true;
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
    int n;
    cin >> n;
    vi cur(n);
    iota(a2z(cur), 1);

    while (gsz(cur) > 3)
    {
        int mid = gsz(cur) / 2;
        int secMid = mid + (gsz(cur) - mid - 1) / 2;

        bool a = query(cur, 0, mid - 1);

        if (a == false)
        {
            reverse(a2z(cur));
            mid = gsz(cur) - mid;
            secMid = mid + (gsz(cur) - mid - 1) / 2;
        }

        bool b = query(cur, mid, secMid);

        if (b == true)
        {
            vi temp;
            rep(i, secMid + 1) temp.pb(cur[i]);
            cur = temp;
        }
        else
        {
            vi temp;
            rep(i, mid) temp.pb(cur[i]);
            for (int i = secMid + 1; i < gsz(cur); i++)
                temp.pb(cur[i]);
            cur = temp;
        }
    }

    if (gsz(cur) == 3)
    {
        if (query(cur, 0, 0))
        {
            if (query(cur, 1, 1))
                cur = {cur[0], cur[1]};
            else
                cur = {cur[0], cur[2]};
        }
        else
        {
            if (query(cur, 0, 0))
            {
                if (query(cur, 1, 1))
                    cur = {cur[0], cur[1]};
                else
                    cur = {cur[0], cur[2]};
            }
            else
                cur = {cur[1], cur[2]};
        }
    }

    for (auto a : cur)
    {
        cout << "! " << a << endl;
        string s;
        cin >> s;
        if (s == ":)")
            return 0;
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