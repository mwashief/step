#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Z, I, M, L, caseN = 1;
    while (cin >> Z >> I >> M >> L && M)
    {
        int rabbit = L, tort = L;
        while (1)
        {
            rabbit = (Z * rabbit + I) % M;
            rabbit = (Z * rabbit + I) % M;
            tort = (Z * tort + I) % M;
            if (rabbit == tort)
                break;
        }
        tort = L;
        while (rabbit != tort)
        {
            tort = (Z * tort + I) % M;
            rabbit = (Z * rabbit + I) % M;
        }
        int length = 1;
        rabbit = rabbit = (Z * rabbit + I) % M;
        while (rabbit != tort)
        {
            length++;
            rabbit = (Z * rabbit + I) % M;
        }
        cout << "Case " << caseN << ": " << length << endl;
        caseN++;
    }
}
