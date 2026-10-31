#include <stdio.h>

int main()
{
    int a[50], n, i, j, temp;

    printf("=== E-COMMERCE PRODUCT PRICE SORTING ===\n");
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter price of %d items:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nPrices sorted from Low to High:\n");
    for (i = 0; i < n; i++)
    {
        printf("Rs. %d\n", a[i]);
    }

    return 0;
}
