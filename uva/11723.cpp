#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, N;
    int caseNo = 1;
    while (1)
    {
        cin >> R >> N;
        if (N * R == 0)
            return 0;
        int result = (R + N - 1) / N - 1;
        if (result > 26)
        {
            cout << "Case " << caseNo << ": impossible\n";
        }
        else
            cout << "Case " << caseNo << ": " << result << "\n";
        caseNo++;
    }
}
