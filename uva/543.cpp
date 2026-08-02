#include <bits/stdc++.h>
using namespace std;
set<int> primes;

void generate()
{
    primes.insert(2);
    bool visited[1000009];
    for (int i = 3; i < 1000001; i += 2)
    {
        if (!visited[i])
        {
            primes.insert(i);
            for (int j = i * i; j > i && j < 1000001; j += i)
                visited[j] = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    generate();
    int x;
    while (cin >> x && x)
    {
        for (auto it = primes.begin(); it != primes.end(); it++)
        {
            auto second = primes.find(x - *it);
            if (second != primes.end())
            {
                cout << x << " = " << *it << " + " << *second << endl;
                break;
            }
        }
    }
    return 0;
}
