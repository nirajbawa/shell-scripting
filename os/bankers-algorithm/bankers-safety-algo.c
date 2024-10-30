#include <stdio.h>
#include <stdlib.h>

void inputArray(int **inA, int numOfp, int numOfr, char name[])
{
    printf("\n\nenter %s resources for each process : \n", name);

    for (int i = 0; i < numOfp; i++)
    {
        printf("process %d : ", i);

        for (int j = 0; j < numOfr; j++)
        {
            int temp;
            scanf("%d", &temp);
            inA[i][j] = temp;
        }
    }
}

void printArray(int **inA, int **inM, int *inAv, int **inN, int numOfp, int numOfr)
{
    printf("\n\n   Allocation    Max      Available     Need\n");

    printf("  ");
    for (int i = 0; i < numOfr; i++)
    {
        printf(" %c ", 65 + i);
    }

    printf("   ");
    for (int i = 0; i < numOfr; i++)
    {
        printf(" %c ", 65 + i);
    }

    printf("   ");
    for (int i = 0; i < numOfr; i++)
    {
        printf(" %c ", 65 + i);
    }

    printf("   ");
    for (int i = 0; i < numOfr; i++)
    {
        printf(" %c ", 65 + i);
    }

    printf("\n");

    for (int i = 0; i < numOfp; i++)
    {
        printf("p%d", i);
        for (int j = 0; j < numOfr; j++)
        {
            printf(" %d ", inA[i][j]);
        }

        printf(" | ");
        for (int j = 0; j < numOfr; j++)
        {
            printf(" %d ", inM[i][j]);
        }

        printf(" | ");
        if (i == 0)
        {
            for (int j = 0; j < numOfr; j++)
            {
                printf(" %d ", inAv[j]);
            }
        }
        else
        {
            for (int j = 0; j < numOfr; j++)
            {
                printf(" - ");
            }
        }

        printf(" | ");
        for (int j = 0; j < numOfr; j++)
        {
            printf(" %d ", inN[i][j]);
        }
        printf("\n");
    }
}

void findNeed(int **need, int **allocation, int **max, int numOfp, int numOfr)
{
    for (int i = 0; i < numOfp; i++)
    {
        for (int j = 0; j < numOfr; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void findSafeSequence(int **inA, int **inM, int *inAv, int **inN, int *execute, int numOfp, int numOfr)
{
    int *f = (int *)malloc(numOfp * sizeof(int));
    for (int k = 0; k < numOfp; k++)
    {
        f[k] = 0;
    }
    int ind = 0;
    int i, j;
    for (int k = 0; k < numOfp; k++)
    {
        for (i = 0; i < numOfp; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < numOfr; j++)
                {
                    if (inN[i][j] > inAv[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    execute[ind++] = i;
                    for (int j = 0; j < numOfr; j++)
                    {
                        inAv[j] += inA[i][j];
                    }
                    f[i] = 1;

                    printf("\nAfter P%d -> Available: ", i);
                    for (int i = 0; i < numOfr; i++)
                    {
                        printf("%d ", inAv[i]);
                    }
                    printf("\n");
                    
                }
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < numOfp; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("\n\nThe given sequence is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("\n\nFollowing is the SAFE sequence\n\n");
        for (int i = 0; i < numOfp; i++)
        {
            printf(" p%d ", execute[i]);
            if ((i + 1) != numOfp)
            {
                printf("->");
            }
        }
    }
}

int main()
{
    int numOfp;
    printf("enter number of process : ");
    scanf("%d", &numOfp);

    int numOfr;
    printf("enter number of resources : ");
    scanf("%d", &numOfr);

    int *execute = (int *)malloc(numOfp * sizeof(int));
    int front = 0;
    int rear = 0;
    int size = numOfp;

    int **allocation = (int **)malloc(numOfp * sizeof(int *));

    for (int i = 0; i < numOfp; i++)
    {
        allocation[i] = (int *)malloc(numOfr * sizeof(int));
    }

    int **max = (int **)malloc(numOfp * sizeof(int *));

    for (int i = 0; i < numOfp; i++)
    {
        max[i] = (int *)malloc(numOfr * sizeof(int));
    }

    int *available = (int *)malloc(numOfp * sizeof(int *));


    int **need = (int **)malloc(numOfp * sizeof(int *));

    for (int i = 0; i < numOfp; i++)
    {
        need[i] = (int *)malloc(numOfr * sizeof(int));
    }



    inputArray(allocation, numOfp, numOfr, "Allocation");
    inputArray(max, numOfp, numOfr, "Max");

    printf("\n\nenter Available resources for each process : \n");

    for (int i = 0; i < numOfr; i++)
    {
        int temp;
        scanf("%d", &temp);
        available[i] = temp;
    }

    findNeed(need, allocation, max, numOfp, numOfr);
    printArray(allocation, max, available, need, numOfp, numOfr);
    findSafeSequence(allocation, max, available, need, execute, numOfp, numOfr);

    return 0;
}
