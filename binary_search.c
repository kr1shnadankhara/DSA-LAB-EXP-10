#include <stdio.h>

int main()
{
    int A[50], N, VAL;
    int POS = -1, LOW, HIGH, MID;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter elements in sorted order:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &VAL);

    LOW = 0;
    HIGH = N - 1;

    while (LOW <= HIGH)
    {
        MID = (LOW + HIGH) / 2;
        if (VAL == A[MID])
        {
            POS = MID;
            printf("POS = %d\n", POS);
            break;
        }
        else if (VAL < A[MID])
        {
            HIGH = MID - 1;
        }
        else
        {
            LOW = MID + 1;
        }
    }

    if (POS == -1)
    {
        printf("VALUE IS NOT PRESENT IN THE ARRAY\n");
    }

    return 0;
}
