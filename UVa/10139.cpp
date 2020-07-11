#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX 2147473647
using namespace std;
vector<unsigned long long> primes;

void sieve()
{
    primes.push_back(2);
    bitset<24000UL> *v = new bitset<24000UL>();
    bitset<24000UL> &visited = *v;
    int len = sqrt(MAX);
    for (int i = 3; i <= len; i += 2)
    {
        if (visited[(i - 3) / 2] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j > i && j <= len; j += 2 * i)
                visited[(j - 3) / 2] = 1;
        }
    }
    delete v;
}

int main()
{
    unsigned long long n, m;
    sieve();
    while (cin >> n >> m)
    {
        bool ok = true;
        int temp = m;
        if (m == 0)
            ok = false;
        for (int i = 0; i < primes.size() && primes[i] <= m; i++)
        {
            if (m % primes[i] == 0)
            {
                unsigned long long t = 0;
                unsigned long long pt = 1;
                unsigned long long c = 0;
                while (m % primes[i] == 0)
                {
                    t++;
                    pt *= primes[i];
                    m /= primes[i];
                    c += n / pt;
                }
                if (t > c)
                {
                    ok = false;
                    break;
                }
            }
        }
        if (m != 1 && m > n)
            ok = false;
        if (ok)
            cout << temp << " divides " << n << "!" << endl;
        else
            cout << temp << " does not divide " << n << "!" << endl;
    }
}