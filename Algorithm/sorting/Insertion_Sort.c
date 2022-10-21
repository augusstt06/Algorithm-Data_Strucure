#include <stdio.h>
#include <string.h>

void InsertionSort(int dataSet[], int length)
{
    int i = 0, j = 0, value = 0;

    for (i = 1; i < length; i++)
    {
        if (dataSet[i - 1] <= dataSet[i])
            continue;

        value = dataSet[i];

        for (j = 0; j < i; j++)
        {
            if (dataSet
                    [j] > value)
            {
                // memmove() : 메모리의 내용을 이동시키는 함수
                // memmove(원본 데이터가 이동할 새로운 메모리 주소, 원본 데이터 주소, 이동시킬 데이터의 양/byte)
                memmove(&dataSet[j + 1], &dataSet[j], sizeof(dataSet[0]) * (i - j));
                dataSet[j] = value;
                break;
            }
        }
    }
}

int main(void)
{
    int dataSet[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof dataSet / sizeof dataSet[0];
    int i = 0;

    InsertionSort(dataSet, length);
    for (i = 0; i < length; i++)
    {
        printf("%d ", dataSet[i]);
    }
    printf("\n");
    return 0;
}