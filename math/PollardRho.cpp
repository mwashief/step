#include <bits/stdc++.h>
using namespace std;

ostream &operator<<(ostream &os, const __int128 i) noexcept
{
    ostream::sentry s(os);
    if (s)
    {
        unsigned __int128 tmp = i < 0 ? -i : i;
        char buffer[128];
        char *d = end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (i < 0)
        {
            --d;
            *d = '-';
        }
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len)
        {
            os.setstate(ios_base::badbit);
        }
    }
    return os;
}

istream &operator>>(istream &is, __int128 &i) noexcept
{
    __int128_t sign = 1;
    char c;
    bool start = 0;
    i = 0;
    while (is.get(c))
    {
        if (c >= '0' && c <= '9')
        {
            start = true;
            i = i * 10;
            i = i + (c - '0');
        }
        else if (!start && c == '-')
            sign = sign * -1;
        else if (start)
            break;
        else
            sign = 1;
    }
    i = i * sign;
    return is;
}

template <class T>
T factorize(T n)
{
    cout << n << endl;
    if (n % 2 == 0)
        return 2;
    T x, y;
    x = y = 1;
    T g = 1;
    while (g == 1)
    {
        x = (x * x + 1) % n;
        y = ((y * y % n + 1) * (y * y % n + 1) % n + 1) % n;
        T k = x - y;
        if (k < 0)
            k = -k;
        g = __gcd(k, n);
    }
    return g;
}

template <class T>
void findAllFactors(T n)
{
    while (n != 1)
    {
        T x = factorize(n);
        cout << x << " ";
        n /= x;
    }
    cout << endl;
}

int main()
{
    __int128_t d = 143;
    findAllFactors(d);
}
