/*
    Washief Hossain Mugdho
    14 August 2020
    LightOJ 1105
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
ull memo[100];

ull fib(int n)
{
    if (memo[n])
        return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main()
{
    memo[0] = 1;
    memo[1] = 1;
    fib(80);
    int T;
    ull n;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n;
        bool taken = false;
        cout << "Case " << tt << ": ";
        for (int i = 55; i >= 1; i--)
        {
            if (n >= memo[i])
            {
                cout << 1;
                n -= memo[i];
                taken = true;
            }
            else if (taken)
                cout << 0;
        }
        cout << endl;
    }
}
