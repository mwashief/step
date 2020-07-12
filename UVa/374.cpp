#include <bits/stdc++.h>
using namespace std;

long long bigMod(long long a, long long b, long long M)
{
    if (b == 0)
        return 1;
    long long result = bigMod(a, b / 2, M);
    result = (result * result) % M;
    if (b & 1)
        result = (result * a) % M;
    return result;
}

int main()
{
    long long a, b, M;
    while (cin >> a >> b >> M)
        cout << bigMod(a, b, M) << endl;
}