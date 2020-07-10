#include <bits/stdc++.h>
using namespace std;
vector<long long> sibling1;
vector<long long> sibling2;
bitset<10000000> odds;

void gen()
{
    for (long long i = 3; i < 20000000; i += 2)
    {
        unsigned index = (i - 3) / 2;
        if (odds[index] == 0)
        {
            for (long long j = i * i; j > i && j < 20000000; j += 2 * i)
            {
                odds[(j - 3) / 2] = 1;
            }
            if (index != 0 && odds[index - 1] == 0)
            {
                sibling1.push_back(2 * (index - 1) + 3);
                sibling2.push_back(i);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    gen();
    long long x;
    while (cin >> x)
    {
        cout << "(" << sibling1[x - 1] << ", " << sibling2[x - 1] << ")" << endl;
    }
    return 0;
}
