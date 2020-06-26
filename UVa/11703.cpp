#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long T;
    cin >> T;
    double d, u, v;
    cout << fixed;
    cout << setprecision(3);
    for (long long t = 1; t <= T; t++)
    {
        cin >> d >> v >> u;
        if (v >= u || v == 0)
        {
            cout << "Case " << t << ": can't determine" << endl;
        }
        else
        {
            double t1 = d / sqrt(u * u - v * v);
            double t2 = d / u;
            cout << "Case " << t << ": " << t1 - t2 << endl;
        }
    }
}