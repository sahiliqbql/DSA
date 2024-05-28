#include <stdio.h>
int main()
{
    int arr[2][2] = {{1,2},{3,4}};

    printf("%p\n", &arr); // 0061FF10

    printf("%p\n", &arr[0]); // 0061FF10

    printf("%p\n", &arr[1]); // 0061FF10 + 8 = 0061FF18

    printf("%d", sizeof(arr[1])); // 8
}
