#include <stdio.h>
#include <stdlib.h>

// https://www.sanfoundry.com/c-program-priority-scheduling/

int findWaitingTime(int *burstTime, int *waitingTime, int noOfp)
{
    waitingTime[0] = 0;
    for (int i = 0; i < noOfp; i++)
    {
        for (int j = 0; j < i; j++)
        {
            waitingTime[i] = burstTime[j] + waitingTime[i];
        }
    }
}


int findTurnaroundTime(int *burstTime, int * waitingTime, int *turnaroundTime, int noOfp)
{
    for (int i = 0; i < noOfp; i++)
    {
        turnaroundTime[i] = burstTime[i]+waitingTime[i];
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


void printArrays(int *process, int *burstTime, int *waitingTime, int *turnaroundTime, int *priority, int numOfp, float averageTurn, float averageWt)
{
    printf("\n\nprocesses \t burst time \t priority \t waiting time \t turnaround time \n");

    for (int i = 0; i < numOfp; i++)
    {
        printf("p%d ", process[i]);
        printf("\t\t %d ", burstTime[i]);
         printf("\t\t %d ", priority[i]);
        printf("\t\t %d ", waitingTime[i]);
        printf("\t\t %d ", turnaroundTime[i]);

        printf("\n");
    }

    printf("\n\n the average wating time is : %f", averageWt);
    printf("\n the average turnaround time is : %f\n\n", averageTurn);
}


int main()
{
    int noOfp;
    printf("\nenter the number of process : ");
    scanf("%d", &noOfp);

    int *burstTime = (int *)calloc(noOfp, sizeof(int));
    int *turnaroundTime = (int *)calloc(noOfp, sizeof(int));
    int *waitingTime = (int *)calloc(noOfp, sizeof(int));
    int *process = (int *)calloc(noOfp, sizeof(int));
    int *priority = (int *)calloc(noOfp, sizeof(int));

    printf("\nenter burst time : \n\n");

    for (int i = 0; i < noOfp; i++)
    {
        printf("process %d : ", i);
        scanf("%d", &burstTime[i]);
        process[i] = i + 1;
    }

    printf("\nenter priority : \n\n");

    for (int i = 0; i < noOfp; i++)
    {
        printf("process %d : ", i);
        scanf("%d", &priority[i]);
    }

    // sorting processes

    for (int i = 0; i < noOfp; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < noOfp; j++)
        {
            if (priority[j] > priority[minInd])
            {
                minInd = j;
            }
        }

        int temp = priority[i];
        priority[i] = priority[minInd];
        priority[minInd] = temp;

        temp = process[i];
        process[i] = process[minInd];
        process[minInd] = temp;

        temp = burstTime[i];
        burstTime[i] = burstTime[minInd];
        burstTime[minInd] = temp;
    }


    findWaitingTime(burstTime, waitingTime, noOfp);
    findTurnaroundTime(burstTime, waitingTime, turnaroundTime, noOfp);
    float avgt = averageTime(turnaroundTime, noOfp);
    float avgwt = averageTime(waitingTime, noOfp);

    printArrays(process, burstTime, waitingTime, turnaroundTime, priority, noOfp, avgt, avgwt);



    return 0;
}