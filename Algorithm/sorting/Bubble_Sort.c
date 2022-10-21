#include <stdio.h>

void BubbleSort(int dataSet[], int length)
{
    int i = 0, j = 0, temp = 0;

    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - (i + 1); j++)
        {
            if (dataSet[j] > dataSet[j + 1])
            {
                temp = dataSet[j + 1];
                dataSet[j + 1] = dataSet[j];
                dataSet[j] = temp;
            }
        }
    }
}

int main(void)
{
    int dataSet[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof dataSet / sizeof dataSet[0];
    int i = 0;

    BubbleSort(dataSet, length);

    for (i = 0; i < length; i++)
    {
        printf("%d ", dataSet[i]);
    }
    printf("\n");
    return 0;
}