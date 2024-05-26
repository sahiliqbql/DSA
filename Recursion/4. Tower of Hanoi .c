// total moves = 2^n - 1

#include <stdio.h>

void TowerOfHanoi(int n, char from_Rod, char aux_Rod, char to_Rod)
{

    if (n == 1)
    {
        printf("%d : %c --> %c\n", n, from_Rod, to_Rod);  //Move
        return;
    }
    TowerOfHanoi(n - 1, from_Rod, to_Rod, aux_Rod);

    printf("%d : %c --> %c\n", n, from_Rod, to_Rod);   //Move

    TowerOfHanoi(n - 1, aux_Rod, from_Rod, to_Rod);
}

int main()
{
    int n;
    printf("enter disks num: ");
    scanf("%d",&n);
    TowerOfHanoi(n,'A', 'B', 'C');
    return 0;
}

// Time Complexity: O(2^n)
// Auxiliary Space: O(n)
