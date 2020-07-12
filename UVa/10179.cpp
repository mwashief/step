#include <bits/stdc++.h>
using namespace std;
vector<int> primes;

void sieve()
{
    bitset<15900UL> visited;
    primes.push_back(2);
    for (int i = 3; i <= 31630; i += 2)
    {
        if (visited[(i - 3) / 2] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= 31630; j += 2 * i)
            {
                visited[(j - 3) / 2] = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    sieve();
    int x;
    while (cin >> x && x)
    {
        int ans = x;
        for (int i = 0; i < primes[i] && primes[i] <= x; i++)
        {
            if (x % primes[i] == 0)
            {
                ans = ans / primes[i] * (primes[i] - 1);
                while (x % primes[i] == 0)
                    x /= primes[i];
            }
        }
        if (x != 1)
            ans = ans / x * (x - 1);
        cout << ans << endl;
    }
    return 0;
}
