// zero element > non-zero element
//    we create a sparse matrix which store only
//    non-zero elements and there index to save unwanted memory

#include <stdio.h>

int main()
{

    int arr[4][4] = {{0, 0, 1, 0},
                     {0, 2, 0, 0},
                     {0, 0, 3, 0},
                     {4, 0, 0, 0}};
    int m = 4;
    int n = 4;
    
    int zro = 0;
    int n_zro = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                zro++;
            }
            else
            {
                n_zro++;
            }
        }
    }

    if (n_zro >= zro)
    {
        printf("not a sparse matrix");
    }
    else
    {
        int spr[n_zro][3];
        int k = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != 0)
                {
                    spr[k][0] = i;
                    spr[k][1] = j;
                    spr[k][2] = arr[i][j];
                    k++;
                }
            }
        }

        for (int i = 0; i < n_zro; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", spr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
