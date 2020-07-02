#include <bits/stdc++.h>
using namespace std;

int main()
{
    string polynomial;
    string variable;
    string EOFS;
    EOFS.push_back(24);
    while (getline(cin, polynomial))
    {
        if (polynomial == EOFS)
            return 0;

        int value;
        vector<int> polynomials;
        istringstream polynomial_stream(polynomial);
        while (polynomial_stream >> value)
        {
            polynomials.push_back(value);
        }

        getline(cin, variable);
        vector<int> variables;
        istringstream variable_stream(variable);
        while (variable_stream >> value)
        {
            variables.push_back(value);
        }
        for (int i = 0; i < variables.size(); i++)
        {
            int result = 0;
            int mul = 1;
            for (int j = polynomials.size() - 1; j >= 0; j--)
            {
                result += polynomials[j] * mul;
                mul *= variables[i];
            }
            if (i)
                cout << " ";
            cout << result;
        }
        cout << endl;
    }
}