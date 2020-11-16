#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef float type;
type cmp_func1(type a, type b)
{
    return (a-b>0);
}
type cmp_func2(type a, type b)
{
    return (b-a>0);
}
void sort(type* array, unsigned array_size, type (*cmp_func)(type,type))
{
    for (unsigned i = 0; i < array_size; i++)
        for (unsigned j = 0; j < i; j++)
            if (cmp_func(array[i], array [j]))
            {
                type tmp = array [i];
                array [i] = array [j];
                array [j] = tmp;
            }
}

int main()
{
    int arr[7] = {5, 2, 6, 8, 5, 3, 1};
    sort(arr, 7, cmp_func1);
    for (int i = 0; i < 7; i++)
        printf("%d\n", arr[i]);
    sort(arr, 7, cmp_func2);
    for (int i = 0; i < 7; i++)
        printf("%d\n", arr[i]);
    return 0;
}

