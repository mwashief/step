#include <bits/stdc++.h>
using namespace std;

long long factorize(long long n)
{
    if (n % 2 == 0)
        return 2;
    long long x, y;
    x = y = 1;
    long long g = 1;
    while (g == 1)
    {
        x = (x * x + 1) % n;
        y = ((y * y + 1) * (y * y + 1) + 1) % n;
        g = __gcd(abs(x - y), n);
    }
    return g;
}

void findAllFactors(long long n)
{
    while (n != 1)
    {
        long long x = factorize(n);
        cout << x << " ";
        n /= x;
    }
    cout << endl;
}

int main()
{
    findAllFactors(260);
}