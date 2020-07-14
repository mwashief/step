#include <bits/stdc++.h>
using namespace std;

long long egcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main(int argc, char const *argv[])
{
    long long n, k;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        long long x, y;
        long long g = egcd(n / k, ceil(1.0 * n / k), x, y);
        cout << x * n / g << " " << y * n / g << endl;
    }
}
