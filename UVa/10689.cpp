#include <bits/stdc++.h>
using namespace std;

int period[] = {0, 60, 300, 1500, 15000};
int power[] = {0, 10, 100, 1000, 10000};
int a, b, n, m, T;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> n >> m;
        a %= power[m];
        b %= power[m];
        n %= period[m];
        if (n == 0)
        {
            cout << a << endl;
            continue;
        }
        if (n == 1)
        {
            cout << b << endl;
            continue;
        }
        for (int i = 2; i <= n; i++)
        {
            int temp = b;
            b = (b + a) % power[m];
            a = temp;
        }
        cout << b << endl;
    }
}
