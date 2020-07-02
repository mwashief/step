#include <bits/stdc++.h>
using namespace std;

int main()
{
    string variable;
    string polynomial;
    string EOFS;
    EOFS.push_back(24);
    while (getline(cin, variable))
    {
        if (variable == EOFS)
            return 0;

        int value;
        int variableValue;
        istringstream variable_stream(variable);
        variable_stream >> variableValue;

        getline(cin, polynomial);
        vector<int> polynomials;
        istringstream polynomial_stream(polynomial);
        while (polynomial_stream >> value)
        {
            polynomials.push_back(value);
        }

        int result = 0;
        int mul = 1;
        for (int j = polynomials.size() - 2; j >= 0; j--)
        {
            result += polynomials[j] * mul * (polynomials.size() - 1 - j);
            mul *= variableValue;
        }

        cout << result << endl;
    }
}