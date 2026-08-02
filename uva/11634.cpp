#include <bits/stdc++.h>
using namespace std;

int next(int n)
{
    n *= n;
    n /= 100;
    return n % 10000;
}

int main()
{
    unsigned long long N;
    while (cin >> N && N)
    {
        unsigned long long tort, rabbit;
        tort = rabbit = N;

        tort = next(tort);
        rabbit = next(next(rabbit));
        while (tort != rabbit)
        {
            tort = next(tort);
            rabbit = next(next(rabbit));
        }

        unsigned long long mu = 0;
        tort = N;
        while (tort != rabbit)
        {
            mu++;
            tort = next(tort);
            rabbit = next(rabbit);
        }

        unsigned long long lambda = 1;
        rabbit = next(rabbit);
        while (rabbit != tort)
        {
            lambda++;
            rabbit = next(rabbit);
        }
        cout << mu + lambda << endl;
    }
}
