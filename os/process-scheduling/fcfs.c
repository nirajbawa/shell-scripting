#include <stdio.h>
#include <stdlib.h>

void inputArray(int *arr, int numOfp, char name[])
{
    printf("\nenter %s : \n", name);
    for (int i = 0; i < numOfp; i++)
    {
        printf("process %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void findWaitingTime(int *burstTime, int *waitingTime, int numOfp)
{
    waitingTime[0] = 0;
    for (int i = 0; i < numOfp; i++)
    {
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
    }
}

void findTurnaroundTime(int *burstTime, int *waitingTime, int *turnaroundTime,  int numOfp)
{
    for (int i = 0; i < numOfp; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
    
} 

float averageTimeCal(int *arr, int numOfp)
{
    float avg = 0;
    float total = 0;
    for (int i = 0; i < numOfp; i++)
    {
        total += arr[i];
    }  

    avg = total/numOfp;

    return avg;
}

void printArrays(int *burstTime, int *waitingTime, int *turnaroundTime,  int numOfp, float averageTurn, float averageWt)
{
    printf("\n\nprocesses \t burst time \t waiting time \t turnaround time \n");

    for (int i = 0; i < numOfp; i++)
    {
        printf("p%d ", i);
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
    printf("enter number of proccesses : ");
    scanf("%d", &numOfp);
    int *burstTime = (int *)calloc(numOfp, sizeof(int));
    inputArray(burstTime, numOfp, "Burst Time");
    int *waitingTime = (int *)calloc(numOfp, sizeof(int));
    int *turnaroundTime = (int *)calloc(numOfp, sizeof(int));

    findWaitingTime(burstTime, waitingTime, numOfp);
    findTurnaroundTime(burstTime, waitingTime, turnaroundTime, numOfp);
    float avegt = averageTimeCal(turnaroundTime, numOfp);
    float avegwt = averageTimeCal(waitingTime, numOfp);

    printArrays(burstTime, waitingTime, turnaroundTime, numOfp, avegt, avegwt);

    return 0;
}