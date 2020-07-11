#include <bits/stdc++.h>
#define MAX 104000000000000
using namespace std;
vector<long long> primes;

void sieve()
{
    bitset<5100000UL> *v = new bitset<5100000UL>();
    bitset<5100000UL> &visited = *v;
    primes.push_back(2);
    long long limit = sqrt(MAX) + 1;
    for (long long i = 3; i <= limit; i += 2)
    {
        if (visited[(i - 3) / 2] == 0)
        {
            primes.push_back(i);
            for (long long j = i * i; j < i && j <= limit; j += 2 * i)
            {
                visited[(j - 3) / 2] = 1;
            }
        }
    }
    delete v;
}

int main(int argc, char const *argv[])
{
    sieve();
    long long x;
    while (cin >> x && x != 0)
    {
        long long factors = 0;
        long long divisible = 0;
        if (x < 0)
            x = -x;
        for (int i = 0; i < primes.size() && x > 1; i++)
        {
            if (x % primes[i] == 0)
            {
                factors++;
                divisible = primes[i];
                while (x % primes[i] == 0)
                    x /= primes[i];
            }
        }
        if (x == 1)
        {
            if (factors > 1)
                cout << divisible << endl;
            else
                cout << -1 << endl;
        }
        else
        {
            if (factors > 0)
                cout << x << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
