#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long N;
    while (cin >> N && N)
    {
        unsigned long long a, b;
        cin >> a >> b;
        unsigned long long tort, rabbit;
        tort = rabbit = 0;
        while (1)
        {
            tort = (a * tort % N * tort % N + b) % N;
            rabbit = (a * rabbit % N * rabbit % N + b) % N;
            rabbit = (a * rabbit % N * rabbit % N + b) % N;
            if (tort == rabbit)
                break;
        }

        unsigned long long lambda = 0;

        while (1)
        {
            lambda++;
            rabbit = (a * rabbit % N * rabbit % N + b) % N;
            if (tort == rabbit)
                break;
        }
        cout << N - lambda << endl;
    }
}
