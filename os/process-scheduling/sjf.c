#include <stdio.h>
#include <stdlib.h>

// https://www.sanfoundry.com/c-program-sjf-scheduling/

void findWaitingTime(int *burstTime, int *waitingTime, int numOfp)
{
    waitingTime[0] = 0;
    for (int i = 0; i < numOfp; i++)
    {
        for (int j = 0; j < i; j++)
        {
            waitingTime[i] = burstTime[j] + waitingTime[i];
        }
    }
}

void findTrunaroundTime(int *burstTime, int *waitingTime, int *turnaroundTime, int numOfp)
{
    for (int i = 0; i < numOfp; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

float averageTime(int *arr, int numOfp)
{
    float total = 0;
    float aveg = 0;
    for (int i = 0; i < numOfp; i++)
    {
        total += arr[i];
    }
    return total / numOfp;
}

void printArrays(int *process, int *burstTime, int *waitingTime, int *turnaroundTime, int numOfp, float averageTurn, float averageWt)
{
    printf("\n\nprocesses \t burst time \t waiting time \t turnaround time \n");

    for (int i = 0; i < numOfp; i++)
    {
        printf("p%d ", process[i]);
        printf("\t\t %d ", burstTime[i]);
        printf("\t\t %d ", waitingTime[i]);
        printf("\t\t %d ", turnaroundTime[i]);
        printf("\n");
    }

    printf("\n\n the average wating time is : %f", averageWt);
    printf("\n the average turnaround time is : %f\n\n", averageTurn);
}

int main()
{

    int numOfp;
    printf("\nenter number of processes : ");
    scanf("%d", &numOfp);
    int *burstTime = (int *)calloc(numOfp, sizeof(int));
    int *waitingTime = (int *)calloc(numOfp, sizeof(int));
    int *turnaroundTime = (int *)calloc(numOfp, sizeof(int));
    int *process = (int *)calloc(numOfp, sizeof(int));

    printf("\nenter the burst time : \n");
    for (int i = 0; i < numOfp; i++)
    {
        printf("process %d : ", i);
        scanf("%d", &burstTime[i]);
        process[i] = i + 1;
    }

    // sorting of processes and burst time
    for (int i = 0; i < numOfp; i++)
    {
        int pos = i;
        for (int j = i + 1; j < numOfp; j++)
        {
            if (burstTime[j] < burstTime[pos])
            {
                pos = j;
            }
        }
        int temp;
        temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;

        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    findWaitingTime(burstTime, waitingTime, numOfp);
    findTrunaroundTime(burstTime, waitingTime, turnaroundTime, numOfp);
    float avgt = averageTime(turnaroundTime, numOfp);
    float avgwt = averageTime(waitingTime, numOfp);

    printArrays(process, burstTime, waitingTime, turnaroundTime, numOfp, avgt, avgwt);

    return 0;
}