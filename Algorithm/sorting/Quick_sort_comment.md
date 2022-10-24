# 퀵 정렬

## 핵심 아이디어

> 특정 값(피벗 값)을 기준으로 큰 숫자, 작은 숫자를 찾아 정렬한다.

- 기본적인 알고리즘 진행방식은 파이썬의 퀵 정렬과 동일하다.

## 소스 코드

```
#include <stdio.h>

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int Partition(int dataSet[], int left, int right)
{
    int first = left;
    int pivot = dataSet[first];
    ++left;

    while (left <= right)
    {
        while (dataSet[left] <= pivot && left < right)
        {
            ++left;
        }
        while (dataSet[right] >= pivot && left <= right)
        {
            --right;
        }

        if (left < right)
        {
            swap(&dataSet[left], &dataSet[right]);
        }
        else
        {
            break;
        }
    }
    swap(&dataSet[first], &dataSet[right]);

    return right;
}

void QuickSort(int dataSet[], int left, int right)
{
    if (left < right)
    {
        int index = Partition(dataSet, left, right);

        QuickSort(dataSet, left, index - 1);
        QuickSort(dataSet, index + 1, right);
    }
}

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
```

## 코드 설명

소스코드를 보면 크게 4개의 함수로 분리되어 있다.
차례대로 함수의 기능을 살펴보며 알고리즘을 이해해보자.

> 전에 프로그래밍을 할 때는 신경쓰지 않았지만, 함수는 하나의 기능만을 수행해야 한다.

### **_1. swap 함수_**

```
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

```

함수의 이름 그대로 **매개변수로 받은 A, B의 값을 서로 바꿔주는 역할**을 하는 함수이다.
temp라는 변수를 사용하여 A, B의 포인터(주소)값을 서로 바꿔준다.

### **_2. Partition 함수_**

```
int Partition(int dataSet[], int left, int right)
{
    int first = left;
    int pivot = dataSet[first];
    ++left;

    while (left <= right)
    {
        while (dataSet[left] <= pivot && left < right)
        {
            ++left;
        }
        while (dataSet[right] >= pivot && left <= right)
        {
            --right;
        }

        if (left < right)
        {
            swap(&dataSet[left], &dataSet[right]);
        }
        else
        {
            break;
        }
    }
    swap(&dataSet[first], &dataSet[right]);

    return right;
}
```

본격적인 알고리즘의 구현부분이다.
퀵정렬의 알고리즘은 피벗값(기준값)기준으로하여 주어진 배열의 왼쪽, 오른쪽부터 탐색을 수행한다.

이 함수는 **매개변수로 받은 dataSet의 범위를 탐색하는 역할**을 하는 함수이다.

```
int first = left;
int pivot = dataSet[first];
++left;
```

가장 먼저 새롭게 매개변수로 받아온 배열의 **피벗값을 설정**한다.
left의 값을 피벗값으로 설정했으니 배열의 **left 인덱스의 값은 탐색할 필요가 없다 (기준점이므로).**
따라서 left값에 1을 더해준다.

첫번째 반복문부터 살펴 보도록 하자.

```
while (left <= right)
    {
        while (dataSet[left] <= pivot && left < right)
        {
            ++left;
        }
        while (dataSet[right] >= pivot && left <= right)
        {
            --right;
        }

        if (left < right)
        {
            swap(&dataSet[left], &dataSet[right]);
        }
        else
        {
            break;
        }
    }
```

기본적으로 이 반복문은 left값이 right값과 만날때까지 반복한다.

내부의 첫번째 while문은 우리가 위에서 정한 피벗값 기준, 매개변수로 받은 배열의 **왼쪽**을 탐색하는 부분이다.
피벗값보다 현재의 left값이 작고, left값이 right값보다 작다면 left를 1씩 증가시키며 탐색한다.

> 피벗값보다 현재의 left값이 크다면 피벗값과 left값의 자리를 바꿔서 정렬해야 하기 때문에 반복문을 탈출하여 밑의 조건문으로 들어간다.

두번째 while문은 우리가 위에서 정한 피벗값 기준, 매개변수로 받은 배열의 **오른쪽**을 탐색하는 부분이다.
첫번째 while문의 방식과 동일하고, 탐색 범위만 다르다.(right)

두개의 while문을 탈출하면 (피벗 값보다 크거나, 작은값을 찾으면) 조건문으로 들어간다.

```
if (left < right)
{
    swap(&dataSet[left], &dataSet[right]);
}
else
{
    break;
}

```

이 조건문은 left, right값이 차례대로 피벗값보다 크거나, 작다면 두 값의 위치를 바꿔준다.

위에서 작성한 swap함수를 호출하여 시행한다.
&연산자를 이용하여 left, right값의 주소를 매개변수로 넘겨주면, swap함수 내에서 해당 두 매개변수의 주소값을 바꾸어 리턴한다.

그 후, 다시 내부의 첫번째 while문으로 돌아가 동일한 연산을 else문의 조건이 충족되거나, 최상위 while문의 조건이 false 일때까지 수행한다.

만약, left값이 right값과 같거나 커졌다면, 두 지점이 만난것이므로 그대로 조건문, 최상위 while문을 탈출한다.

```
swap(&dataSet[first], &dataSet[right]);

    return right;
```

최종적으로 최상위 while문을 모두 수행하고 탈출하고 나면 즉, left 값이 right값보다 커진다면, 현재의 피벗값과 right의 값을 바꾼다.

left 값이 right값보다 커진다는 의미는 더이상 탐색하는 범위내에서는 현재 피벗값으로 정렬할수 있는 요소는 없다는 뜻이기 때문에, 피벗 값을 바꾸어 해당 값 (새로운 피벗값)을 리턴한다.

### **_3. QuickSort 함수_**

```
void QuickSort(int dataSet[], int left, int right)
{
    if (left < right)
    {
        int index = Partition(dataSet, left, right);

        QuickSort(dataSet, left, index - 1);
        QuickSort(dataSet, index + 1, right);
    }
}
```

함수 이름 그대로 **퀵 정렬을 실제로 시행하는 역할**을 하는 함수이다.
위에서 작성한 Partition함수는 배열의 피벗값을 정해주는 역할을 하므로 해당 함수를 호출하여 피벗값을 index라는 변수에 할당한다.

피벗값을 정한 후, 피벗값 기준 왼쪽 (left ~ index-1)과 오른쪽 (index + 1 ~ right) 두 부분으로 나누어 재귀적으로 QuickSort함수를 호출하여 시행한다.

재귀적으로 QuickSort를 시행한단뜻은 주어진 배열을 계속해서 피벗 값을 기준으로 탐색하여 정렬한다는 의미이다.

### **_4. Main 함수_**

```
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
```

마지막으로 실제로 퀵정렬을 실시하기위해 QuickSort 함수를 호출하여 실시하는 메인함수이다.

dataSet을 정의하고, left, right값을 정의하여 QuickSort 함수의 매개변수로 넘겨준다.

퀵 정렬을 수행하고 난 뒤, 정렬된 배열을 출력하여 잘 정렬이 되었는지 확인한다.
