// 피벗값 선정
#include <stdio.h>

// 위치를 바꿔주는 함수
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

// 범위를 나누어 탐색하는 함수
int Partition(int dataSet[], int left, int right)
{
    int first = left;
    // 기준 요소 Pivot 정의
    int pivot = dataSet[first];
    ++left;

    // left값과 right값이 만나지 않을때까지 탐색
    // 만약 두 값이 만나는 순간 반복문 종료
    while (left <= right)
    {
        while (dataSet[left] <= pivot && left < right)
        {
            // dataSet의 left에서 출발하여 pivot보다 큰값을 찾을때까지 loop 수행
            // pivot보다 큰값을 찾으면 left에 해당 값의 인덱스 저장
            ++left;
        }
        while (dataSet[right] >= pivot && left <= right)
        {
            --right;
        }

        if (left < right)
        {
            // 조건이 충족 되었다면 위 연산이 끝난 left값과 right값을 바꾼다.
            swap(&dataSet[left], &dataSet[right]);
        }
        else
        {
            break;
        }
    }
    // 위의 loop가 끝나면 기존의 기준요소와 새로운 기준이 될곳을 바꾼다.
    swap(&dataSet[first], &dataSet[right]);

    // 마지막으로 모든 연산이 끝나면 새로운 기준점을 반환
    return right;
}

// 퀵정렬을 수행하는 함수
void QuickSort(int dataSet[], int left, int right)
{
    if (left < right)
    {
        // Partition함수에 의해 반환된 새로운 기준점을 index라는 변수에 할당한다.
        int index = Partition(dataSet, left, right);

        // 재귀 호출
        // 할당 후, index변수 기준 왼쪽, 오른쪽을 나누어 다시 퀵정렬을 수행
        QuickSort(dataSet, left, index - 1);
        QuickSort(dataSet, index + 1, right);
    }
}

// 메인 함수
int main(void)
{
    int dataSet[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof dataSet / sizeof dataSet[0];
    int i = 0;

    QuickSort(dataSet, 0, length - 1);

    for (i = 0; i < length; i++)
    {
        printf("%d ", dataSet[i]);
    }
    printf("\n");
    return 0;
}