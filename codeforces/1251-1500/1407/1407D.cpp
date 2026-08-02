/*
    Washief Hossain Mugdho
    13 June 2021
    Codeforces 1251-1500 1407 1407D
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
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];

    vvi adj(n);
    stack<int> leseq, grtr;
    rep(i, n - 1) adj[i].pb(i + 1);
    rep(i, n)
    {
        while (leseq.size() && h[leseq.top()] < h[i])
            leseq.pop();
        while (grtr.size() && h[grtr.top()] > h[i])
            grtr.pop();
        if (leseq.size() && leseq.top() != i - 1)
            adj[leseq.top()].pb(i);
        if (grtr.size() && grtr.top() != i - 1)
            adj[grtr.top()].pb(i);
        leseq.push(i);
        grtr.push(i);
    }
    while (leseq.size())
        leseq.pop();
    while (grtr.size())
        grtr.pop();
    rrep(i, n)
    {
        while (leseq.size() && h[leseq.top()] < h[i])
            leseq.pop();
        while (grtr.size() && h[grtr.top()] > h[i])
            grtr.pop();
        if (leseq.size() && leseq.top() != i + 1)
            adj[i].pb(leseq.top());
        if (grtr.size() && grtr.top() != i + 1)
            adj[i].pb(grtr.top());
        leseq.push(i);
        grtr.push(i);
    }

    vi d(n, -1);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto vertex : adj[u])
            if (d[vertex] == -1)
            {
                d[vertex] = d[u] + 1;
                q.push(vertex);
            }
    }
    cout << d[n - 1] << endl;
}