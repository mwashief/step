#include <bits/stdc++.h>
using namespace std;
vector<int> primes;

void sieve()
{
    bitset<3165UL> visited;
    primes.push_back(2);
    for (int i = 3; i <= 3163; i += 2)
    {
        if (visited[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= 3163; j += 2 * i)
            {
                visited[j] = 1;
            }
        }
    }
}

int power(int n, int m)
{
    if (m == 0)
        return 1;
    int half = power(n, m / 2);
    half *= half;
    if (m & 1)
        half *= n;
    return half;
}

unordered_map<int, int> factorize(int n)
{
    unordered_map<int, int> factors;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            while (n % primes[i] == 0)
            {
                factors[primes[i]]++;
                n /= primes[i];
            }
        }
    }
    if (n != 1)
    {
        factors[n] = 1;
    }
    return factors;
}

int main(int argc, char const *argv[])
{
    sieve();
    int T, A, C;
    cin >> T;
    while (T--)
    {
        cin >> A >> C;
        auto a = factorize(A);
        auto c = factorize(C);
        int b = 1;
        for (auto it = c.begin(); it != c.end(); it++)
        {
            if (a[it->first] > it->second)
            {
                b = -1;
                break;
            }
            else if (a[it->first] < it->second)
            {
                b *= power(it->first, it->second);
            }
            a.erase(it->first);
        }
        if (b < 1 || a.size())
            cout << "NO SOLUTION" << endl;
        else
            cout << b << endl;
    }
    return 0;
}
