// 병합 정렬
// 원본 데이터 배열을 재귀적으로 반복하여 크기가 1인 배열로 만든다.
// 그 후  데이터를 다시 합치는 과정에서 정렬을 실시.
#include <stdio.h>
#define MAX_SIZE 8
int sorted[MAX_SIZE];

void merge(int data[], int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (data[i] <= data[j])
            sorted[k++] = data[i++];
        else
            sorted[k++] = data[j++];
    }

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
        mid = (left + right) / 2;
        merge_Sort(data, left, mid);
        merge_Sort(data, mid + 1, right);
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