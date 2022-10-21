#include <stdio.h>

void BubbleSort(int dataSet[], int length)
{
    int i = 0, j = 0, temp = 0;

    // 매개변수로 받은 자료구조의 크기만큼 내부의 for문 실행
    for (i = 0; i < length - 1; i++)
    {
        // 첫번째 for문이 실행 될 때마다 실행 횟수가 1회 감소
        // 정렬대상의 자료크기가 줄어들기 때문
        for (j = 0; j < length - (i + 1); j++)
        {
            if (dataSet[j] > dataSet[j + 1])
            {
                temp = dataSet[j + 1];
                dataSet[j + 1] = dataSet[j];
                dataSet[j] = temp;
            }
            else
            {
                continue;
            }
        }
    }
}

int main(void)
{
    int dataSet[] = {6, 4, 2, 3, 1, 5};
    // sizeof를 이용하여 배열의 길이를 구하고 length 초기화
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