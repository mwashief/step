#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<int> primes;
ull SODF[2000006];
ull phi[2000006] = {0, 1};
ull depthPhi[2000006];
void sieve()
{
    bitset<2000005> visited;
    for (int i = 1; i < 2000003; i++)
        phi[i] = i;
    for (int i = 2; i <= 2000003; i++)
    {
        if (visited[i] == 0)
        {
            for (int j = i; j <= 2000003; j += i)
            {
                phi[j] = phi[j] / i * (i - 1);
                visited[j] = 1;
            }
        }
        depthPhi[i] = depthPhi[phi[i]] + 1;
        SODF[i] = SODF[i - 1] + depthPhi[i];
    }
}

int main(int argc, char const *argv[])
{
    sieve();
    int T, m, n;
    cin >> T;
    while (T--)
    {
        cin >> m >> n;
        cout << SODF[n] - SODF[m - 1] << endl;
    }
    return 0;
}
