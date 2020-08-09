/*
    Washief Hossain Mugdho
    30 July 2020
    UVa 10976
*/
#include <stdio.h>
int arr[2][12009];

int main()
{
    int k;
    while (scanf("%d", &k) == 1)
    {
        int i;
        int total = 0;
        for (i = k + 1; i <= 2 * k; i++)
        {
            int y = i * k / (i - k);
            if (i * k == y * (i - k))
            {
                arr[0][total] = y;
                arr[1][total] = i;
                total++;
            }
        }
        printf("%d\n", total);
        for (i = 0; i < total; i++)
            printf("1/%d = 1/%d + 1/%d\n", k, arr[0][i], arr[1][i]);
    }
}
