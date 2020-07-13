#include <bits/stdc++.h>
using namespace std;

unsigned long long egcd(unsigned long long a, unsigned long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    unsigned long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main(int argc, char const *argv[])
{
    unsigned long long n, c1, c2, n1, n2, m1, m2;
    while (cin >> n && n)
    {
        cin >> c1 >> n1 >> c2 >> n2;
        long long x, y;
        unsigned long long g, price = ULLONG_MAX;
        g = egcd(n1, n2, x, y);
        if (n % g != 0)
        {
            cout << "failed" << endl;
            continue;
        }
        n /= g;
        n1 /= g;
        n2 /= g;
        long long low, high;
        long long x1, x2, y1, y2;
        if (x < 0)
        {
            low = ceil(-1.0 * x * n / n2);
            high = floor(y * n / n1);
            x1 = (n2 * low + x * n);
            y1 = (-n1 * low + y * n);
            x2 = (n2 * high + x * n);
            y2 = (-n1 * high + y * n);
        }
        else
        {
            low = ceil(-1.0 * y * n / n1);
            high = floor(x * n / n2);
            x1 = (-n2 * low + x * n);
            y1 = (n1 * low + y * n);
            x2 = (-n2 * high + x * n);
            y2 = (n1 * high + y * n);
        }
        if (low > high)
        {
            cout << "failed" << endl;
            continue;
        }
        if (c1 * x1 + c2 * y1 < c1 * x2 + c2 * y2)
            cout << x1 << " " << y1 << endl;
        else
            cout << x2 << " " << y2 << endl;
    }
    return 0;
}
