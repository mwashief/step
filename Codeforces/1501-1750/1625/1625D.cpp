/*
    Washief Hossain Mugdho
    12 January 2022
    Codeforces 1501-1750 1625 1625D
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

vi taken;

vi choose2(vvi &a, int ind, int k)
{
    if (ind < 0)
    {
        if (gsz(a[0]) && gsz(a[1]))
            return {a[0][0], a[1][0]};
        return {};
    }
    if (gsz(a[0]) == 0 && gsz(a[1]) == 0)
        return {};
    vector<vvi> all(2, vvi(2));
    for (auto d : a[0])
        if (d & (1 << ind))
            all[0][1].pb(d);
        else
            all[1][0].pb(d);
    for (auto d : a[1])
        if (d & (1 << ind))
            all[1][1].pb(d);
        else
            all[0][0].pb(d);
    if ((1 << ind) > k)
    {
        if (gsz(all[0][0]) && gsz(all[0][1]))
            return {all[0][0][0], all[0][1][0]};
        if (gsz(all[1][0]) && gsz(all[1][1]))
            return {all[1][0][0], all[1][1][0]};
        all.clear();
        return choose2(a, ind - 1, k);
    }
    a.clear();
    k = k ^ (1 << ind);

    auto c = choose2(all[0], ind - 1, k);
    if (gsz(c))
        return c;
    return choose2(all[1], ind - 1, k);
}

void traverse(vi &all, int ind, int k)
{
    if (gsz(all) == 0)
        return;
    if (ind < 0)
    {
        for (auto d : all)
            taken.pb(d);
        return;
    }
    vvi a(2);
    for (auto d : all)
    {
        if (d & (1 << ind))
            a[1].pb(d);
        else
            a[0].pb(d);
    }
    int temp = all[0];
    all.clear();
    if ((1 << ind) > k)
    {
        traverse(a[0], ind - 1, k);
        traverse(a[1], ind - 1, k);
        return;
    }
    k = k ^ (1 << ind);
    auto res = choose2(a, ind - 1, k);
    if (gsz(res) == 0)
        res.pb(temp);
    for (auto d : res)
        taken.pb(d);
    cout << "";
}

int main()
{
    fastio;
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#endif
    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, vi> all;
    rep(i, n)
    {
        cin >> a[i];
        all[a[i]].pb(i + 1);
    }
    traverse(a, 30, k);
    if (gsz(taken) < 2)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << gsz(taken) << endl;
    for (auto d : taken)
    {
        cout << all[d].back() << " ";
        all[d].pop_back();
    }
    cout << endl;
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