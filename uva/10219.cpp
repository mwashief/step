/*
    Washief Hossain Mugdho
    24 August 2020
    UVa 10219
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

int main()
{
    ll n, k;
    while (cin >> n >> k)
    {
        double ans = 1.0;
        ll a = min(k, n - k);
        ll b = max(k, n - k);
        for (int i = b + 1; i <= n; i++)
        {
            ans += log10(i);
            if (a > 1)
            {
                ans -= log10(a);
                a--;
            }
        }
        for (int i = 2; i <= a; i++)
            ans -= log10(i);
        cout << (ll)ans << endl;
    }
}
