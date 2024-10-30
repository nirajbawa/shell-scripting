#include <stdio.h>
#include <stdlib.h>

// https://www.sanfoundry.com/c-program-round-robin-scheduling/

int main()
{
    int noOfp;
    printf("enter no of processes : ");
    scanf("%d", &noOfp);

    int *arr_time = (int *) calloc(noOfp, sizeof(noOfp));
    int *burst_time = (int *) calloc(noOfp, sizeof(noOfp));
    int *temp_burst_time = (int *) calloc(noOfp, sizeof(noOfp));
    int wait_time = 0;
    int ta_time = 0;
    int x = noOfp;

    printf("\nenter arrival time : \n");
    for (int i = 0; i < noOfp; i++)
    {
        printf("process %d : ", i);
        scanf("%d", &arr_time[i]);
    }

    printf("\nenter burst time : \n");
    for (int i = 0; i < noOfp; i++)
    {
        printf("process %d : ", i);
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    int time_slot;
    printf("\n\nEnter time slot : ");
    scanf("%d", &time_slot);


    int total = 0, counter = 0, i = 0;
    printf("\n\n processes \t burst time \t turnaround time \t waiting time\n");

    while(x!=0)
    {
        if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0)
        {
            total = total + temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        }
        else if(temp_burst_time[i]>0)
        {
            temp_burst_time[i] = temp_burst_time[i] - time_slot;
            total += time_slot;
        }
        if(temp_burst_time[i] == 0 && counter==1)
        {
            x--;
            printf("\np%d \t\t %d\t\t %d\t\t %d", i+1, burst_time[i], total-arr_time[i], total-arr_time[i]-burst_time[i]);

            wait_time = wait_time+total-arr_time[i]-burst_time[i];
            ta_time += total - arr_time[i];
            counter = 0;
        }

        if(i==noOfp-1)
        {
            i = 0;
        }
        else if(arr_time[i+1] <= total)
        {
            i++;
        }
        else{
            i=0;
        }
    }
    

    float avgwt = wait_time*1.0/noOfp;
    float avgt = ta_time*1.0/noOfp;

    printf("\n\nAverage waiting time : %f \n", avgwt);
    printf("\n\nAverage turnaround time : %f \n", avgt);
    

    return 0;
}