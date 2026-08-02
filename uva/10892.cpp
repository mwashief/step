#include <bits/stdc++.h>
#define MAX 200000000
using namespace std;
vector<int> primes;

void sieve()
{
    primes.push_back(2);
    bitset<44730> visited;
    for (int i = 3; i <= 44725; i += 2)
    {
        if (visited[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= 44725; j += 2 * i)
                visited[j] = 1;
        }
    }
}

int main()
{
    int x;
    sieve();
    while (cin >> x)
    {
        if (!x)
            return 0;
        bool square = false;
        int ans = 1;
        int temp = x;
        cout << x << " ";
        for (int i = 0; primes[i] * primes[i] <= x; i++)
        {
            int power = 0;
            bool first = false;
            if (x == temp)
                first = true;
            while (x % primes[i] == 0)
            {
                x /= primes[i];
                power++;
            }
            ans = ans + 2 * ans * power - power;
        }
        if (x != 1)
        {
            ans = ans + 2 * ans - 1;
        }
        cout << ans << endl;
    }
}
