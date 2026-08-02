/*
    Washief Hossain Mugdho
    04 October 2020
    Educational DP Frog3
    Convex Hull Trick
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;

int n;
ll c, h;

struct line
{
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double)(c - l.c) / (l.m - m); }
};

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> c;
    deque<line> dq;
    cin >> h;
    dq.push_back({-2 * h, h * h});
    for (int i = 2; i <= n; i++)
    {
        cin >> h;
        while (dq.size() >= 2 && dq[0].eval(h) >= dq[1].eval(h))
            dq.pop_front();
        long long f = dq[0].eval(h) + h * h + c;
        if (i == n)
        {
            cout << f << endl;
            return 0;
        }
        line cur = {-2 * h, f + h * h};
        while (dq.size() >= 2 && cur.intersectX(dq.back()) <= dq[dq.size() - 2].intersectX(dq.back()))
            dq.pop_back();
        dq.push_back(cur);
    }
}
