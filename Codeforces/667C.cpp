/*
    Washief Hossain Mugdho
    10 October 2020
    Codeforces 667C
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

    int T, n, x, y;
    cin >> T;

    while (T--)
    {
        cin >> n >> x >> y;
        int gap = y - x;
        int r;

        for (int i = 1; i <= gap; i++)
            if (gap % i == 0 && ((gap / i) + 1 <= n))
            {
                r = i;
                break;
            }
        int temp = y;
        while (temp > 0 && n > 0)
        {
            cout << temp << " ";
            temp -= r;
            n--;
        }
        temp = y + r;
        while (n > 0)
        {
            cout << temp << " ";
            temp += r;
            n--;
        }
        cout << endl;
    }
}
