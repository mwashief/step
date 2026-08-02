#include <bits/stdc++.h>
using namespace std;
vector<int> primes;

void sieve()
{
    bitset<510UL> visited;
    primes.push_back(2);
    for (int i = 3; i <= 1005; i += 2)
    {
        if (visited[(i - 3) / 2] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j > i && j <= 1005; j += 2 * i)
            {
                visited[(j - 3) / 2] = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    sieve();
    int n;
    while (cin >> n && n)
    {
        int temp = n;
        int c = 0;
        for (int i = 0; i < primes.size() && i <= n; i++)
        {
            if (n % primes[i] == 0)
            {
                c++;
                while (n % primes[i] == 0)
                    n /= primes[i];
            }
        }
        if (n != 1)
            c++;
        cout << temp << " : " << c << endl;
    }
    return 0;
}
