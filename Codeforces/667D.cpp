/*
    Washief Hossain Mugdho
    10 October 2020
    Codeforces 667D
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

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    fastio;
    untie;
    int T, s;
    cin >> T;
    ull n;
    while (T--)
    {
        cin >> n >> s;
        ull temp = n;
        int sum = 0;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum <= s)
        {
            cout << 0 << endl;
            continue;
        }
        s = sum - s + 1;
        ull p = 1;
        temp = n;
        ull __digit = n;
        while (s > 0)
        {
            ull digit = __digit % 10;
            __digit /= 10;
            s -= digit;
            temp -= digit * p;
            p *= 10;
        }
        temp += p;
        cout << temp - n << endl;
    }
}
