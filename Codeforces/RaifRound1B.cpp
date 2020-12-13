/*
    Washief Hossain Mugdho
    13 December 2020
    Codeforces RaifRound1B
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

ll takentime(ll length, ll segs)
{
    ll segLen = length / segs;
    ll longer = length % segs;
    ll newCost = (longer) * (segLen + 1) * (segLen + 1) + (segs - longer) * segLen * segLen;
    return newCost;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    ll n, k, x;
    priority_queue<pair<ll, pair<ll, ll>>> PQ;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        PQ.push({takentime(x, 1) - takentime(x, 2), {x, 2}});
    }
    while (n < k)
    {
        auto top = PQ.top();
        x = top.sc.fr;
        ll segs = top.sc.sc;
        PQ.pop();
        n++;
        PQ.push({takentime(x, segs) - takentime(x, segs + 1), {x, segs + 1}});
    }
    ll ans = 0;
    while (!PQ.empty())
    {
        auto top = PQ.top();
        x = top.sc.fr;
        ll segs = top.sc.sc - 1;
        PQ.pop();
        ans += takentime(x, segs);
    }
    cout << ans << endl;
}
