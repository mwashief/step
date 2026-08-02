#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX 4294967296
using namespace std;
vector<unsigned long long> primes;

void sieve()
{
    primes.push_back(2);
    bitset<33000UL> *v = new bitset<33000UL>();
    bitset<33000UL> &visited = *v;
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

int main(int argc, char const *argv[])
{
    sieve();
    ull n;
    while (cin >> n && n)
    {
        ull factors = 1;
        for (int i = 0; i < primes.size() && primes[i] <= n; i++)
        {
            ull t = 1;
            while (n % primes[i] == 0)
            {
                t++;
                n /= primes[i];
            }
            factors *= t;
        }
        if (n != 1)
        {
            cout << "no" << endl;
        }
        else
        {
            if (factors & 1)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}
