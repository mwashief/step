/*
    Washief Hossain Mugdho
    06 August 2020
    LightOJ 1140
*/

#pragma GCC optimize("O3")
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

ll howMany(ll n)
{
    if (n<0) return 0;
    ll k =10;
    ll ans =0;
    while (n>=k)
    {
        ll d = n/k;
        ans = ans+(d-1)*(k/10);
        ans += min(k/10, n-d*k+1);
        k*=10;
    }
    return ans+1;
}

inline ll inBetween(ll a, ll b)
{
    return howMany(b) - howMany(a-1);
}


int main()
{
    int T;
    cin >> T;
    for (int tt=1; tt<=T; tt++)
    {
        ll a, b;
        cin >> a >> b;
        cout << "Case " << tt << ": " << inBetween(a, b) << endl;
    }
}

