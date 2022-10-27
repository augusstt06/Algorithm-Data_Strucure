// 병합 정렬
// 원본 데이터 배열을 재귀적으로 반복하여 크기가 1인 배열로 만든다.
// 그 후  데이터를 다시 합치는 과정에서 정렬을 실시.
#include <stdio.h>
#define MAX_SIZE 8
int sorted[MAX_SIZE];

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(int data[], int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    /* 분할 정렬된 list의 병합 */
    while (i <= mid && j <= right)
    {
        if (data[i] <= data[j])
            sorted[k++] = data[i++];
        else
            sorted[k++] = data[j++];
    }
    // 남아 있는 값들을 일괄 복사
    if (i > mid)
    {
        for (int m = j; m <= right; m++)
            sorted[k++] = data[m];
    }
    else
    {
        for (int m = i; m <= mid; m++)
        {
            sorted[k++] = data[m];
        }
    }
    // 배열 sorted[](임시 배열)의 리스트를 배열 data[]로 재복사
    for (int n = left; n <= right; n++)
    {
        data[n] = sorted[n];
    }
}

void merge_Sort(int data[], int left, int right)
{
    int mid;
    if (left < right)
    {
        // 중간 지점 선언/할당
        mid = (left + right) / 2;
        // 중간 지점 기준 앞 쪽
        merge_Sort(data, left, mid);
        // 중간 지점 기준 뒷 쪽
        merge_Sort(data, mid + 1, right);
        // 2번의 merge_Sort로 인하여 정렬된 2개의 배열을 병합
        merge(data, left, mid, right);
    }
}

int main()
{
    int i;
    int n = MAX_SIZE;
    int data[] = {21, 10, 12, 20, 25, 13, 15, 22};

    merge_Sort(data, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        printf("%d\n", data[i]);
    }
}