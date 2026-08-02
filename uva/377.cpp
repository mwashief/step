#include <bits/stdc++.h>
using namespace std;
char digits[] = {'V', 'U', 'C', 'D'};

string numTostring(int n)
{
    string s("VVVVVVVV");
    for (int i = 7; i >= 0; i--, n /= 4)
    {
        s[i] = digits[n % 4];
    }
    return s;
}

int stringToNum(string s)
{
    int num = 0;
    int mul = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int digit = 0;
        if (s[i] == 'D')
            digit = 3;
        else if (s[i] == 'C')
            digit = 2;
        else if (s[i] == 'U')
            digit = 1;
        num += digit * mul;
        mul *= 4;
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    cout << "COWCULATIONS OUTPUT" << endl;
    while (N--)
    {
        string n1, n2, ans;
        cin >> n1 >> n2;
        string operations[3];
        cin >> operations[0] >> operations[1] >> operations[2];
        cin >> ans;
        int num1 = stringToNum(n1);
        int num2 = stringToNum(n2);
        for (int i = 0; i < 3; i++)
        {
            if (operations[i] == "A")
                num2 += num1;
            else if (operations[i] == "R")
                num2 /= 4;
            else if (operations[i] == "L")
                num2 *= 4;
        }
        if (numTostring(num2) == ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    cout << "END OF OUTPUT" << endl;
}
