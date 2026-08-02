#include <bits/stdc++.h>
using namespace std;

long long egcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main(int argc, char const *argv[])
{
    long long A, B;
    while (cin >> A >> B)
    {
        long long x, y;
        long long g = egcd(A, B, x, y);
        cout << x << " " << y << " " << g << endl;
    }
}
