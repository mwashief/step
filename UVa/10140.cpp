#include <bits/stdc++.h>
#define MAX 1000000
#define SUPER 2147483647
using namespace std;
vector<unsigned int> primes;
bool visited[MAX];

void generate()
{
    primes.push_back(2);
    for (unsigned int i = 3; i < MAX; i += 2)
    {
        if (!visited[i])
        {
            primes.push_back(i);
            for (unsigned int j = i * i; j > i && j < MAX; j += i)
                visited[j] = true;
        }
    }
}

bool isPrime(unsigned int n)
{
    if (n < MAX)
        return binary_search(primes.begin(), primes.end(), n);
    auto finish = upper_bound(primes.begin(), primes.end(), sqrt(n));
    for (auto it = primes.begin(); it != finish; it++)
    {
        if (n % (*it) == 0)
            return false;
    }
    return true;
}

unsigned getNextPrime(unsigned int n)
{
    auto last = upper_bound(primes.begin(), primes.end(), n);
    if (last != primes.end())
        return *last;
    for (unsigned int i = n + 1;; i++)
        if (isPrime(i))
            return i;
}

int main(int argc, char const *argv[])
{
    generate();
    unsigned int x, L, U, C1, C2, D1, D2, g1, g2;

    while (cin >> L >> U)
    {
        g1 = 1000005;
        g2 = 0;
        unsigned int current = getNextPrime(L - 1);
        unsigned int next = getNextPrime(L - 1);
        while (next <= U)
        {
            if ((next - current) && next - current < g1)
            {
                C1 = current;
                C2 = next;
                g1 = next - current;
            }
            if (next - current > g2)
            {
                D1 = current;
                D2 = next;
                g2 = next - current;
            }
            current = next;
            next = getNextPrime(current);
        }
        if (g2 == 0)
        {
            cout << "There are no adjacent primes." << endl;
        }
        else
        {
            cout << C1 << "," << C2 << " are closest, " << D1 << "," << D2 << " are most distant." << endl;
        }
    }

    return 0;
}
